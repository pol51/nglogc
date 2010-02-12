

#ifndef __LOGC_LOGGGER_TYPE__H__
#define __LOGC_LOGGGER_TYPE_H__


/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "types.h"

#include <stdio.h>

/* =========== DEFINES ===================================================== */
/* =========== DATA TYPES ================================================== */

/* typedef for publisher function */
typedef logc_error_t (*publisher_t)(
      char* const message,
      FILE* fd
      );

/* logger type */
struct logger_s {
   /* identifier of the logger */
   uint16_t id;
   /* logger output type */
   logc_loggerType_t type;
   /* log level */
   logc_logLevel_t level;
   /* record type for error logging */
   logc_errRecordType_t errRecordType;
   /* record type for log logging */
   logc_logRecordType_t logRecordType;
   /* pointer to publisher function */
   publisher_t publisher;
   /* file */
   FILE* fd;
};
typedef struct logger_s logger_t;

/* =========== PUBLIC PROTOTYPES =========================================== */
#endif
/* ========================== END OF FILE ================================== */

/*
 * vim settings, please do not remove!
 * vim:autoindent:filetype=c:syntax=c:
 * vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=75:formatoptions=croql:
 * vim600:foldmethod=syntax:
 */

