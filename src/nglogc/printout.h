
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

#ifndef __LOGC_PRINTOUT_H__
#define __LOGC_PRINTOUT_H__


/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "types.h"

#include <stdio.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif /* ifdef __cplusplus */

/* =========== DEFINES ===================================================== */
/* =========== DATA TYPES ================================================== */
/* =========== PUBLIC PROTOTYPES =========================================== */

/*---------------------------------------------------------------------------*/
/*
 * print message to standard out
 *
 * @param message        in : logging message
 * @param vaList         in : va_list of formatStr, could be NULL
 * @param fd             in : file descriptor, not used could be NULL
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if message is NULL
 */
logc_error_t
prn_stdprint(
      const char* const message,
      va_list* vaList,
      FILE* fd
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * print message to standard err
 *
 * @param message        in : logging message
 * @param vaList         in : va_list of formatStr, could be NULL
 * @param fd             in : file descriptor, not used could be NULL
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if message is NULL
 */
logc_error_t
prn_stderrprint(
      const char* const message,
      va_list* vaList,
      FILE* fd
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * print message to log file
 *
 * @param message        in : logging message
 * @param vaList         in : va_list of formatStr, could be NULL
 * @param fd             in : file descriptor for logging file
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if message or fd is NULL
 */
logc_error_t
prn_fileprint(
      const char* const message,
      va_list* vaList,
      FILE* fd
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * print message to ringbuffer
 *
 * @param message        in : logging message
 * @param vaList         in : va_list of formatStr, could be NULL
 * @param fd             in : file descriptor, not used could be NULL
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if message or fd is NULL
 *                       TODO not implemented
 */
logc_error_t
prn_rbufprint(
      const char* const message,
      va_list* vaList,
      FILE* fd
      );
/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
}; /* close `extern "C" */
#endif /* ifdef __cplusplus */

#endif /* header guard */
/* ========================== END OF FILE ================================== */

/*
 * vim settings, please do not remove!
 * vim:autoindent:filetype=c:syntax=c:
 * vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=75:formatoptions=croql:
 * vim600:foldmethod=syntax:
 */

