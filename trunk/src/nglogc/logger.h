

#ifndef __LOGC_LOGGGER_H__
#define __LOGC_LOGGGER_H__


/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "types.h"

/* =========== DEFINES ===================================================== */

#if 0
#define MAX_LOGGER   32
logc_setLogger("main_logger", FILEOUT, WARNING);

logc_setLogfile("main_logger", "/etc/var/my_log.log");

logc_logErrorLevel("main_logger", WARNING, "while allocating memory");

logc_logErrorInfo("main_logger", "while allocating memory");

logc_logErrorInfo(main_log, "while allocating memory");

logc_removeLogger("main_logger");


#define LOG_MAIN   0x0001

logc_setLogger(LOG_MAIN, FILEOUT, WARNING);

logc_setLogfile(LOG_MAIN, "/etc/var/my_log.log");

logc_logErrorLevel(LOG_MAIN, WARNING, "while allocating memory");

logc_logErrorInfo(LOG_MAIN, "while allocating memory");
#endif
/* =========== DATA TYPES ================================================== */

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
logError_t
logc_registerLogger(
      uint16_t ident,
      log_loggerType_t type,
      log_logLevel_t level
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
logError_t
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
logError_t
logc_changeLogLevel(
      uint16_t ident,
      log_logLevel_t level
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
logError_t
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

