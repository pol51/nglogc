

#ifndef __LOGC_LOG_H__
#define __LOGC_LOG_H__


/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "log_priv.h"

/* =========== DEFINES ===================================================== */


/*---------------------------------------------------------------------------*/
/*
 * prints error messages to given output type
 *
 * log level is LOG_BASIC, except if logger has log level LOG_SILENT error
 * messages will always be printed
 *
 * @param err            in : error to log
 * @param type           in : type of output
 * @param formatStr      in : format string log message
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger type or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
 */
#define logc_logError(err, type, formatStr, args...) \
   logc_logErrorTEMP__(err, type, formatStr, ##args)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints error messages to given log level and output type
 *
 * @param err            in : error to log
 * @param level          in : log level of message
 * @param type           in : type of output
 * @param formatStr      in : format string log message
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger type or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
 */
#define logc_logLevelError(err, level, type, formatStr, args...) \
   logc_logLevelErrorTEMP__(err, level, type, formatStr, ##args)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints error messages to given output type
 *
 * log level is LOG_WARNING
 *
 * @param err            in : error to log
 * @param type           in : type of output
 * @param formatStr      in : format string log message
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger type or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
 */
#define logc_logErrorWarning(err, type, formatStr, args...) \
   logc_logErrorWarningTEMP__(err, WARNING, type, formatStr, ##args)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints error messages to given output type
 *
 * log level is LOG_INFO
 *
 * @param err            in : error to log
 * @param type           in : type of output
 * @param formatStr      in : format string log message
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger type or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
 */
#define logc_logErrorInfo(err, type, formatStr, args...) \
   logc_logErrorInfoTEMP__(err, type, formatStr, ##args)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints error messages to given output type
 *
 * log level is LOG_FINE
 *
 * @param err            in : error to log
 * @param type           in : type of output
 * @param formatStr      in : format string log message
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger type or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
 */
#define logc_logErrorFine(err, type, formatStr, args...) \
   logc_logErrorFineTEMP__(err, type, formatStr, ##args)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints error messages to given output type
 *
 * log level is LOG_FINEST
 *
 * @param err            in : error to log
 * @param type           in : type of output
 * @param formatStr      in : format string log message
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger type or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
 */
#define logc_logErrorFinest(err, type, formatStr, args...) \
   logc_logErrorFinestTEMP__(err, type, formatStr, ##args)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints log messages to given log level and output type
 *
 * @param level          in : log level of message
 * @param type           in : type of output
 * @param formatStr      in : format string log message
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger type or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
 */
#define logc_log(level, type, formatStr, args...) \
   logc_logTEMP__(level, type, formatStr, ##args)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints log messages to given output type
 *
 * log level is LOG_BASIC
 *
 * @param type           in : type of output
 * @param formatStr      in : format string log message
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger type or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
 */
#define logc_logBasic(type, formatStr, args...) \
   logc_logBasicTEMP__(type, formatStr, ##args)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints log messages to given output type
 *
 * log level is LOG_WARNING
 *
 * @param type           in : type of output
 * @param formatStr      in : format string log message
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger type or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
 */
#define logc_logWarning(type, formatStr, args...) \
   logc_logWarningTEMP__(type, formatStr, ##args)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints log messages to given output type
 *
 * log level is LOG_INFO
 *
 * @param type           in : type of output
 * @param formatStr      in : format string log message
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger type or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
 */
#define logc_logInfo(type, formatStr, args...) \
   logc_logInfoTEMP__(type, formatStr, ##args)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints log messages to given output type
 *
 * log level is LOG_FINE
 *
 * @param type           in : type of output
 * @param formatStr      in : format string log message
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger type or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
 */
#define logc_logFine(type, formatStr, args...) \
   logc_logFineTEMP__(type, formatStr, ##args)

#define logc_logFinest(type, formatStr, args...) \
   logc_logFinestTEMP__(type, formatStr, ##args)
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/*
 * prints data array described by descriptor to given log level and
 * output type
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
#define logc_logArray(level, type, desc, array, len) \
   logc_logArrayTEMP__(level, type, desc, array, len)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints data array described by descriptor to given output type
 *
 * log level is LOG_BASIC
 *
 * @param type           in : type of output
 * @param descriptor     in : descriptor of the array
 * @param array          in : data array
 * @param len            in : length of the data array
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger type or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
 */
#define logc_logArrayBasic(type, desc, array, len) \
   logc_logArrayBasicTEMP__(type, desc, array, len)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints data array described by descriptor to given output type
 *
 * log level is LOG_WARNING
 *
 * @param type           in : type of output
 * @param descriptor     in : descriptor of the array
 * @param array          in : data array
 * @param len            in : length of the data array
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger type or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
 */
#define logc_logArrayWarning(type, desc, array, len) \
   logc_logArrayWarningTEMP__(type, desc, array, len)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints data array described by descriptor to given output type
 *
 * log level is LOG_INFO
 *
 * @param type           in : type of output
 * @param descriptor     in : descriptor of the array
 * @param array          in : data array
 * @param len            in : length of the data array
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger type or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
 */
#define logc_logArrayInfo(type, desc, array, len) \
   logc_logArrayInfoTEMP__(type, desc, array, len)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints data array described by descriptor to given output type
 *
 * log level is LOG_FINE
 *
 * @param type           in : type of output
 * @param descriptor     in : descriptor of the array
 * @param array          in : data array
 * @param len            in : length of the data array
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger type or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
 */
#define logc_logArrayFine(type, desc, array, len) \
   logc_logArrayFineTEMP__(type, desc, array, len)
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * prints data array described by descriptor to given output type
 *
 * log level is LOG_FINE
 *
 * @param type           in : type of output
 * @param descriptor     in : descriptor of the array
 * @param array          in : data array
 * @param len            in : length of the data array
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger type or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
 */
#define logc_logArrayFinest(type, desc, array, len) \
   logc_logArrayFinestTEMP__(type, desc, array, len)
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
 * @param type           in : type of output
 * @param functionName   in : name of the function
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger type or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
 */
#define logc_logEnter(type, functionname) \
   logc_logEnterTEMP__(type, functionname)
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
 * @param type           in : type of output
 * @param functionName   in : name of the function
 * @return logError_t    LOG_ERR_OK for success
 *                       LOG_ERR_DATA for invalid logger type or level
 *                       LOG_ERR_MULTIPL if logger already exist TODO
 */
#define logc_logLeave(type, functionname) \
   logc_logLeaveTEMP__(type, functionname)
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

