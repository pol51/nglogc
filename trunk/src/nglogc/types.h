

#ifndef __LOGC_TYPES_H__
#define __LOGC_TYPES_H__


/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

/* =========== DEFINES ===================================================== */

#define LOG_ERR_OK               0x00000000

#define LOG_ERR_DATA             0x00001001

/* =========== DATA TYPES ================================================== */

/* log error type */
typedef uint32_t logError_t;

/*
 * boolean type
 */
typedef enum {
   LOG_TRUE = 1,
   LOG_FALSE = 0
} logBool_t;

/*
 * log levels enumeration
 */
typedef enum {
   /* no logging */
   LOG_SILENT,
   /* basic logging used by error logging */
   LOG_BASIC,
   /* warning message */
   LOG_WARNING,
   /* an informal message */
   LOG_INFO,
   /* debug message */
   LOG_FINE,
   /* a detailed debug message */
   LOG_FINEST

} log_logLevel_t;


/*
 * output types
 */
typedef enum {
   /* standard output */
   STDOUT,
   /* standard error output */
   STDERROUT
   /* file output */
   FILEOUT,
   /* ringbuffer output */
   RBUFOUT,
   /* all output types */
   ALLOUT

} log_loggerType_t;


/* =========== PUBLIC PROTOTYPES =========================================== */

#endif /* header guard */
/* ========================== END OF FILE ================================== */

/*
 * vim settings, please do not remove!
 * vim:autoindent:filetype=c:syntax=c:
 * vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=75:formatoptions=croql:
 * vim600:foldmethod=syntax:
 */

