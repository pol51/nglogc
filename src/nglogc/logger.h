

#ifndef __LOGC_LOGGGER_H__
#define __LOGC_LOGGGER_H__


/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "types.h"

/* =========== DEFINES ===================================================== */

/* =========== DATA TYPES ================================================== */

/* typedef for publisher function */
typedef logc_error_t (*publisher_t)(char* const message);

/* logger type */
struct logger_s {
   uint16_t id;
   logc_loggerType_t type;
   logc_logLevel_t level;
   logc_errRecordType_t errRecordType;
   logc_logRecordType_t logRecordType;
   publisher_t publisher;
};
typedef struct logger_s logger_t;

/* =========== PUBLIC PROTOTYPES =========================================== */

/*---------------------------------------------------------------------------*/
/*
 * initialisation of the logger
 *
 * @param ident          in : identifier of the logger
 * @param type           in : type of the logger which specifies the output type
 * @param level          in : sets the level of logging
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger type or level
 *                       LOG_ERR_MULTIPL if logger already exist
 */
logc_error_t
logc_registerLogger(
      uint16_t ident,
      logc_loggerType_t type,
      logc_logLevel_t level
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * removes the logger
 *
 * @param ident          in : identifier of the logger to remove
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger type
 */
logc_error_t
logc_removeLogger(
      uint16_t ident
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * changes the level of logging
 *
 * @param ident          in : identifier of the logger
 * @param level          in : new log level
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger type or level
 */
logc_error_t
logc_changeLogLevel(
      uint16_t ident,
      logc_logLevel_t level
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* TODO
 * set the log format for logging.
 *
 */
logc_error_t
logc_setLogFormat(
      uint16_t ident,
      logc_errRecordType_t errForm,
      logc_logRecordType_t logForm
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * set the filename for file logging
 *
 * @param ident          in : identifier of the logger
 * @param filename       in : name of log file <= MAX_FILENAME
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_LENGTH to long file name length
 */
logc_error_t
logc_setLogfile(
      uint16_t ident,
      const char* const filename
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * TODO should be private
 */
logger_t*
getLogger(
      uint16_t ident
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

