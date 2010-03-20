
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

#ifndef __LOGC_ARRAY_RECORD_H__
#define __LOGC_ARRAY_RECORD_H__


/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "types.h"

#include <stdarg.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif /* ifdef __cplusplus */

/* =========== DEFINES ===================================================== */

/* =========== DATA TYPES ================================================== */

/*
 * record struct for array logging
 */
struct arrayRecord_s {
   /* __FILE__ */
   const char* file;
   /* __LINE__ */
   int line;
   /* __FUNCTION__ */
   const char* function;
   /* pointer to new record */
   char* newRecord;
   /* record type */
   logc_logRecordType_t rtype;
   /* descriptor */
   const char* descriptor;
   /* data */
   const uint8_t* array;
   /* length of data */
   size_t len;
};
typedef struct arrayRecord_s arrayRecord_t;

/* =========== PUBLIC PROTOTYPES =========================================== */

/*---------------------------------------------------------------------------*/
/*
 * create a new array record
 * allocated on heap, rec->newRecord must be freed by the caller
 *
 * @param rec            in : array record struct
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_NULL if parameter rec is NULL
 *                       LOG_ERR_PARAM for invalid record type
 *                       LOG_ERR_MEM if no memory could be allocated
 */
logc_error_t
newArrayRecord(
      arrayRecord_t* rec
      );
/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
}; /* close `extern "C" */
#endif /* ifdef __cplusplus */

#endif
/* ========================== END OF FILE ================================== */

/*
 * vim settings, please do not remove!
 * vim:autoindent:filetype=c:syntax=c:
 * vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=75:formatoptions=croql:
 * vim600:foldmethod=syntax:
 */

