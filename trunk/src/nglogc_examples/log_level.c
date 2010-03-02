/* gcc -o log_level log_level.c -L ../nglogc/ -lnglogc -DLOGC_ENABLE_LOW_LEVEL */

#include "../nglogc/log.h"

 /* loggers are identified by an uint16_t type */
#define MAIN_LOGGER          0x0001


static void
printErrorLogs(
      void
      )
{
   /* log an error message with the log level LOG_BASIC */
   logc_logErrorBasic(MAIN_LOGGER, 0, "This is a LOG_BASIC error message");
   /* log an error message with the log level LOG_WARNING */
   logc_logErrorWarning(MAIN_LOGGER, 0, "This is a LOG_WARNING error message");
   /* log an error message with the log level LOG_INFO */
   logc_logErrorInfo(MAIN_LOGGER, 0, "This is a LOG_INFO error message");
   /* log an error message with the log level LOG_FINE */
   logc_logErrorFine(MAIN_LOGGER, 0, "This is a LOG_FINE error message");
   /* log an error message with the log level LOG_FINEST */
   logc_logErrorFinest(MAIN_LOGGER, 0, "This is a LOG_FINEST error message");
}


int main(int argc, char *argv[])
{
   /* register a logger with the stdout publisher and
    LOG_SILENT log level */
   logc_registerLogger(MAIN_LOGGER, STDOUT, LOG_SILENT);

   /* change log level to LOG_BASIC */
   logc_changeLogLevel(MAIN_LOGGER, LOG_BASIC);
   logc_logBasic(MAIN_LOGGER, "\nlogLevel is set to LOG_BASIC");
   printErrorLogs();

   /* change log level to LOG_WARNING */
   logc_changeLogLevel(MAIN_LOGGER, LOG_WARNING);
   logc_logBasic(MAIN_LOGGER, "\nlogLevel is set to LOG_WARNING");
   printErrorLogs();

   /* change log level to LOG_INFO */
   logc_changeLogLevel(MAIN_LOGGER, LOG_INFO);
   logc_logBasic(MAIN_LOGGER, "\nlogLevel is set to LOG_INFO");
   printErrorLogs();

   /* change log level to LOG_FINE */
   logc_changeLogLevel(MAIN_LOGGER, LOG_FINE);
   logc_logBasic(MAIN_LOGGER, "\nlogLevel is set to LOG_FINE");
   printErrorLogs();

   /* change log level to LOG_FINEST */
   logc_changeLogLevel(MAIN_LOGGER, LOG_FINEST);
   logc_logBasic(MAIN_LOGGER, "\nlogLevel is set to LOG_FINEST");
   printErrorLogs();

   /* remove the logger */
   logc_removeLogger(MAIN_LOGGER);

   return 0;
}

