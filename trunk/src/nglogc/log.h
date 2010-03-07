

#ifndef __LOGC_LOG_H__
#define __LOGC_LOG_H__


/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "log_priv.h"
#include "logger.h"
#include "types.h"

/* =========== DEFINES ===================================================== */

#if __STDC_VERSION__ < 199901L
#if __GNUC__ >= 2
#define __func__ __FUNCTION__
#else
#define __func__ "<unknown>"
#endif
#endif

/*---------------------------------------------------------------------------*/
/*
 * prints error messages to given logger and log level
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
#define logc_logError(ident, level, err, formatStr, ...) \
   logc_logErrorTEMP__(ident, level, err, formatStr, ## __VA_ARGS__)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints error messages to given logger
 *
 * log level is LOG_BASIC, except if logger has log level LOG_SILENT error
 * messages will always be printed
 *
 * @param ident          in : identifier of the logger
 * @param error          in : error to log
 * @param formatStr      in : format string log message
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if formatStr is NULL
 *                       LOG_ERR_NOT_FOUND if the logger is not found
 *                       LOG_ERR_LEVEL not printed because of the log level
 *                       error types from newErrorRecord function
 */
#define logc_logErrorBasic(ident, err, formatStr, ...) \
   logc_logErrorBasicTEMP__(ident, err, formatStr, ## __VA_ARGS__)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints error messages to given logger
 *
 * log level is LOG_WARNING
 *
 * @param ident          in : identifier of the logger
 * @param error          in : error to log
 * @param formatStr      in : format string log message
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if formatStr is NULL
 *                       LOG_ERR_NOT_FOUND if the logger is not found
 *                       LOG_ERR_LEVEL not printed because of the log level
 *                       error types from newErrorRecord function
 */
#define logc_logErrorWarning(ident, err, formatStr, ...) \
   logc_logErrorWarningTEMP__(ident, err, formatStr, ## __VA_ARGS__)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints error messages to given logger
 *
 * log level is LOG_INFO
 *
 * @param ident          in : identifier of the logger
 * @param error          in : error to log
 * @param formatStr      in : format string log message
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if formatStr is NULL
 *                       LOG_ERR_NOT_FOUND if the logger is not found
 *                       LOG_ERR_LEVEL not printed because of the log level
 *                       error types from newErrorRecord function
 */
#define logc_logErrorInfo(ident, err, formatStr, ...) \
   logc_logErrorInfoTEMP__(ident, err, formatStr, ## __VA_ARGS__)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints error messages to given logger
 *
 * log level is LOG_FINE
 *
 * @param ident          in : identifier of the logger
 * @param error          in : error to log
 * @param formatStr      in : format string log message
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if formatStr is NULL
 *                       LOG_ERR_NOT_FOUND if the logger is not found
 *                       LOG_ERR_LEVEL not printed because of the log level
 *                       error types from newErrorRecord function
 */
#define logc_logErrorFine(ident, err, formatStr, ...) \
   logc_logErrorFineTEMP__(ident, err, formatStr, ## __VA_ARGS__)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints error messages to given logger
 *
 * log level is LOG_FINEST
 *
 * @param ident          in : identifier of the logger
 * @param error          in : error to log
 * @param formatStr      in : format string log message
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if formatStr is NULL
 *                       LOG_ERR_NOT_FOUND if the logger is not found
 *                       LOG_ERR_LEVEL not printed because of the log level
 *                       error types from newErrorRecord function
 */
#define logc_logErrorFinest(ident, err, formatStr, ...) \
   logc_logErrorFinestTEMP__(ident, err, formatStr, ## __VA_ARGS__)
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/*
 * prints log messages to given logger and log level
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
#define logc_log(ident, level, formatStr, ...) \
   logc_logTEMP__(ident, level, formatStr, ## __VA_ARGS__)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints log messages to given logger
 *
 * log level is LOG_BASIC
 *
 * @param ident          in : identifier of the logger
 * @param formatStr      in : format string log message
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if formatStr is NULL
 *                       LOG_ERR_NOT_FOUND if the logger is not found
 *                       LOG_ERR_LEVEL not printed because of the log level
 *                       error types from newLogRecord function
 */
#define logc_logBasic(ident, formatStr, ...) \
   logc_logBasicTEMP__(ident, formatStr, ## __VA_ARGS__)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints log messages to given logger
 *
 * log level is LOG_WARNING
 *
 * @param ident          in : identifier of the logger
 * @param formatStr      in : format string log message
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if formatStr is NULL
 *                       LOG_ERR_NOT_FOUND if the logger is not found
 *                       LOG_ERR_LEVEL not printed because of the log level
 *                       error types from newLogRecord function
 */
#define logc_logWarning(ident, formatStr, ...) \
   logc_logWarningTEMP__(ident, formatStr, ## __VA_ARGS__)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints log messages to given logger
 *
 * log level is LOG_INFO
 *
 * @param ident          in : identifier of the logger
 * @param formatStr      in : format string log message
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if formatStr is NULL
 *                       LOG_ERR_NOT_FOUND if the logger is not found
 *                       LOG_ERR_LEVEL not printed because of the log level
 *                       error types from newLogRecord function
 */
#define logc_logInfo(ident, formatStr, ...) \
   logc_logInfoTEMP__(ident, formatStr, ## __VA_ARGS__)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints log messages to given logger
 *
 * log level is LOG_FINE
 *
 * @param ident          in : identifier of the logger
 * @param formatStr      in : format string log message
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if formatStr is NULL
 *                       LOG_ERR_NOT_FOUND if the logger is not found
 *                       LOG_ERR_LEVEL not printed because of the log level
 *                       error types from newLogRecord function
 */
#define logc_logFine(ident, formatStr, ...) \
   logc_logFineTEMP__(ident, formatStr, ## __VA_ARGS__)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints log messages to given logger
 *
 * log level is LOG_FINEST
 *
 * @param ident          in : identifier of the logger
 * @param formatStr      in : format string log message
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if formatStr is NULL
 *                       LOG_ERR_NOT_FOUND if the logger is not found
 *                       LOG_ERR_LEVEL not printed because of the log level
 *                       error types from newLogRecord function
 */
#define logc_logFinest(ident, formatStr, ...) \
   logc_logFinestTEMP__(ident, formatStr, ## __VA_ARGS__)
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/*
 * prints data array described by descriptor to given logger and log level
 *
 * @param ident          in : identifier of the logger
 * @param level          in : log level of message
 * @param descriptor     in : descriptor of the array
 * @param array          in : data array
 * @param len            in : length of the data array
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if descriptor or array is NULL
 *                       LOG_ERR_NOT_FOUND if the logger is not found
 *                       LOG_ERR_LEVEL not printed because of the log level
 *                       error types from newArrayRecord function
 */
#define logc_logArray(ident, level, desc, array, len) \
   logc_logArrayTEMP__(ident, level, desc, array, len)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints data array described by descriptor to given logger
 *
 * log level is LOG_BASIC
 *
 * @param ident          in : identifier of the logger
 * @param descriptor     in : descriptor of the array
 * @param array          in : data array
 * @param len            in : length of the data array
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if descriptor or array is NULL
 *                       LOG_ERR_NOT_FOUND if the logger is not found
 *                       LOG_ERR_LEVEL not printed because of the log level
 *                       error types from newArrayRecord function
 */
#define logc_logArrayBasic(ident, desc, array, len) \
   logc_logArrayBasicTEMP__(ident, desc, array, len)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints data array described by descriptor to given logger
 *
 * log level is LOG_WARNING
 *
 * @param ident          in : identifier of the logger
 * @param descriptor     in : descriptor of the array
 * @param array          in : data array
 * @param len            in : length of the data array
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if descriptor or array is NULL
 *                       LOG_ERR_NOT_FOUND if the logger is not found
 *                       LOG_ERR_LEVEL not printed because of the log level
 *                       error types from newArrayRecord function
 */
#define logc_logArrayWarning(ident, desc, array, len) \
   logc_logArrayWarningTEMP__(ident, desc, array, len)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints data array described by descriptor to given logger
 *
 * log level is LOG_INFO
 *
 * @param ident          in : identifier of the logger
 * @param descriptor     in : descriptor of the array
 * @param array          in : data array
 * @param len            in : length of the data array
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if descriptor or array is NULL
 *                       LOG_ERR_NOT_FOUND if the logger is not found
 *                       LOG_ERR_LEVEL not printed because of the log level
 *                       error types from newArrayRecord function
 */
#define logc_logArrayInfo(ident, desc, array, len) \
   logc_logArrayInfoTEMP__(ident, desc, array, len)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints data array described by descriptor to given logger
 *
 * log level is LOG_FINE
 *
 * @param ident          in : identifier of the logger
 * @param descriptor     in : descriptor of the array
 * @param array          in : data array
 * @param len            in : length of the data array
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if descriptor or array is NULL
 *                       LOG_ERR_NOT_FOUND if the logger is not found
 *                       LOG_ERR_LEVEL not printed because of the log level
 *                       error types from newArrayRecord function
 */
#define logc_logArrayFine(ident, desc, array, len) \
   logc_logArrayFineTEMP__(ident, desc, array, len)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints data array described by descriptor to given logger
 *
 * log level is LOG_FINEST
 *
 * @param ident          in : identifier of the logger
 * @param descriptor     in : descriptor of the array
 * @param array          in : data array
 * @param len            in : length of the data array
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if descriptor or array is NULL
 *                       LOG_ERR_NOT_FOUND if the logger is not found
 *                       LOG_ERR_LEVEL not printed because of the log level
 *                       error types from newArrayRecord function
 */
#define logc_logArrayFinest(ident, desc, array, len) \
   logc_logArrayFinestTEMP__(ident, desc, array, len)
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/*
 * trace logger
 * loggs entering of a function
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
#define logc_logEnter(ident, functionname) \
   logc_logEnterTEMP__(ident, functionname)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * trace logger
 * loggs leaving of a function
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
#define logc_logLeave(ident, functionname) \
   logc_logLeaveTEMP__(ident, functionname)
/*---------------------------------------------------------------------------*/

/* =========== DATA TYPES ================================================== */
/* =========== PUBLIC PROTOTYPES =========================================== */

#endif /* header guard */
/* ========================== END OF FILE ================================== */

/*
 * vim settings, please do not remove!
 * vim:autoindent:filetype=c:syntax=c:
 * vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=75:formatoptions=croql:
 * vim600:foldmethod=syntax:
 */

