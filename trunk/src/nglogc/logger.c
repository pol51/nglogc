
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

/* this function is only added for unit testing, so this function is not
 * defined in the header file but also not static to make it usable with
 * extern keyword */
int
getLoggerCount(
      void
      );

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
      newLogger->logger.type = type;
      newLogger->logger.level = level;
      newLogger->logger.errRecordType = ERR;
      newLogger->logger.logRecordType = CLEAN;

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
            newLogger->logger.publisher = &prn_rbufprint;
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

   if (err != LOG_ERR_OK) {
      if (newLogger != NULL) {
         free(newLogger);
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

      if (iter->logger.dest != NULL) {
         if (iter->logger.type == FILEOUT) {
            fclose((FILE*)iter->logger.dest);
         } else {
            rng_delRingbuffer((rng_ringBuffer_t*)iter->logger.dest);
         }
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
   logger_t* logger = NULL;

   if (level < LOG_SILENT || level > LOG_FINEST) {
      err = LOG_ERR_PARAM;
   }

   if (err == LOG_ERR_OK) {
      logger = getLogger(ident);
      if (logger != NULL) {
         logger->level = level;
      } else {
         err = LOG_ERR_NOT_FOUND;
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
   logger_t* logger = NULL;

   if (errForm < ERR || errForm > TIMESTAMP_ERR_TAG ||
         logForm < CLEAN || logForm > TIMESTAMP) {
      err = LOG_ERR_PARAM;
   }

   if (err == LOG_ERR_OK) {
      logger = getLogger(ident);
      if (logger != NULL) {
         logger->errRecordType = errForm;
         logger->logRecordType = logForm;
      } else {
         err = LOG_ERR_NOT_FOUND;
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
   logger_t* logger = NULL;

   if (filename == NULL) {
      err = LOG_ERR_NULL;
   }

   if (err == LOG_ERR_OK) {
      logger = getLogger(ident);
      if (logger == NULL) {
         err = LOG_ERR_NOT_FOUND;
      } else {
         if (logger->type != FILEOUT) {
            err = LOG_ERR_WRONG_TYPE;
         } else {
            logger->dest = fopen(filename, "a");
            err = (logger->dest != NULL) ?
               LOG_ERR_OK : LOG_ERR_OPEN_FILE;
         }
      }
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logc_error_t
logc_setRingbuffer(
      uint16_t ident,
      const size_t size
      )
{
   logc_error_t err = LOG_ERR_OK;
   logger_t* logger = NULL;

   if (err == LOG_ERR_OK) {
      logger = getLogger(ident);
      if (logger == NULL) {
         err = LOG_ERR_NOT_FOUND;
      } else {
         if (logger->type != RBUFOUT) {
            err = LOG_ERR_WRONG_TYPE;
         } else {
            logger->dest = rng_newRingbuffer(size);
            err = (logger->dest != NULL) ?
               LOG_ERR_OK : LOG_ERR_CREATE_RNGBUF;
         }
      }
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logc_error_t
logc_resetRingbuffer(
      uint16_t ident
      )
{
   logc_error_t err = LOG_ERR_OK;
   logger_t* logger = NULL;

   if (err == LOG_ERR_OK) {
      logger = getLogger(ident);
      if (logger == NULL) {
         err = LOG_ERR_NOT_FOUND;
      } else {
         if (logger->dest != NULL && logger->type == RBUFOUT) {
            rng_resetRingbuffer((rng_ringBuffer_t*)logger->dest);
         } else {
            err = LOG_ERR_NO_RNGBUF;
         }
      }
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logc_error_t
logc_readRingbuffer(
      uint16_t ident,
      char* const buffer,
      const size_t size,
      size_t* const writtenBytes
      )
{
   logc_error_t err = LOG_ERR_OK;
   logger_t* logger = NULL;

   if (buffer == NULL || writtenBytes == NULL) {
      err = LOG_ERR_NULL;
   }

   if (err == LOG_ERR_OK) {
      logger = getLogger(ident);
      if (logger == NULL) {
         err = LOG_ERR_NOT_FOUND;
      } else if (logger->type == RBUFOUT) {
         err = rng_readRingbuffer((rng_ringBuffer_t*)logger->dest, buffer,
               size, writtenBytes);
      } else {
         err = LOG_ERR_NO_RNGBUF;
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

/* ========================== END OF FILE ================================== */

/*
 * vim settings, please do not remove!
 * vim:autoindent:
 * vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=75:formatoptions=croql:
 * vim600:foldmethod=syntax:
 */
