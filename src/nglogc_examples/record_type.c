/* gcc -o record_type record_type.c -L ../nglogc/ -lnglogc -DLOGC_ENABLE_LOW_LEVEL */

#include "../nglogc/log.h"

 /* loggers are identified by an uint16_t type */
#define MAIN_LOGGER   0x0001

/* example error code */
#define ERR_TEST      0x00000001


int main(int argc, char *argv[])
{
   /* register a logger with the stdout publisher and
    LOG_BASIC log level. The errRecordType_t is set to ERR
    the logRecordType_t is set to CLEAN per default */
   logc_registerLogger(MAIN_LOGGER, STDOUT, LOG_BASIC);

   /* log an error message with the default error log format ERR */
   logc_logError(MAIN_LOGGER, LOG_BASIC, ERR_TEST,
         "Error message with ERR format");

   /* set error record type to ERR_TAG */
   logc_setLogFormat(MAIN_LOGGER, ERR_TAG, CLEAN);
   logc_logError(MAIN_LOGGER, LOG_BASIC, ERR_TEST,
         "Error message with ERR_TAG format");

   /* set error record type to ERR_TAG_TIMESTAMP */
   logc_setLogFormat(MAIN_LOGGER, ERR_TAG_TIMESTAMP, CLEAN);
   logc_logError(MAIN_LOGGER, LOG_BASIC, ERR_TEST,
         "Error message with ERR_TAG_TIMESTAMP format");

   /* set error record type to ERR_TIMESTAMP_TAG */
   logc_setLogFormat(MAIN_LOGGER, ERR_TIMESTAMP_TAG, CLEAN);
   logc_logError(MAIN_LOGGER, LOG_BASIC, ERR_TEST,
         "Error message with ERR_TIMESTAMP_TAG format");

   /* set error record type to TIMESTAMP_ERR_TAG */
   logc_setLogFormat(MAIN_LOGGER, TIMESTAMP_ERR_TAG, CLEAN);
   logc_logError(MAIN_LOGGER, LOG_BASIC, ERR_TEST,
         "Error message with TIMESTAMP_ERR_TAG format\n");


   /* log an log message with the default log format CLEAN */
   logc_log(MAIN_LOGGER, LOG_BASIC,
         "Log message with CLEAN format");

   /* set log record type to TIMESTAMP */
   logc_setLogFormat(MAIN_LOGGER, TIMESTAMP_ERR_TAG, TIMESTAMP);
   logc_log(MAIN_LOGGER, LOG_BASIC,
         "Log message with TIMESTAMP format");

   /* remove the logger */
   logc_removeLogger(MAIN_LOGGER);

   return 0;
}

