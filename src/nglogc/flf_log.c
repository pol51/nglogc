
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

#include "flf_log.h"

#include "logger.h"
#include "log_record.h"

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* =========== MODULE CONFIGURATION ======================================== */
/* =========== DEFINES ===================================================== */

#define MAX_INT   10

/* =========== DATA TYPES ================================================== */
/* =========== GLOBALS ===================================================== */
/* =========== PRIVATE PROTOTYPES ========================================== */
/* =========== PUBLIC FUNCTIONS ============================================ */

/*---------------------------------------------------------------------------*/
extern logger_t*
getLogger(
      uint16_t ident
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logc_error_t
logc_log_flf_(
      const char* file,
      int line,
      const char* func,
      uint16_t ident,
      logc_logLevel_t level,
      const char* formatStr,
      ...
      )
{
   logc_error_t err = LOG_ERR_OK;
   logger_t* logger = NULL;
   va_list vaList;
   logRecord_t record = {0};

   if (formatStr == NULL) {
      err = LOG_ERR_NULL;
   }

   if (err == LOG_ERR_OK) {
      logger = getLogger(ident);
      if (logger == NULL) {
         err = LOG_ERR_NOT_FOUND;
      }
   }

   if (err == LOG_ERR_OK) {
      if (logger->level < level) {
         err = LOG_ERR_LEVEL;
      } else {
         va_start(vaList, formatStr);
         record.file = file;
         record.line = line;
         record.function = func;
         record.rtype = logger->logRecordType;
         record.formatStr = formatStr;
         record.vaList = &vaList;
         err = newLogRecord(&record);
         if (err == LOG_ERR_OK) {
            logger->publisher(record.newRecord, record.vaList, logger->dest);
            deleteLogRecord(&record);
         }
         va_end(vaList);
      }
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/* =========== PRIVATE FUNCTIONS =========================================== */
/* ========================== END OF FILE ================================== */

/*
 * vim settings, please do not remove!
 * vim:autoindent:
 * vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=75:formatoptions=croql:
 * vim600:foldmethod=syntax:
 */
