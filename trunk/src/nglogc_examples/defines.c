/* gcc -o log_level log_level.c -L nglogc/src/nglogc/ -lnglogc */

#include "../nglogc/log.h"

 /* loggers are identified by an uint16_t type */
#define MAIN_LOGGER          0x0001


static void
runLogs(
      void
      )
{
   /* trace the function call */
   logc_logEnter(MAIN_LOGGER, "runLogs");

   /* log an error message with the log level LOG_BASIC */
   logc_logErrorBasic(MAIN_LOGGER, 0, "This is a LOG_BASIC error message");
   /* log an error message with the log level LOG_WARNING */
   logc_logErrorWarning(MAIN_LOGGER, 0, "This is a LOG_WARNING error message");
   /* log an error message with the log level LOG_INFO */
   logc_logErrorInfo(MAIN_LOGGER, 0, "This is a LOG_INFO error message");
   /* log an error message with the log level LOG_FINE */
   logc_logErrorFine(MAIN_LOGGER, 0, "This is a LOG_FINE error message");
   /* log an error message with the log level LOG_FINEST */
   logc_logErrorFinest(MAIN_LOGGER, 0, "This is a LOG_FINEST error message\n");

   /* log an log message with the log level LOG_BASIC */
   logc_logBasic(MAIN_LOGGER, "This is a LOG_BASIC log message");
   /* log an log message with the log level LOG_WARNING */
   logc_logWarning(MAIN_LOGGER, "This is a LOG_WARNING log message");
   /* log an log message with the log level LOG_INFO */
   logc_logInfo(MAIN_LOGGER, "This is a LOG_INFO log message");
   /* log an log message with the log level LOG_FINE */
   logc_logFine(MAIN_LOGGER, "This is a LOG_FINE log message");
   /* log an log message with the log level LOG_FINEST */
   logc_logFinest(MAIN_LOGGER, "This is a LOG_FINEST log message");

   /* trace the function call */
   logc_logLeave(MAIN_LOGGER, "runLogs");
}


int main(int argc, char *argv[])
{
   /* register a logger with the stdout publisher and
    LOG_BASIC log level */
   logc_registerLogger(MAIN_LOGGER, STDOUT, LOG_FINEST);

   /* change format for logs and error logs */
   logc_setLogFormat(MAIN_LOGGER, ERR_TAG, TIMESTAMP);

   runLogs();

   /* remove the logger */
   logc_removeLogger(MAIN_LOGGER);

   return 0;
}

