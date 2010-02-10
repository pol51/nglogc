

#ifndef __LOGC_TYPES_H__
#define __LOGC_TYPES_H__


/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdint.h>

/* =========== DEFINES ===================================================== */

#define LOG_ERR_OK               0x00000000

#define LOG_ERR_DATA             0x00001001

#define LOG_ERR_PARAM            0x00001002

#define LOG_ERR_MEM              0x00001003

#define LOG_ERR_NOT_FOUND        0x00001004

#define LOG_ERR_LEVEL            0x00001005

#define LOG_ERR_NULL             0x00001006

#define LOG_ERR_OPEN_FILE        0x00001007

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
   /* basic logging used by error logging */
   LOG_BASIC,
   /* warning message */
   LOG_WARNING,
   /* an informal message */
   LOG_INFO,
   /* debug message */
   LOG_FINE,
   /* a detailed debug message */
   LOG_FINEST,
   /* no logging */
   LOG_SILENT

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

#endif /* header guard */
/* ========================== END OF FILE ================================== */

/*
 * vim settings, please do not remove!
 * vim:autoindent:filetype=c:syntax=c:
 * vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=75:formatoptions=croql:
 * vim600:foldmethod=syntax:
 */

