

#ifndef __LOGC_NFLF_LOG_H__
#define __LOGC_NFLF_LOG_H__


/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

/* =========== DEFINES ===================================================== */
/* =========== DATA TYPES ================================================== */
/* =========== PUBLIC PROTOTYPES =========================================== */

/*---------------------------------------------------------------------------*/
/*
 * prints error messages to given output type
 *
 * log level is LOG_BASIC, except if logger has log level LOG_SILENT error
 * messages will always be printed
 * DO NOT USE THIS FUNCTION DIRECTLY
 * USE THE DEFINITIONS IN LOG.H
 *
 * @param err            in : error to log
 * @param type           in : type of output
 * @param formatStr      in : format string log message
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger type or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
 */
logError_t
logc_logError_nflf_(
      logError_t err,
      log_loggerType_t type,
      const* char formatStr,
      ...
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints error messages to given log level and output type
 * DO NOT USE THIS FUNCTION DIRECTLY
 * USE THE DEFINITIONS IN LOG.H
 *
 * @param err            in : error to log
 * @param level          in : log level of message
 * @param type           in : type of output
 * @param formatStr      in : format string log message
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger type or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
 */
logError_t
logc_logLevelError_nflf_(
      logError_t err,
      log_logLevel_t level,
      log_loggerType_t type,
      const* char formatStr,
      ...
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints log messages to given log level and output type
 * DO NOT USE THIS FUNCTION DIRECTLY
 * USE THE DEFINITIONS IN LOG.H
 *
 * @param level          in : log level of message
 * @param type           in : type of output
 * @param formatStr      in : format string log message
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger type or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
 */
logError_t
logc_log_nflf_(
      log_logLevel_t level,
      log_loggerType_t type,
      const* char formatStr,
      ...
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints data array described by descriptor to given log level and
 * output type
 * DO NOT USE THIS FUNCTION DIRECTLY
 * USE THE DEFINITIONS IN LOG.H
 *
 * @param level          in : log level of message
 * @param type           in : type of output
 * @param descriptor     in : descriptor of the array
 * @param array          in : data array
 * @param len            in : length of the data array
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger type or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
 */
logError_t
logc_logArray_nflf_(
      log_logLevel_t level,
      log_loggerType_t type,
      const* char descriptor,
      const* uint8_t array,
      size_t len
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * trace logger
 * loggs entering of a function
 * DO NOT USE THIS FUNCTION DIRECTLY
 * USE THE DEFINITIONS IN LOG.H
 *
 * used to trace function calls
 * log level is LOG_FINEST
 * format is: Enter 'formatStr'
 *
 * @param type           in : type of output
 * @param functionName   in : name of the function
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger type or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
 */
logError_t
logc_logEnter_nflf_(
      log_loggerType_t type,
      const* char functionName
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * trace logger
 * loggs leaving of a function
 * DO NOT USE THIS FUNCTION DIRECTLY
 * USE THE DEFINITIONS IN LOG.H
 *
 * used to trace function calls
 * log level is LOG_FINEST
 * format is: Leave 'formatStr'
 *
 * @param type           in : type of output
 * @param functionName   in : name of the function
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger type or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
 */
logError_t
logc_logLeave_nflf_(
      log_loggerType_t type,
      const* char functionName
      );
/*---------------------------------------------------------------------------*/

#endif /* header guard */
/* ========================== END OF FILE ================================== */

/*
 * vim settings, please do not remove!
 * vim:autoindent:filetype=c:syntax=c:
 * vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=75:formatoptions=croql:
 * vim600:foldmethod=syntax:
 */

