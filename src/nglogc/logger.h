

#ifndef __LOGC_LOGGGER_H__
#define __LOGC_LOGGGER_H__


/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "types.h"
#include "logger_type.h"

#include <stdio.h>

/* =========== DEFINES ===================================================== */
/* =========== DATA TYPES ================================================== */
/* =========== PUBLIC PROTOTYPES =========================================== */

/*---------------------------------------------------------------------------*/
/*
 * initialisation of a logger
 *
 * @param ident          in : identifier of the logger
 * @param type           in : type of the logger which specifies the output type
 * @param level          in : sets the log level
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_PARAM for invalid parameter
 *                       LOG_ERR_MEM if no memory could be allocated
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
 * removes a logger
 *
 * @param ident          in : identifier of the logger
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NOT_FOUND for invalid logger id
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
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_PARAM for invalid log level
 *                       LOG_ERR_NOT_FOUND for invalid logger id
 */
logc_error_t
logc_changeLogLevel(
      uint16_t ident,
      logc_logLevel_t level
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * set the log format for logging.
 *
 * @param ident          in : identifier of the logger
 * @param errForm        in : format of error logging
 * @param logForm        in : format of log logging
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_PARAM for invalid format types
 *                       LOG_ERR_NOT_FOUND for invalid logger id
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
 * @param filename       in : name of log file
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if filename is NULL
 *                       LOG_ERR_NOT_FOUND for invalid logger id
 *                       LOG_ERR_OPEN_FILE if file could not be opened
 */
logc_error_t
logc_setLogfile(
      uint16_t ident,
      const char* const filename
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

