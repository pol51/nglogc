

#include "log.h"

#include "timestamp.h"

#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>


extern int
getLoggerCount(
      void
      );


static void
check_logger(
      void
      );

static void
check_logFormat(
      void
      );

static void
check_traceLog(
      void
      );


int main(int argc, char *argv[])
{
   printf("\n starting unittets...\n");
   printf("\n TESTS OF NGLOGC\n\n");

   printf("  running check_logger\n");
   check_logger();
   printf("  all tests passed\n\n");

   printf("  running check_logFormat\n");
   check_logFormat();
   printf("  all tests passed\n\n");

   printf("  running check_traceLog\n");
   check_traceLog();
   printf("  all tests passed\n\n");
   return 0;
}

static void
check_logger(
      void
      )
{
   /* tests of logc_registerLogger good case */
   assert(logc_registerLogger(0x0011, STDOUT, LOG_FINE) == LOG_ERR_OK);
   assert(getLoggerCount() == 1);
   assert(logc_registerLogger(0x0012, STDOUT, LOG_FINE) == LOG_ERR_OK);
   assert(getLoggerCount() == 2);
   assert(logc_registerLogger(0x0013, STDOUT, LOG_FINE) == LOG_ERR_OK);
   assert(getLoggerCount() == 3);
   /* tests of logc_registerLogger bad case */
   assert(logc_registerLogger(0x0013, 7, LOG_FINE) == LOG_ERR_PARAM);
   assert(logc_registerLogger(0x0013, STDOUT, 7) == LOG_ERR_PARAM);

   /* tests of logc_changeLogLevel good case */
   assert(logc_changeLogLevel(0x0011, LOG_BASIC) == LOG_ERR_OK);
   assert(logc_changeLogLevel(0x0012, LOG_BASIC) == LOG_ERR_OK);
   assert(logc_changeLogLevel(0x0013, LOG_BASIC) == LOG_ERR_OK);
   /* tests of logc_changeLogLevel bad case */
   assert(logc_changeLogLevel(0x0014, LOG_BASIC) == LOG_ERR_NOT_FOUND);
   assert(logc_changeLogLevel(0x0011, 7) == LOG_ERR_PARAM);

   /* tests of logc_setLogFormat good case */
   assert(logc_setLogFormat(0x0011, ERR_TAG, CLEAN) == LOG_ERR_OK);
   assert(logc_setLogFormat(0x0012, TIMESTAMP_ERR_TAG, TIMESTAMP) == LOG_ERR_OK);
   assert(logc_setLogFormat(0x0013, ERR, CLEAN) == LOG_ERR_OK);
   /* tests of logc_setLogFormat bad case */
   assert(logc_setLogFormat(0x0014, ERR_TAG, CLEAN) == LOG_ERR_NOT_FOUND);
   assert(logc_setLogFormat(0x0012, 7, TIMESTAMP) == LOG_ERR_PARAM);
   assert(logc_setLogFormat(0x0013, ERR_TAG, 7) == LOG_ERR_PARAM);

   /* tests of logc_removeLogger bad case */
   assert(logc_removeLogger(0x0014) == LOG_ERR_NOT_FOUND);
   assert(getLoggerCount() == 3);
   /* tests of logc_removeLogger good case */
   assert(logc_removeLogger(0x0011) == LOG_ERR_OK);
   assert(getLoggerCount() == 2);
   assert(logc_removeLogger(0x0012) == LOG_ERR_OK);
   assert(getLoggerCount() == 1);
   assert(logc_removeLogger(0x0013) == LOG_ERR_OK);
   assert(getLoggerCount() == 0);

}


static void
check_logFormat(
      void
      )
{
   FILE* fd = NULL;
   char checkBuf[256] = {0};
   char tmpBuf[256] = {0};
   char timest[25] = {0};
   int check = 0;

   /* register logger */
   assert(logc_registerLogger(0x0011, FILEOUT, LOG_BASIC) == LOG_ERR_OK);
   assert(getLoggerCount() == 1);
   /* set filename to log in */
   assert(logc_setLogfile(0x0011, "unittests.log") == LOG_ERR_OK);

   /* tests of error format */
   assert(logc_setLogFormat(0x0011, ERR, CLEAN) == LOG_ERR_OK);
   assert(logc_logError(0x0011, 0x00000001, "error message") == LOG_ERR_OK);
   assert(logc_setLogFormat(0x0011, ERR_TAG, CLEAN) == LOG_ERR_OK);
   assert(logc_logError(0x0011, 0x00000001, "error message") == LOG_ERR_OK);
   assert(logc_setLogFormat(0x0011, ERR_TAG_TIMESTAMP, CLEAN) == LOG_ERR_OK);
   assert(logc_logError(0x0011, 0x00000001, "error message") == LOG_ERR_OK);
   assert(logc_setLogFormat(0x0011, ERR_TIMESTAMP_TAG, CLEAN) == LOG_ERR_OK);
   assert(logc_logError(0x0011, 0x00000001, "error message") == LOG_ERR_OK);
   assert(logc_setLogFormat(0x0011, TIMESTAMP_ERR_TAG, CLEAN) == LOG_ERR_OK);
   assert(logc_logError(0x0011, 0x00000001, "error message") == LOG_ERR_OK);
   /* tests of log format */
   assert(logc_setLogFormat(0x0011, ERR, CLEAN) == LOG_ERR_OK);
   assert(logc_log(0x0011, LOG_BASIC, "log message") == LOG_ERR_OK);
   assert(logc_setLogFormat(0x0011, ERR, TIMESTAMP) == LOG_ERR_OK);
   assert(logc_log(0x0011, LOG_BASIC, "log message") == LOG_ERR_OK);
   /* remove the logger to close the file */
   assert(logc_removeLogger(0x0011) == LOG_ERR_OK);
   assert(getLoggerCount() == 0);

   /* get the timestamp and replace the seconds to compare the output */
   addTimestamp(timest);
   memset(timest+17, 'X', 2);
   timest[24] = '\0';

   /* open file to check the logging output */
   fd = fopen("unittests.log", "r");
   if (fd == NULL) {
      printf("error couldn't open file\n");
   }
   /* check the output of the loggers */
   assert(fgets(checkBuf, sizeof(checkBuf), fd) != NULL);
   check = strncmp(checkBuf, "ERR : error message\n", sizeof(checkBuf));
   assert(check == 0);

   assert(fgets(checkBuf, sizeof(checkBuf), fd) != NULL);
   check = strncmp(checkBuf, "ERR 0x00000001 : error message\n", sizeof(checkBuf));
   assert(check == 0);

   assert(fgets(checkBuf, sizeof(checkBuf), fd) != NULL);
   memset(checkBuf+32, 'X', 2);
   sprintf(tmpBuf, "ERR 0x00000001 %s : error message\n", timest);
   check = strncmp(checkBuf, tmpBuf, sizeof(checkBuf));
   assert(check == 0);

   assert(fgets(checkBuf, sizeof(checkBuf), fd) != NULL);
   memset(checkBuf+21, 'X', 2);
   sprintf(tmpBuf, "ERR %s 0x00000001 : error message\n", timest);
   check = strncmp(checkBuf, tmpBuf, sizeof(checkBuf));
   assert(check == 0);

   assert(fgets(checkBuf, sizeof(checkBuf), fd) != NULL);
   memset(checkBuf+17, 'X', 2);
   sprintf(tmpBuf, "%s ERR 0x00000001 : error message\n", timest);
   check = strncmp(checkBuf, tmpBuf, sizeof(checkBuf));
   assert(check == 0);

   if (fd) {
      fclose(fd);
   }

   remove("unittests.log");
}


static void
check_traceLog(
      void
      )
{
   FILE* fd = NULL;
   char checkBuf[256] = {0};
   int check = 0;

   /* register logger */
   assert(logc_registerLogger(0x0011, FILEOUT, LOG_FINEST) == LOG_ERR_OK);
   /* set filename to log in */
   assert(logc_setLogfile(0x0011, "unittests.log") == LOG_ERR_OK);

   /* test trace logging */
   assert(logc_logEnter(0x0011, "check_traceLog") == LOG_ERR_OK);
   assert(logc_logLeave(0x0011, "check_traceLog") == LOG_ERR_OK);
   /* remove the logger to close the file */
   assert(logc_removeLogger(0x0011) == LOG_ERR_OK);

   /* open file to check the logging output */
   fd = fopen("unittests.log", "r");
   if (fd == NULL) {
      printf("error couldn't open file\n");
   }
   /* check the output of the loggers */
   assert(fgets(checkBuf, sizeof(checkBuf), fd) != NULL);
   check = strncmp(checkBuf, "Enter > check_traceLog\n", sizeof(checkBuf));
   assert(check == 0);

   assert(fgets(checkBuf, sizeof(checkBuf), fd) != NULL);
   check = strncmp(checkBuf, "Leave < check_traceLog\n", sizeof(checkBuf));
   assert(check == 0);

   if (fd) {
      fclose(fd);
   }

   remove("unittests.log");
}



