/* gcc -o main main.c -lnglogc */

#include <nglogc/log.h>

 /* loggers are identified by an uint16_t type */
#define MAIN_LOGGER   0x0001


int main(int argc, char *argv[])
{
   int i = 0;
   unsigned char data[16] = {0};

   /* register a logger with the stdout publisher and
    LOG_BASIC log level */
   logc_registerLogger(MAIN_LOGGER, STDOUT, LOG_BASIC);

   /* fill some test data */
   for (i=0; i<sizeof(data); i++) {
      data[i] = 'A' + i;
   }

   /* log an error message with the log level LOG_BASIC */
   logc_logLevelError(MAIN_LOGGER, LOG_BASIC, 0,
         "This is a error message");

   /* log an info message with the log level LOG_BASIC */
   logc_log(MAIN_LOGGER, LOG_BASIC,
         "This is a log message");

   /* log an data array in hex with description */
   logc_logArray(MAIN_LOGGER, LOG_BASIC,
         "Data array", data, sizeof(data));

   /* remove the logger */
   logc_removeLogger(MAIN_LOGGER);

   return 0;
}

