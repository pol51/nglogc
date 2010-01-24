

#ifndef __LOGC_LOG_H__
#define __LOGC_LOG_H__


/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "log_priv.h"
#include "logger.h"

/* =========== DEFINES ===================================================== */


/*---------------------------------------------------------------------------*/
/*
 * prints error messages to given logger
 *
 * log level is LOG_BASIC
 *
 * @param ident          in : identifier of the logger
 * @param err            in : error to log
 * @param formatStr      in : format string log message
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger err or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
 */
#define logc_logError(ident, err, formatStr, ...) \
   logc_logErrorTEMP__(ident, err, formatStr, ##args)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints error messages to given logger and log level
 *
 * @param ident          in : identifier of the logger
 * @param level          in : log level of message
 * @param err            in : error to log
 * @param formatStr      in : format string log message
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger err or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
 */
#define logc_logLevelError(ident, level, err, formatStr, ...) \
   logc_logLevelErrorTEMP__(ident, level, err, formatStr, ##args)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints error messages to given logger
 *
 * log level is LOG_WARNING
 *
 * @param ident          in : identifier of the logger
 * @param err            in : error to log
 * @param formatStr      in : format string log message
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger err or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
 */
#define logc_logErrorWarning(ident, err, formatStr, ...) \
   logc_logErrorWarningTEMP__(ident, err, formatStr, ##args)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints error messages to given logger
 *
 * log level is LOG_INFO
 *
 * @param ident          in : identifier of the logger
 * @param err            in : error to log
 * @param formatStr      in : format string log message
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger err or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
 */
#define logc_logErrorInfo(ident, err, formatStr, ...) \
   logc_logErrorInfoTEMP__(ident, err, formatStr, ##args)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints error messages to given logger
 *
 * log level is LOG_FINE
 *
 * @param ident          in : identifier of the logger
 * @param err            in : error to log
 * @param formatStr      in : format string log message
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger err or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
 */
#define logc_logErrorFine(ident, err, formatStr, ...) \
   logc_logErrorFineTEMP__(ident, err, formatStr, ##args)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints error messages to given logger
 *
 * log level is LOG_FINEST
 *
 * @param ident          in : identifier of the logger
 * @param err            in : error to log
 * @param formatStr      in : format string log message
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger err or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
 */
#define logc_logErrorFinest(ident, err, formatStr, ...) \
   logc_logErrorFinestTEMP__(ident, err, formatStr, ##args)
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/*
 * prints log messages to given logger and log level
 *
 * @param ident          in : identifier of the logger
 * @param level          in : log level of message
 * @param formatStr      in : format string log message
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger err or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
 */
#define logc_log(ident, level, formatStr, ...) \
   logc_logTEMP__(ident, level, formatStr, ##args)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints log messages to given logger
 *
 * log level is LOG_BASIC
 *
 * @param ident          in : identifier of the logger
 * @param formatStr      in : format string log message
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger err or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
 */
#define logc_logBasic(ident, formatStr, ...) \
   logc_logBasicTEMP__(ident, formatStr, ##args)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints log messages to given logger
 *
 * log level is LOG_WARNING
 *
 * @param ident          in : identifier of the logger
 * @param formatStr      in : format string log message
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger err or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
 */
#define logc_logWarning(ident, formatStr, ...) \
   logc_logWarningTEMP__(ident, formatStr, ##args)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints log messages to given logger
 *
 * log level is LOG_INFO
 *
 * @param ident          in : identifier of the logger
 * @param formatStr      in : format string log message
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger err or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
 */
#define logc_logInfo(ident, formatStr, ...) \
   logc_logInfoTEMP__(ident, formatStr, ##args)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints log messages to given logger
 *
 * log level is LOG_FINE
 *
 * @param ident          in : identifier of the logger
 * @param formatStr      in : format string log message
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger err or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
 */
#define logc_logFine(ident, formatStr, ...) \
   logc_logFineTEMP__(ident, formatStr, ##args)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints log messages to given logger
 *
 * log level is LOG_FINEST
 *
 * @param ident          in : identifier of the logger
 * @param formatStr      in : format string log message
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger err or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
 */
#define logc_logFinest(ident, formatStr, ...) \
   logc_logFinestTEMP__(ident, formatStr, ##args)
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/*
 * prints data array described by descriptor to given logger and log level
 *
 * @param ident          in : identifier of the logger
 * @param level          in : log level of message
 * @param desc           in : descriptor of the array
 * @param array          in : data array
 * @param len            in : length of the data array
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger err or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
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
 * @param desc           in : descriptor of the array
 * @param array          in : data array
 * @param len            in : length of the data array
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger err or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
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
 * @param desc           in : descriptor of the array
 * @param array          in : data array
 * @param len            in : length of the data array
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger err or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
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
 * @param desc           in : descriptor of the array
 * @param array          in : data array
 * @param len            in : length of the data array
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger err or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
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
 * @param desc           in : descriptor of the array
 * @param array          in : data array
 * @param len            in : length of the data array
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger err or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
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
 * @param desc           in : descriptor of the array
 * @param array          in : data array
 * @param len            in : length of the data array
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger err or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
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
 * format is: Enter 'formatStr'
 *
 * @param ident          in : identifier of the logger
 * @param functionName   in : name of the function
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger err or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
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
 * format is: Leave 'formatStr'
 *
 * @param ident          in : identifier of the logger
 * @param functionName   in : name of the function
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger err or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
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

