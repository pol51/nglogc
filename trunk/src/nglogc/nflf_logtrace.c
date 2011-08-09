
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

#include "nflf_logtrace.h"

#include "logger.h"

#include <stdlib.h>
#include <string.h>

/* =========== MODULE CONFIGURATION ======================================== */
/* =========== DEFINES ===================================================== */
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
logc_logEnter_nflf_(
      uint16_t ident,
      const char* functionName
      )
{
   logc_error_t err = LOG_ERR_OK;
   logger_t* logger = NULL;
   char* record = NULL;

   if (functionName == NULL) {
      err = LOG_ERR_NULL;
   }

   if (err == LOG_ERR_OK) {
      logger = getLogger(ident);
      if (logger == NULL) {
         err = LOG_ERR_NOT_FOUND;
      } else {
         if (logger->level < LOG_FINEST) {
            err = LOG_ERR_LEVEL;
         }
      }
   }

   if (err == LOG_ERR_OK) {
      record = malloc(strlen(functionName) + sizeof("Enter > ") + 1);
      if (record == NULL) {
         err = LOG_ERR_MEM;
      } else {
         sprintf(record, "Enter > %s\n", functionName);
         logger->publisher(record, NULL, logger->dest);
      }
   }

   if (record != NULL) {
      free(record);
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logc_error_t
logc_logLeave_nflf_(
      uint16_t ident,
      const char* functionName
      )
{
   logc_error_t err = LOG_ERR_OK;
   logger_t* logger = NULL;
   char* record = NULL;

   if (functionName == NULL) {
      err = LOG_ERR_NULL;
   }

   if (err == LOG_ERR_OK) {
      logger = getLogger(ident);
      if (logger == NULL) {
         err = LOG_ERR_NOT_FOUND;
      } else {
         if (logger->level < LOG_FINEST) {
            err = LOG_ERR_LEVEL;
         }
      }
   }

   if (err == LOG_ERR_OK) {
      record = malloc(strlen(functionName) + sizeof("Leave < ") + 1);
      if (record == NULL) {
         err = LOG_ERR_MEM;
      } else {
         sprintf(record, "Leave < %s\n", functionName);
         logger->publisher(record, NULL, logger->dest);
      }
   }

   if (record != NULL) {
      free(record);
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
