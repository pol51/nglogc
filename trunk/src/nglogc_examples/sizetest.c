/* gcc -o log_level log_level.c -lnglogc -DLOGC_ENABLE_LOW_LEVEL */

#include <nglogc/log.h>


 /* loggers are identified by an uint16_t type */
#define MAIN_LOGGER          0x0001


static
printLogs(
      void
      )
{
   logc_logEnter(MAIN_LOGGER, "printLogs");

   logc_logErrorBasic(MAIN_LOGGER, 0, "This is a LOG_BASIC error message");
   logc_logErrorWarning(MAIN_LOGGER, 0, "This is a LOG_BASIC error message");

   logc_logBasic(MAIN_LOGGER, "This is a LOG_BASIC error message");
   logc_logWarning(MAIN_LOGGER, "This is a LOG_BASIC error message");

   logc_logLeave(MAIN_LOGGER, "printLogs");
}


int main(int argc, char *argv[])
{
   logc_registerLogger(MAIN_LOGGER, STDOUT, LOG_FINEST);

   printLogs();

   logc_removeLogger(MAIN_LOGGER);

   return 0;
}

