
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

#ifndef __LOGC_TYPES_H__
#define __LOGC_TYPES_H__


/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdlib.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif /* ifdef __cplusplus */

/* =========== DEFINES ===================================================== */

/*
 * log errors
 */
#define LOG_ERR_OK                   0x00000000

#define LOG_ERR_DATA                 0x00000001

#define LOG_ERR_PARAM                0x00000002

#define LOG_ERR_MEM                  0x00000003

#define LOG_ERR_NOT_FOUND            0x00000004

#define LOG_ERR_LEVEL                0x00000005

#define LOG_ERR_NULL                 0x00000006

#define LOG_ERR_OPEN_FILE            0x00000007

#define LOG_ERR_NO_ENTRIES           0x00000008

#define LOG_ERR_INSUFFICIENT_BUFFER  0x00000009

#define LOG_ERR_CREATE_RNGBUF        0x0000000A

#define LOG_ERR_NO_RNGBUF            0x0000000B

#define LOG_ERR_WRONG_TYPE           0x0000000C

#define LOG_ERR_NOT_IMPLEMENTED      0x00000010


/* =========== DATA TYPES ================================================== */

/* log error type */
typedef uint32_t logc_error_t;

/*
 * boolean type
 */
typedef enum {
   LOG_TRUE = 1,
   LOG_FALSE = 0
} logc_bool_t;

/*
 * log levels enumeration
 */
typedef enum {
   /* no logging */
   LOG_SILENT,
   /* severe message */
   LOG_BASIC,
   /* warning message */
   LOG_WARNING,
   /* an informal message */
   LOG_INFO,
   /* debug message */
   LOG_FINE,
   /* a detailed debug message */
   LOG_FINEST

} logc_logLevel_t;


/*
 * output types
 */
typedef enum {
   /* standard output */
   STDOUT,
   /* standard error output */
   STDERROUT,
   /* file output */
   FILEOUT,
   /* ringbuffer output */
   RBUFOUT

} logc_loggerType_t;


/*
 * type of error record format
 */
typedef enum {
   /* ERR: message */
   ERR,
   /* ERR 0xYYYYYYYY: message */
   ERR_TAG,
   /* ERR: 0xYYYYYYYY <timestamp>: message */
   ERR_TAG_TIMESTAMP,
   /* ERR <timestamp> 0xYYYYYYYY: message */
   ERR_TIMESTAMP_TAG,
   /* <timestamp> ERR: 0xYYYYYYYY: message */
   TIMESTAMP_ERR_TAG

} logc_errRecordType_t;

/*
 * type of log record format
 */
typedef enum {
   /* message */
   CLEAN,
   /* <timestamp> message */
   TIMESTAMP

} logc_logRecordType_t;

/* =========== PUBLIC PROTOTYPES =========================================== */

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

