
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

#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>

/* =========== MODULE CONFIGURATION ======================================== */

//#define LOGC_ENABLE_LOW_LEVEL 1

/* =========== DEFINES ===================================================== */

/* test log file to compare the logger output */
#define UNITTESTS_LOGFILE   "unittests.log"

/* =========== DATA TYPES ================================================== */
/* =========== GLOBALS ===================================================== */
/* =========== PRIVATE PROTOTYPES ========================================== */

static void
check_flf(
      void
      );

/* =========== PUBLIC FUNCTIONS ============================================ */

int main(int argc, char *argv[])
{
   printf("\n  running check_flf\n");
   check_flf();
   printf("  all tests passed\n\n");

   return 0;
}

/* =========== PRIVATE FUNCTIONS =========================================== */

static void
check_flf(
      void
      )
{
   FILE* fd = NULL;
   char checkBuf[256] = {0};
   char tmpBuf[256] = {0};
   int check = 0;

   /* in case of a failed unittest the logfile is not erased and further
    * runs will fail */
   remove(UNITTESTS_LOGFILE);

   /* register logger */
   assert(logc_registerLogger(0x0011, FILEOUT, LOG_BASIC) == LOG_ERR_OK);
   assert(getLoggerCount() == 1);
   /* set filename to log in */
   assert(logc_setLogfile(0x0011, UNITTESTS_LOGFILE) == LOG_ERR_OK);

   /* log messages */
   assert(logc_logErrorBasic(0x0011, 0x00000001, "error message") == LOG_ERR_OK);
   assert(logc_log(0x0011, LOG_BASIC, "log message") == LOG_ERR_OK);

   /* remove the logger to close the file */
   assert(logc_removeLogger(0x0011) == LOG_ERR_OK);
   assert(getLoggerCount() == 0);

   /* open file to check the logging output */
   fd = fopen(UNITTESTS_LOGFILE, "r");
   if (fd == NULL) {
      printf("error couldn't open file\n");
   }

   /* check the output of the loggers
    * no macros here, because if they don't work in library they won't work
    * here */
   assert(fgets(checkBuf, sizeof(checkBuf), fd) != NULL);
   check = strncmp(checkBuf,
         "ERR : unittests_flf.c:89 check_flf - error message\n",
         sizeof(checkBuf));
   assert(check == 0);

   assert(fgets(checkBuf, sizeof(checkBuf), fd) != NULL);
   check = strncmp(checkBuf,
         "unittests_flf.c:90 check_flf - log message\n",
         sizeof(checkBuf));
   assert(check == 0);

   if (fd) {
      fclose(fd);
   }

   remove(UNITTESTS_LOGFILE);
}

/* ========================== END OF FILE ================================== */

/*
 * vim settings, please do not remove!
 * vim:autoindent:
 * vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=75:formatoptions=croql:
 * vim600:foldmethod=syntax:
 */


