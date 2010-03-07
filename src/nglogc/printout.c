
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
      char* const message,
      FILE* fd
      )
{
   logc_error_t err = LOG_ERR_OK;

   if (message != NULL) {
      fprintf(stdout, message);
   } else {
      err = LOG_ERR_NULL;
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logc_error_t
prn_stderrprint(
      char* const message,
      FILE* fd
      )
{
   logc_error_t err = LOG_ERR_OK;

   if (message != NULL) {
      fprintf(stderr, message);
   } else {
      err = LOG_ERR_NULL;
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logc_error_t
prn_fileprint(
      char* const message,
      FILE* fd
      )
{
   logc_error_t err = LOG_ERR_OK;

   if (message == NULL || fd == NULL) {
      err = LOG_ERR_NULL;
   } else {
      fprintf(fd, message);
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logc_error_t
prn_rbufprint(
      char* const message,
      FILE* fd
      )
{
   /* TODO */
   logc_error_t err = LOG_ERR_OK;
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
