
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "logger.h"

#include "types.h"
#include "printout.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* =========== MODULE CONFIGURATION ======================================== */

#define DEBUG 1

/* =========== DEFINES ===================================================== */
/* =========== DATA TYPES ================================================== */

/* double linked list type of loggers */
struct loggerList_s {
   logger_t logger;
   struct loggerList_s* next;
   struct loggerList_s* before;
};
typedef struct loggerList_s loggerList_t;

/* =========== GLOBALS ===================================================== */

static
loggerList_t* loggerList = NULL;

static
loggerList_t* loggerLast = NULL;

/* =========== PRIVATE PROTOTYPES ========================================== */

#if defined (DEBUG)
int
getLoggerCount(
      void
      );
#endif
/* =========== PUBLIC FUNCTIONS ============================================ */

/*---------------------------------------------------------------------------*/
logc_error_t
logc_registerLogger(
      uint16_t ident,
      logc_loggerType_t type,
      logc_logLevel_t level
      )
{
   logc_error_t err = LOG_ERR_OK;
   loggerList_t* newLogger = NULL;

   if (type < STDOUT || type > RBUFOUT ||
         level < LOG_SILENT || level > LOG_FINEST) {
      err = LOG_ERR_PARAM;
   }

   if (err == LOG_ERR_OK) {
      newLogger = (loggerList_t*)malloc(sizeof(*newLogger));
      if (newLogger != NULL) {
         memset(newLogger, 0, sizeof(*newLogger));
      } else {
         err = LOG_ERR_MEM;
      }
   }

   if (err == LOG_ERR_OK) {
      newLogger->logger.id = ident;
      newLogger->logger.level = level;
      newLogger->logger.errRecordType = ERR;
      newLogger->logger.logRecordType = ERR;

      switch (type) {
         case STDOUT:
            newLogger->logger.publisher = &prn_stdprint;
            break;
         case STDERROUT:
            newLogger->logger.publisher = &prn_stderrprint;
            break;
         case FILEOUT:
            newLogger->logger.publisher = &prn_fileprint;
            break;
         case RBUFOUT:
            /* TODO */
            break;
      }
   }

   if (err == LOG_ERR_OK) {
      if (loggerLast == NULL) {
         loggerList = newLogger;
         loggerLast = loggerList;
      } else {
         newLogger->before = loggerLast;
         loggerLast->next = newLogger;
         loggerLast = newLogger;
      }
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logc_error_t
logc_removeLogger(
      uint16_t ident
      )
{
   logc_error_t err = LOG_ERR_NOT_FOUND;
   loggerList_t* iter = NULL;

   iter = loggerList;
   while (iter != NULL) {
      if (iter->logger.id == ident) {
         err = LOG_ERR_OK;
         break;
      }
      iter = iter->next;
   }

   if (err == LOG_ERR_OK) {
      if (iter->before) {
         iter->before->next = iter->next;
         if (iter->next) {
            iter->next->before = iter->before;
         }
      } else {
         loggerList = iter->next;
         if (iter->next) {
            iter->next->before = NULL;
         }
      }

      if (iter->next == NULL) {
         loggerLast = iter->before;
      }

      if (iter->logger.fd) {
         fclose(iter->logger.fd);
      }
      free(iter);
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logc_error_t
logc_changeLogLevel(
      uint16_t ident,
      logc_logLevel_t level
      )
{
   logc_error_t err = LOG_ERR_OK;
   loggerList_t* iter = NULL;

   if (level < LOG_SILENT || level > LOG_FINEST) {
      err = LOG_ERR_PARAM;
   }

   if (err == LOG_ERR_OK) {
      err = LOG_ERR_NOT_FOUND;
      iter = loggerList;

      while (iter != NULL) {
         if (iter->logger.id == ident) {
            iter->logger.level = level;
            err = LOG_ERR_OK;
            break;
         }
         iter = iter->next;
      }
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logc_error_t
logc_setLogFormat(
      uint16_t ident,
      logc_errRecordType_t errForm,
      logc_logRecordType_t logForm
      )
{
   logc_error_t err = LOG_ERR_OK;
   loggerList_t* iter = NULL;

   if (errForm < ERR || errForm > TIMESTAMP_ERR_TAG ||
         logForm < CLEAN || logForm > TIMESTAMP) {
      err = LOG_ERR_PARAM;
   }

   if (err == LOG_ERR_OK) {
      err = LOG_ERR_NOT_FOUND;
      iter = loggerList;

      while (iter != NULL) {
         if (iter->logger.id == ident) {
            iter->logger.errRecordType = errForm;
            iter->logger.logRecordType = logForm;
            err = LOG_ERR_OK;
            break;
         }
         iter = iter->next;
      }
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logc_error_t
logc_setLogfile(
      uint16_t ident,
      const char* const filename
      )
{
   logc_error_t err = LOG_ERR_OK;
   loggerList_t* iter = NULL;

   if (filename == NULL) {
      err = LOG_ERR_NULL;
   }

   if (err == LOG_ERR_OK) {
      err = LOG_ERR_NOT_FOUND;
      iter = loggerList;

      while (iter != NULL) {
         if (iter->logger.id == ident) {
            iter->logger.fd = fopen(filename, "a");
            if (iter->logger.fd) {
               err = LOG_ERR_OK;
            } else {
               err = LOG_ERR_OPEN_FILE;
            }
            break;
         }
         iter = iter->next;
      }
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logger_t*
getLogger(
      uint16_t ident
      )
{
   logger_t* ret = NULL;
   loggerList_t* iter = loggerList;

   while (iter != NULL) {
      if (iter->logger.id == ident) {
         ret = &(iter->logger);
         break;
      }
      iter = iter->next;
   }

   return ret;
}
/*---------------------------------------------------------------------------*/

/* =========== PRIVATE FUNCTIONS =========================================== */

#if defined (DEBUG)
int
getLoggerCount(
      void
      )
{
   int count = 0;
   loggerList_t* iter = loggerList;

   while (iter != NULL) {
      count++;
      iter = iter->next;
   }

   return count;
}
#endif

/* ========================== END OF FILE ================================== */

/*
 * vim settings, please do not remove!
 * vim:autoindent:
 * vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=75:formatoptions=croql:
 * vim600:foldmethod=syntax:
 */
