

#include "log.h"

#include <stdio.h>
#include <assert.h>
#include <unistd.h>


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


int main(int argc, char *argv[])
{
   //logc_error_t err = LOG_ERR_OK;

   printf("\n starting unittets...\n");

   printf("\n TESTS OF LIBNGLOGC\n\n");

   printf("  running check_logger\n");
   check_logger();
   printf("  all tests passed\n");

   printf("  running check_logFormat\n");
   check_logFormat();
   printf("  all tests passed\n");
#if 0
   logc_registerLogger(0x0012, STDOUT, LOG_WARNING);

   err = logc_changeLogLevel(0x0012, LOG_BASIC);

   err = logc_logError(0x0012, 1, "foobar ich bin ein error");
   printf("logError: %08x\n", err);

   err = logc_logEnter(0x0013, "main()\n");
   err = logc_logLeave(0x0013, "main()\n");
   printf("  all tests passed\n");

   check_logger();
   printf("\n");
#endif

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
   assert(logc_registerLogger(0x0011, STDOUT, LOG_BASIC) == LOG_ERR_OK);
   assert(getLoggerCount() == 1);

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



   assert(logc_removeLogger(0x0011) == LOG_ERR_OK);
   assert(getLoggerCount() == 0);
}




