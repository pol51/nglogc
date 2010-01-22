

#ifndef __LOGC_LOGGGER_H__
#define __LOGC_LOGGGER_H__


/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

/* =========== DEFINES ===================================================== */

/* =========== DATA TYPES ================================================== */

/* =========== PUBLIC PROTOTYPES =========================================== */

/*---------------------------------------------------------------------------*/
/*
 * initialisation of the logger
 *
 * @param type           in : type of the logger which specifies the output type
 * @param level          in : sets the level of logging
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger type or level
 *                       LOG_ERR_MULTIPL if logger already exist
 */
logError_t
log_setLogger(
      log_loggerType_t type,
      log_logLevel_t level
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * removes the logger
 *
 * @param type           in : type of the logger to remove
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger type
 */
logError_t
log_removeLogger(
      log_loggerType_t type
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * changes the level of logging
 *
 * @param type           in : type of the logger
 * @param level          in : new log level
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger type or level
 */
logError_t
log_changeLogLevel(
      log_loggerType_t type,
      log_logLevel_t level
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * set the filename for file logging
 *
 * @param filename       in : name of log file <= MAX_FILENAME
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_LENGTH to long file name length
 */
logError_t
log_setLogfile(
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

