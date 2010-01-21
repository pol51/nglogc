

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









/*---------------------------------------------------------------------------*/
/*
 * initialisation of logging
 * open logfile, must be closed by log_clean call
 *
 * @param logfile        in : file name of loggingfile
 * @param loglevel         in : level of logging
 * @return logError_t     RET_OK for success or BASE_ERR_DATA
 */
logError_t
log_init(
      const char* logfile,
      logLevel_t logLevel
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * close the logging file
 * resets the values
 */
void
log_clean(
      void
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * error logging
 * write on standard output and loggingfile
 * no loglevel is needed
 *
 * @param err              in : error type (not used atm)
 * @param formatStr        in : format string
 */
void
log_error(
      logError_t err,
      const char* formatStr,
      ...
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * TODO depends on platform if this is needed
 * mutexed error logging
 * write on standard output and loggingfile
 * no loglevel is needed
 *
 * @param err              in : error type (not used atm)
 * @param formatStr        in : format string
 */
void
log_errorMutexed(
      logError_t,
      const char* formatStr,
      ...
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * stdout printer logger
 * writes only on standard output
 * if param log level is equal or less than the privat log level
 *
 * @param level            in : log level for this log
 * @param formatStr        in : format string
 */
void
log_printOut(
      logLevel_t level,
      const char* formatStr,
      ...
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * TODO depends on platform if this is needed
 * mutexed stdout printer logger
 * writes only on standard output
 * if param log level is equal or less than the privat log level
 *
 * @param level            in : log level for this log
 * @param formatStr        in : format string
 */
void
log_printOutMutexed(
      logLevel_t level,
      const char* formatStr,
      ...
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * info logger
 * write on standard output and loggingfile
 * if param log level is equal or less than the privat log level
 *
 * @param level            in : log level for this log
 * @param formatStr        in : format string
 */
void
log_info(
      logLevel_t level,
      const char* formatStr,
      ...
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * TODO depends on platform if this is needed
 * mutexed info logger
 * write on standard output and loggingfile
 * if param log level is equal or less than the privat log level
 *
 * @param level            in : log level for this log
 * @param formatStr        in : format string
 */
void
log_infoMutexed(
      logLevel_t level,
      const char* formatStr,
      ...
      );
/*---------------------------------------------------------------------------*/

#ifdef DEBUG
/*---------------------------------------------------------------------------*/
/*
 * debug logger
 * writes only on standard output
 *
 * @param formatStr        in : format string
 */
void
log_debug(
      const char* formatStr,
      ...
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * TODO depends on platform if this is needed
 * debug logger
 * writes only on standard output
 *
 * @param formatStr        in : format string
 */
void
log_debugMutexed(
      const char* formatStr,
      ...
      );
/*---------------------------------------------------------------------------*/
#endif /* ifdef DEBUG */

#endif
/* ========================== END OF FILE ================================== */

/*
 * vim settings, please do not remove!
 * vim:autoindent:filetype=c:syntax=c:
 * vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=75:formatoptions=croql:
 * vim600:foldmethod=syntax:
 */

