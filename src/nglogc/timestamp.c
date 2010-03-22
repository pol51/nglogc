
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

#include "timestamp.h"

#if defined TM_IN_SYS_TIME
#include <sys/time.h>
#endif

#if defined (HAVE_TIME_H) && defined (HAVE_STRFTIME)
#include <time.h>
#else
#define NO_TIMESTAMP
#include <stdio.h>
#endif

/* =========== MODULE CONFIGURATION ======================================== */
/* =========== DEFINES ===================================================== */
/* =========== DATA TYPES ================================================== */
/* =========== GLOBALS ===================================================== */
/* =========== PRIVATE PROTOTYPES ========================================== */
/* =========== PUBLIC FUNCTIONS ============================================ */

void
addTimestamp(
      char* str
      )
{
#ifndef NO_TIMESTAMP
   struct tm tim;
   time_t now;
#endif

   if (str != NULL) {
#ifndef NO_TIMESTAMP
      now = time(NULL);
      tim = *(localtime(&now));
      strftime(str, TIMEST_LENGTH, "%c", &tim);
#else
      const char* noTm = "<no timestamp on host>  ";
      sprintf(str, "%s", noTm);
#endif
      str[TIMEST_LENGTH-1] = 0x20;
   }
}


/* =========== PRIVATE FUNCTIONS =========================================== */
/* ========================== END OF FILE ================================== */

/*
 * vim settings, please do not remove!
 * vim:autoindent:
 * vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=75:formatoptions=croql:
 * vim600:foldmethod=syntax:
 */
