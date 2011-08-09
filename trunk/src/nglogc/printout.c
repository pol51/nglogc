
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

#include "printout.h"
#include "ringbuffer.h"

#include "types.h"

#include <stdio.h>

/* =========== MODULE CONFIGURATION ======================================== */
/* =========== DEFINES ===================================================== */
/* =========== DATA TYPES ================================================== */
/* =========== GLOBALS ===================================================== */
/* =========== PRIVATE PROTOTYPES ========================================== */
/* =========== PUBLIC FUNCTIONS ============================================ */

/*---------------------------------------------------------------------------*/
logc_error_t
prn_stdprint(
      const char* const message,
      va_list* vaList,
      void* dest
      )
{
   logc_error_t err = LOG_ERR_OK;

   if (message == NULL) {
      err = LOG_ERR_NULL;
   } else {
      if (vaList != NULL) {
         vfprintf(stdout, message, *vaList);
      } else {
         fputs(message, stdout);
      }
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logc_error_t
prn_stderrprint(
      const char* const message,
      va_list* vaList,
      void* dest
      )
{
   logc_error_t err = LOG_ERR_OK;

   if (message == NULL) {
      err = LOG_ERR_NULL;
   } else {
      if (vaList != NULL) {
         vfprintf(stderr, message, *vaList);
      } else {
         fputs(message, stderr);
      }
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logc_error_t
prn_fileprint(
      const char* const message,
      va_list* vaList,
      void* dest
      )
{
   logc_error_t err = LOG_ERR_OK;

   if (message == NULL || dest == NULL) {
      err = LOG_ERR_NULL;
   } else {
      if (vaList != NULL) {
         vfprintf((FILE*)dest, message, *vaList);
      } else {
         fputs(message, (FILE*)dest);
      }
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logc_error_t
prn_rbufprint(
      const char* const message,
      va_list* vaList,
      void* dest
      )
{
   logc_error_t err = LOG_ERR_OK;

   if (message == NULL || dest == NULL) {
      err = LOG_ERR_NULL;
   } else {
      if (vaList != NULL) {
         char tmp[256] = {0};
         vsnprintf(tmp, sizeof(tmp), message, *vaList);
         err = rng_writeRingbuffer((rng_ringBuffer_t*)dest, tmp);
      } else {
         err = rng_writeRingbuffer((rng_ringBuffer_t*)dest, message);
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
