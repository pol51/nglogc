
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

#ifndef __LOGC_FLF_LOG_H__
#define __LOGC_FLF_LOG_H__


/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif /* ifdef __cplusplus */

/* =========== DEFINES ===================================================== */
/* =========== DATA TYPES ================================================== */
/* =========== PUBLIC PROTOTYPES =========================================== */

/*---------------------------------------------------------------------------*/
/*
 * prints log messages to given logger and log level
 * DO NOT USE THIS FUNCTION DIRECTLY
 * USE THE DEFINITIONS IN LOG.H
 *
 * @param file           in : __FILE__
 * @param line           in : __LINE__
 * @param func           in : __func__
 * @param ident          in : identifier of the logger
 * @param level          in : log level of message
 * @param formatStr      in : format string log message
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if formatStr is NULL
 *                       LOG_ERR_NOT_FOUND if the logger is not found
 *                       LOG_ERR_LEVEL not printed because of the log level
 *                       error types from newLogRecord function
 */
logc_error_t
logc_log_flf_(
      const char* file,
      int line,
      const char* func,
      uint16_t ident,
      logc_logLevel_t level,
      const char* formatStr,
      ...
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

