
/******************************************************************************
 *
 * nglogc - Flexible C Logging API
 *
 * Author:        Dennis Krzyzaniak
 * E-mail:        ebrosius@netgarage.org
 * WWW:           http://www.netgarage.org
 * Copyright (C): 2010 by Dennis Krzyzaniak
 *
 * This file is part of nglogc.
 *
 * nglogc is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * nglogc is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser Public License for more details.
 *
 * You should have received a copy of the GNU Lesser Public License
 * along with nglogc.  If not, see <http://www.gnu.org/licenses/>.
 *
 *****************************************************************************/

/* =========== INCLUDES ==================================================== */

#include "log.h"
#include "ringbuffer.h"

#include "timestamp.h"

#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>

/* =========== MODULE CONFIGURATION ======================================== */

//#define LOGC_ENABLE_LOW_LEVEL 1

/* =========== DEFINES ===================================================== */

/* test log file to compare the logger output */
#define UNITTESTS_LOGFILE   "unittests.log"

/* helper for number of array elements */
#define ARRAY_COUNT(x)  sizeof(x)/sizeof(x[0])

/* =========== DATA TYPES ================================================== */
/* =========== GLOBALS ===================================================== */
/* =========== PRIVATE PROTOTYPES ========================================== */

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

static void
check_errLogging(
      void
      );

static void
check_logLogging(
      void
      );

static void
check_arrayLogging(
      void
      );

static void
check_ringBuffer(
      void
      );

static void
check_ringBufferLogging(
      void
      );

/* =========== PUBLIC FUNCTIONS ============================================ */

int main(int argc, char *argv[])
{
   printf("\n starting unittests...\n");
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

   printf("  running check_errLogging\n");
   check_errLogging();
   printf("  all tests passed\n\n");

   printf("  running check_logLogging\n");
   check_logLogging();
   printf("  all tests passed\n\n");

   printf("  running check_arrayLogging\n");
   check_arrayLogging();
   printf("  all tests passed\n\n");

   printf("  running check_ringBuffer\n");
   check_ringBuffer();
   printf("  all tests passed\n\n");

   printf("  running check_ringBufferLogging\n");
   check_ringBufferLogging();
   printf("  all tests passed\n\n");

   return 0;
}

/* =========== PRIVATE FUNCTIONS =========================================== */

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

   const char* teststring = "foobar";

   /* in case of a failed unittest the logfile is not erased and further
    * runs will fail */
   remove(UNITTESTS_LOGFILE);

   /* register logger */
   assert(logc_registerLogger(0x0011, FILEOUT, LOG_BASIC) == LOG_ERR_OK);
   assert(getLoggerCount() == 1);
   /* set filename to log in */
   assert(logc_setLogfile(0x0011, UNITTESTS_LOGFILE) == LOG_ERR_OK);

   /* tests of error format */
   assert(logc_setLogFormat(0x0011, ERR, CLEAN) == LOG_ERR_OK);
   assert(logc_logErrorBasic(0x0011, 0x00000001, "error message %s",
            teststring) == LOG_ERR_OK);
   assert(logc_setLogFormat(0x0011, ERR_TAG, CLEAN) == LOG_ERR_OK);
   assert(logc_logErrorBasic(0x0011, 0x00000001, "error message %s",
            teststring) == LOG_ERR_OK);
   assert(logc_setLogFormat(0x0011, ERR_TAG_TIMESTAMP, CLEAN) == LOG_ERR_OK);
   assert(logc_logErrorBasic(0x0011, 0x00000001, "error message %s",
            teststring) == LOG_ERR_OK);
   assert(logc_setLogFormat(0x0011, ERR_TIMESTAMP_TAG, CLEAN) == LOG_ERR_OK);
   assert(logc_logErrorBasic(0x0011, 0x00000001, "error message %s",
            teststring) == LOG_ERR_OK);
   assert(logc_setLogFormat(0x0011, TIMESTAMP_ERR_TAG, CLEAN) == LOG_ERR_OK);
   assert(logc_logErrorBasic(0x0011, 0x00000001, "error message %s",
            teststring) == LOG_ERR_OK);
   /* tests of log format */
   assert(logc_setLogFormat(0x0011, ERR, CLEAN) == LOG_ERR_OK);
   assert(logc_log(0x0011, LOG_BASIC, "log message %s",
            teststring) == LOG_ERR_OK);
   assert(logc_setLogFormat(0x0011, ERR, TIMESTAMP) == LOG_ERR_OK);
   assert(logc_log(0x0011, LOG_BASIC, "log message %s", teststring) == LOG_ERR_OK);
   /* remove the logger to close the file */
   assert(logc_removeLogger(0x0011) == LOG_ERR_OK);
   assert(getLoggerCount() == 0);

   /* get the timestamp and replace the seconds to compare the output */
   addTimestamp(timest);
   memset(timest+17, 'X', 2);
   timest[24] = '\0';

   /* open file to check the logging output */
   fd = fopen(UNITTESTS_LOGFILE, "r");
   if (fd == NULL) {
      printf("error couldn't open file\n");
   }
   /* check the output of the loggers */
   assert(fgets(checkBuf, sizeof(checkBuf), fd) != NULL);
   check = strncmp(checkBuf, "ERR : error message foobar\n", sizeof(checkBuf));
   assert(check == 0);

   assert(fgets(checkBuf, sizeof(checkBuf), fd) != NULL);
   check = strncmp(checkBuf, "ERR 0x00000001 : error message foobar\n", sizeof(checkBuf));
   assert(check == 0);

   assert(fgets(checkBuf, sizeof(checkBuf), fd) != NULL);
   memset(checkBuf+32, 'X', 2);
   sprintf(tmpBuf, "ERR 0x00000001 %s : error message %s\n", timest, teststring);
   check = strncmp(checkBuf, tmpBuf, sizeof(checkBuf));
   assert(check == 0);

   assert(fgets(checkBuf, sizeof(checkBuf), fd) != NULL);
   memset(checkBuf+21, 'X', 2);
   sprintf(tmpBuf, "ERR %s 0x00000001 : error message %s\n", timest, teststring);
   check = strncmp(checkBuf, tmpBuf, sizeof(checkBuf));
   assert(check == 0);

   assert(fgets(checkBuf, sizeof(checkBuf), fd) != NULL);
   memset(checkBuf+17, 'X', 2);
   sprintf(tmpBuf, "%s ERR 0x00000001 : error message %s\n", timest, teststring);
   check = strncmp(checkBuf, tmpBuf, sizeof(checkBuf));
   assert(check == 0);

   assert(fgets(checkBuf, sizeof(checkBuf), fd) != NULL);
   check = strncmp(checkBuf, "log message foobar\n", sizeof(checkBuf));
   assert(check == 0);

   assert(fgets(checkBuf, sizeof(checkBuf), fd) != NULL);
   memset(checkBuf+17, 'X', 2);
   sprintf(tmpBuf, "%s : log message %s\n", timest, teststring);
   check = strncmp(checkBuf, tmpBuf, sizeof(checkBuf));
   assert(check == 0);

   if (fd) {
      fclose(fd);
   }

   remove(UNITTESTS_LOGFILE);
}


static void
check_traceLog(
      void
      )
{
   FILE* fd = NULL;
   char checkBuf[256] = {0};
   int check = 0;

   /* in case of a failed unittest the logfile is not erased and further
    * runs will fail */
   remove(UNITTESTS_LOGFILE);

   /* register logger */
   assert(logc_registerLogger(0x0011, FILEOUT, LOG_FINEST) == LOG_ERR_OK);
   /* set filename to log in */
   assert(logc_setLogfile(0x0011, UNITTESTS_LOGFILE) == LOG_ERR_OK);

   /* test trace logging */
   assert(logc_logEnter(0x0011, "check_traceLog") == LOG_ERR_OK);
   assert(logc_logLeave(0x0011, "check_traceLog") == LOG_ERR_OK);
   /* remove the logger to close the file */
   assert(logc_removeLogger(0x0011) == LOG_ERR_OK);

   /* open file to check the logging output */
   fd = fopen(UNITTESTS_LOGFILE, "r");
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

   remove(UNITTESTS_LOGFILE);
}

static void
check_errLogging(
      void
      )
{
   FILE* fd = NULL;
   char checkBuf[256] = {0};
   int check = 0;
   int i = 0;

   /* in case of a failed unittest the logfile is not erased and further
    * runs will fail */
   remove(UNITTESTS_LOGFILE);

   /* register logger */
   assert(logc_registerLogger(0x0011, FILEOUT, LOG_FINEST) == LOG_ERR_OK);
   /* set filename to log in */
   assert(logc_setLogfile(0x0011, UNITTESTS_LOGFILE) == LOG_ERR_OK);
   /* set log format */
   assert(logc_setLogFormat(0x0011, ERR, CLEAN) == LOG_ERR_OK);

   /* test error logging */
   assert(logc_logError(0x0011, LOG_FINEST, 0x00000001,
            "error message") == LOG_ERR_OK);
   assert(logc_logErrorBasic(0x0011, 0x00000001,
            "error message") == LOG_ERR_OK);
   assert(logc_logErrorWarning(0x0011, 0x00000001,
            "error message") == LOG_ERR_OK);
   assert(logc_logErrorInfo(0x0011, 0x00000001,
            "error message") == LOG_ERR_OK);
   assert(logc_logErrorFine(0x0011, 0x00000001,
            "error message") == LOG_ERR_OK);
   assert(logc_logErrorFinest(0x0011, 0x00000001,
            "error message") == LOG_ERR_OK);
   /* remove the logger to close the file */
   assert(logc_removeLogger(0x0011) == LOG_ERR_OK);

   /* open file to check the logging output */
   fd = fopen(UNITTESTS_LOGFILE, "r");
   if (fd == NULL) {
      printf("error couldn't open file\n");
   }

   /* check the output of the loggers */
   for (i=0; i<6; i++) {
      assert(fgets(checkBuf, sizeof(checkBuf), fd) != NULL);
      check = strncmp(checkBuf, "ERR : error message\n", sizeof(checkBuf));
      assert(check == 0);
   }

   if (fd) {
      fclose(fd);
   }

   remove(UNITTESTS_LOGFILE);
}

static void
check_logLogging(
      void
      )
{
   FILE* fd = NULL;
   char checkBuf[256] = {0};
   int check = 0;
   int i = 0;

   /* in case of a failed unittest the logfile is not erased and further
    * runs will fail */
   remove(UNITTESTS_LOGFILE);

   /* register logger */
   assert(logc_registerLogger(0x0011, FILEOUT, LOG_FINEST) == LOG_ERR_OK);
   /* set filename to log in */
   assert(logc_setLogfile(0x0011, UNITTESTS_LOGFILE) == LOG_ERR_OK);
   /* set log format */
   assert(logc_setLogFormat(0x0011, ERR, CLEAN) == LOG_ERR_OK);

   /* test error logging */
   assert(logc_log(0x0011, LOG_FINEST, "log message") == LOG_ERR_OK);
   assert(logc_logBasic(0x0011, "log message") == LOG_ERR_OK);
   assert(logc_logWarning(0x0011, "log message") == LOG_ERR_OK);
   assert(logc_logInfo(0x0011, "log message") == LOG_ERR_OK);
   assert(logc_logFine(0x0011, "log message") == LOG_ERR_OK);
   assert(logc_logFinest(0x0011, "log message") == LOG_ERR_OK);
   /* remove the logger to close the file */
   assert(logc_removeLogger(0x0011) == LOG_ERR_OK);

   /* open file to check the logging output */
   fd = fopen(UNITTESTS_LOGFILE, "r");
   if (fd == NULL) {
      printf("error couldn't open file\n");
   }

   /* check the output of the loggers */
   for (i=0; i<6; i++) {
      assert(fgets(checkBuf, sizeof(checkBuf), fd) != NULL);
      check = strncmp(checkBuf, "log message\n", sizeof(checkBuf));
      assert(check == 0);
   }

   if (fd) {
      fclose(fd);
   }

   remove(UNITTESTS_LOGFILE);
}


static void
check_arrayLogging(
      void
      )
{
   FILE* fd = NULL;
   char checkBuf[256] = {0};
   char tmpBuf[256] = {0};
   char timest[25] = {0};
   uint8_t array[10] = {0};
   int check = 0;
   int len = 10;
   int i = 0;

   /* fill the array */
   for (i=0; i<10; i++) {
      array[i] = 65 + i;
   }

   /* in case of a failed unittest the logfile is not erased and further
    * runs will fail */
   remove(UNITTESTS_LOGFILE);

   /* register logger */
   assert(logc_registerLogger(0x0011, FILEOUT, LOG_FINEST) == LOG_ERR_OK);
   /* set filename to log in */
   assert(logc_setLogfile(0x0011, UNITTESTS_LOGFILE) == LOG_ERR_OK);
   /* set log format */
   assert(logc_setLogFormat(0x0011, ERR, CLEAN) == LOG_ERR_OK);

   /* test array logging */
   assert(logc_logArray(0x0011, LOG_FINEST, "array", array, len) == LOG_ERR_OK);
   /* set log format */
   assert(logc_setLogFormat(0x0011, ERR, TIMESTAMP) == LOG_ERR_OK);
   assert(logc_logArray(0x0011, LOG_FINEST, "array", array, len) == LOG_ERR_OK);

   /* remove the logger to close the file */
   assert(logc_removeLogger(0x0011) == LOG_ERR_OK);

   /* get the timestamp and replace the seconds to compare the output */
   addTimestamp(timest);
   memset(timest+17, 'X', 2);
   timest[24] = '\0';

   /* open file to check the logging output */
   fd = fopen(UNITTESTS_LOGFILE, "r");
   if (fd == NULL) {
      printf("error couldn't open file\n");
   }

   /* check the output of logger */
   assert(fgets(checkBuf, sizeof(checkBuf), fd) != NULL);
   check = strncmp(checkBuf, "array : 4142434445464748494A\n", sizeof(checkBuf));
   assert(check == 0);

   assert(fgets(checkBuf, sizeof(checkBuf), fd) != NULL);
   memset(checkBuf+17, 'X', 2);
   sprintf(tmpBuf, "%s array : 4142434445464748494A\n", timest);
   check = strncmp(checkBuf, tmpBuf, sizeof(checkBuf));
   assert(check == 0);

   if (fd) {
      fclose(fd);
   }

   remove(UNITTESTS_LOGFILE);
}


static void
check_ringBuffer(
      void
      )
{
   logc_error_t err = LOG_ERR_OK;
   rng_ringBuffer_t* rngBuf = NULL;
   char bufContent[32] = {0};
   size_t wBytes = 0;
   const char* strOne = "test message 1\n";
   const char* strTwo = "test message 2\n";
   const char* strThree = "test message 3\n";

   /* detect of by ones of string termination */
   memset(bufContent, 'A', sizeof(bufContent));

   /* create new ringbuffer */
   rngBuf = rng_newRingbuffer(32);
   assert(rngBuf != NULL);

   /* write first message to ringbuffer */
   err = rng_writeRingbuffer(rngBuf, strOne);
   assert(err == LOG_ERR_OK);

   /* get first message from ringbuffer */
   err = rng_readRingbuffer(rngBuf, bufContent, sizeof(bufContent), &wBytes);
   assert(err == LOG_ERR_OK);
   assert(wBytes == strlen(strOne) + 1);
   assert(memcmp(bufContent, strOne, strlen(strOne) + 1) == 0);

   /* write next message to ringbuffer */
   err = rng_writeRingbuffer(rngBuf, strTwo);
   assert(err == LOG_ERR_OK);

   /* read both messages from ringbuffer */
   memset(bufContent, 'A', sizeof(bufContent));
   err = rng_readRingbuffer(rngBuf, bufContent, sizeof(bufContent), &wBytes);
   assert(err == LOG_ERR_OK);
   assert(wBytes == strlen(strOne) + strlen(strTwo) + 1);
   assert(memcmp(bufContent, strOne, strlen(strOne)) == 0);
   assert(memcmp(bufContent + strlen(strOne), strTwo, strlen(strTwo) + 1) == 0);

   /* write third message to ringbuffer, overflow happens */
   err = rng_writeRingbuffer(rngBuf, strThree);
   assert(err == LOG_ERR_OK);

   /* due to the overflow only message two and three must be returned */
   memset(bufContent, 'A', sizeof(bufContent));
   err = rng_readRingbuffer(rngBuf, bufContent, sizeof(bufContent), &wBytes);
   assert(err == LOG_ERR_OK);
   assert(wBytes == strlen(strTwo) + strlen(strThree) + 1);
   assert(memcmp(bufContent, strTwo, strlen(strThree)) == 0);
   assert(memcmp(bufContent + strlen(strTwo), strThree,
            strlen(strThree) + 1) == 0);

   /* reset ringbuffer no content is stored now */
   rng_resetRingbuffer(rngBuf);
   err = rng_readRingbuffer(rngBuf, bufContent, sizeof(bufContent), &wBytes);
   assert(err == LOG_ERR_NO_ENTRIES);

   /* ringbuffer is still usable after reset */
   err = rng_writeRingbuffer(rngBuf, strOne);
   assert(err == LOG_ERR_OK);

   /* get first message from ringbuffer */
   err = rng_readRingbuffer(rngBuf, bufContent, sizeof(bufContent), &wBytes);
   assert(err == LOG_ERR_OK);
   assert(wBytes == strlen(strOne) + 1);
   assert(memcmp(bufContent, strOne, strlen(strOne) + 1) == 0);

   rng_delRingbuffer(rngBuf);
}


static void
check_ringBufferLogging(
      void
      )
{
   logc_error_t err = LOG_ERR_OK;
   char checkBuf[512] = {0};
   char* ptr = checkBuf;
   size_t writtenBytes = 0;
   size_t i = 0;
   const char* testMessages[] = {
      "test message 1",
      "test message 2",
      "test message 3",
      "test message 4",
   };

   /* register logger */
   assert(logc_registerLogger(0x0011, RBUFOUT, LOG_FINEST) == LOG_ERR_OK);
   /* set ringbuffer to logger */
   assert(logc_setRingbuffer(0x0011, 512) == LOG_ERR_OK);
   /* set log format */
   assert(logc_setLogFormat(0x0011, ERR, CLEAN) == LOG_ERR_OK);

   /* test logging */
   assert(logc_log(0x0011, LOG_FINEST, testMessages[0]) == LOG_ERR_OK);
   assert(logc_logBasic(0x0011, testMessages[1]) == LOG_ERR_OK);
   assert(logc_logWarning(0x0011, testMessages[2]) == LOG_ERR_OK);
   assert(logc_logInfo(0x0011, testMessages[3]) == LOG_ERR_OK);

   /* read out ringbuffer */
   assert(logc_readRingbuffer(0x0011, checkBuf, sizeof(checkBuf),
            &writtenBytes) == LOG_ERR_OK);
   /* check writtenBytes \n is appended on each messages + \0 at end of
    * messages string */
   assert(writtenBytes == ARRAY_COUNT(testMessages) + 1 +
         strlen(testMessages[0]) * ARRAY_COUNT(testMessages));

   /* check ringbuffer content */
   for (i=0; i<ARRAY_COUNT(testMessages); i++) {
      assert(strncmp(testMessages[i], ptr, strlen(testMessages[i])) == 0);
      ptr += strlen(testMessages[i]) + 1;
   }

   /* buffer size smaller than ringbuffer content */
   memset(checkBuf, 0, sizeof(checkBuf));
   assert(logc_readRingbuffer(0x0011, checkBuf, strlen(testMessages[0]) + 10,
            &writtenBytes) == LOG_ERR_INSUFFICIENT_BUFFER);
   /* only the first entry included in checkBuf */
   assert(writtenBytes == strlen(testMessages[0]) + 1 + 1);
   assert(strncmp(testMessages[0], checkBuf, strlen(testMessages[0])) == 0);

   /* reset ringbuffer */
   assert(logc_resetRingbuffer(0x0011) == LOG_ERR_OK);
   /* must be empty after reset */
   assert(logc_readRingbuffer(0x0011, checkBuf, sizeof(checkBuf),
            &writtenBytes) == LOG_ERR_NO_ENTRIES);
   assert(writtenBytes == 0);

   /* remove the logger */
   assert(logc_removeLogger(0x0011) == LOG_ERR_OK);
}


/* ========================== END OF FILE ================================== */

/*
 * vim settings, please do not remove!
 * vim:autoindent:
 * vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=75:formatoptions=croql:
 * vim600:foldmethod=syntax:
 */


