

#ifndef __LOGC_ARRAY_RECORD_H__
#define __LOGC_ARRAY_RECORD_H__


/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "types.h"

#include <stdarg.h>
#include <stdlib.h>

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
 * TODO
 */
logc_error_t
newArrayRecord(
      arrayRecord_t* rec
      );
/*---------------------------------------------------------------------------*/

#endif
/* ========================== END OF FILE ================================== */

/*
 * vim settings, please do not remove!
 * vim:autoindent:filetype=c:syntax=c:
 * vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=75:formatoptions=croql:
 * vim600:foldmethod=syntax:
 */

