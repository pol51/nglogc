

#ifndef __LOGC_NFLF_LOG_H__
#define __LOGC_NFLF_LOG_H__


/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "types.h"
#include "string.h"

/* =========== DEFINES ===================================================== */
/* =========== DATA TYPES ================================================== */
/* =========== PUBLIC PROTOTYPES =========================================== */

/*---------------------------------------------------------------------------*/
/*
 * prints error messages to given logger and log level
 * DO NOT USE THIS FUNCTION DIRECTLY
 * USE THE DEFINITIONS IN LOG.H
 *
 * @param ident          in : identifier of the logger
 * @param level          in : log level of message
 * @param error          in : error to log
 * @param formatStr      in : format string log message
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if formatStr is NULL
 *                       LOG_ERR_NOT_FOUND if the logger is not found
 *                       LOG_ERR_LEVEL not printed because of the log level
 *                       error types from newErrorRecord function
 */
logc_error_t
logc_logError_nflf_(
      uint16_t ident,
      logc_logLevel_t level,
      logc_error_t error,
      const char* formatStr,
      ...
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints log messages to given logger and log level
 * DO NOT USE THIS FUNCTION DIRECTLY
 * USE THE DEFINITIONS IN LOG.H
 *
 * @param ident          in : identifier of the logger
 * @param level          in : log level of message
 * @param formatStr      in : format string log message
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if formatStr is NULL
 *                       LOG_ERR_NOT_FOUND if the logger is not found
 *                       LOG_ERR_LEVEL not printed because of the log level
 *                       error types from newLogRecord function
 */
logc_error_t
logc_log_nflf_(
      uint16_t ident,
      logc_logLevel_t level,
      const char* formatStr,
      ...
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints data array described by descriptor to given logger and log level
 * DO NOT USE THIS FUNCTION DIRECTLY
 * USE THE DEFINITIONS IN LOG.H
 *
 * @param ident          in : identifier of the logger
 * @param level          in : log level of message
 * @param descriptor     in : descriptor of the array
 * @param array          in : data array
 * @param len            in : length of the data array
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if formatStr is NULL
 *                       LOG_ERR_NOT_FOUND if the logger is not found
 *                       LOG_ERR_LEVEL not printed because of the log level
 *                       error types from newArrayRecord function
 */
logc_error_t
logc_logArray_nflf_(
      uint16_t ident,
      logc_logLevel_t level,
      const char* descriptor,
      const uint8_t* array,
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
 *
 * @param ident          in : identifier of the logger
 * @param functionName   in : name of the function
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if formatStr is NULL
 *                       LOG_ERR_NOT_FOUND if the logger is not found
 *                       LOG_ERR_LEVEL not printed because of the log level
 *                       LOG_ERR_MEM if needed memory could not be
 *                       allocated
 */
logc_error_t
logc_logEnter_nflf_(
      uint16_t ident,
      const char* functionName
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
 *
 * @param ident          in : identifier of the logger
 * @param functionName   in : name of the function
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if formatStr is NULL
 *                       LOG_ERR_NOT_FOUND if the logger is not found
 *                       LOG_ERR_LEVEL not printed because of the log level
 *                       LOG_ERR_MEM if needed memory could not be
 *                       allocated
 */
logc_error_t
logc_logLeave_nflf_(
      uint16_t ident,
      const char* functionName
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

