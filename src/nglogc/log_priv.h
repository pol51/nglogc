

#ifndef __LOGC_LOG_PRIV_H__
#define __LOGC_LOG_PRIV_H__


/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "flf_log.h"
#include "nflf_log.h"

/* =========== DEFINES ===================================================== */

#if __STDC_VERSION__ < 199901L
#if __GNUC__ >= 2
#define __func__ __FUNCTION__
#else
#define __func__ "<unknown>"
#endif
#endif



#if defined (HAVE_FLF) || defined (HAVE_FLF_BASIC)
#define logc_logErrorTEMP__(ident, err, formatStr, ...) \
   logc_logError_flf_(__FILE__, __LINE__, __func__, ident, err, formatStr, ## __VA_ARGS__)
#else
#define logc_logErrorTEMP__(ident, err, formatStr, ...) \
   logc_logError_nflf_(ident, err, formatStr, ## __VA_ARGS__)
#endif


#if defined (HAVE_FLF)
#define logc_logLevelErrorTEMP__(ident, level, err, formatStr, ...) \
   logc_logLevelError_flf_(__FILE__, __LINE__, __func__, ident, level, err, formatStr, ## __VA_ARGS__)
#else
#define logc_logLevelErrorTEMP__(ident, level, err, formatStr, ...) \
   logc_logLevelError_nflf_(ident, level, err, formatStr, ## __VA_ARGS__)
#endif


#if defined (HAVE_FLF) || defined (HAVE_FLF_WARNING)
#define logc_logErrorWarningTEMP__(ident, err, formatStr, ...) \
   logc_logLevelError_flf_(__FILE__, __LINE__, __func__, ident, LOG_WARNING, err, formatStr, ## __VA_ARGS__)
#else
#define logc_logErrorWarningTEMP__(ident, err, formatStr, ...) \
   logc_logLevelError_nflf_(ident, LOG_WARNING, err, formatStr, ## __VA_ARGS__)
#endif


#if defined (HAVE_FLF) || defined (HAVE_FLF_INFO)
#define logc_logErrorInfoTEMP__(ident, err, formatStr, ...) \
   logc_logLevelError_flf_(__FILE__, __LINE__, __func__, ident, LOG_INFO, err, formatStr, ## __VA_ARGS__)
#else
#define logc_logErrorInfoTEMP__(ident, err, formatStr, ...) \
   logc_logLevelError_nflf_(ident, LOG_INFO, err, formatStr, ## __VA_ARGS__)
#endif


#if defined (HAVE_FLF) || defined (HAVE_FLF_FINE)
#define logc_logErrorFineTEMP__(ident, err, formatStr, ...) \
   logc_logLevelError_flf_(__FILE__, __LINE__, __func__, ident, LOG_FINE, err, formatStr, ## __VA_ARGS__)
#else
#define logc_logErrorFineTEMP__(ident, err, formatStr, ...) \
   logc_logLevelError_nflf_(ident, LOG_FINE, err, formatStr, ## __VA_ARGS__)
#endif


#if defined (HAVE_FLF) || defined (HAVE_FLF_FINEST)
#define logc_logErrorFinestTEMP__(ident, err, formatStr, ...) \
   logc_logLevelError_flf_(__FILE__, __LINE__, __func__, ident, LOG_FINEST, err, formatStr, ## __VA_ARGS__)
#else
#define logc_logErrorFinestTEMP__(ident, err, formatStr, ...) \
   logc_logLevelError_nflf_(ident, LOG_FINEST, err, formatStr, ## __VA_ARGS__)
#endif



#if defined (HAVE_FLF)
#define logc_logTEMP__(ident, level, formatStr, ...) \
   logc_log_flf_(__FILE__, __LINE__, __func__, ident, level, formatStr, ## __VA_ARGS__)
#else
#define logc_logTEMP__(ident, level, formatStr, ...) \
   logc_log_nflf_(ident, level, formatStr, ## __VA_ARGS__)
#endif

#if defined (HAVE_FLF) || defined (HAVE_FLF_BASIC)
#define logc_logBasicTEMP__(ident, formatStr, ...) \
   logc_log_flf_(__FILE__, __LINE__, __func__, ident, LOG_BASIC, formatStr, ## __VA_ARGS__)
#else
#define logc_logBasicTEMP__(ident, formatStr, ...) \
   logc_log_nflf_(ident, LOG_BASIC, formatStr, ## __VA_ARGS__)
#endif

#if defined (HAVE_FLF) || defined (HAVE_FLF_WARNING)
#define logc_logWarningTEMP_(ident, formatStr, ...) \
   logc_log_flf_(__FILE__, __LINE__, __func__, ident, LOG_WARNING, formatStr, ## __VA_ARGS__)
#else
#define logc_logWarningTEMP_(ident, formatStr, ...) \
   logc_log_nflf_(ident, LOG_WARNING, formatStr, ## __VA_ARGS__)
#endif


#if defined (HAVE_FLF) || defined (HAVE_FLF_INFO)
#define logc_logInfoTEMP_(ident, formatStr, ...) \
   logc_log_flf_(__FILE__, __LINE__, __func__, ident, LOG_INFO, formatStr, ## __VA_ARGS__)
#else
#define logc_logInfoTEMP_(ident, formatStr, ...) \
   logc_log_nflf_(ident, LOG_INFO, formatStr, ## __VA_ARGS__)
#endif


#if defined (HAVE_FLF) || defined (HAVE_FLF_FINE)
#define logc_logFineTEMP_(ident, formatStr, ...) \
   logc_log_flf_(__FILE__, __LINE__, __func__, ident, LOG_FINE, formatStr, ## __VA_ARGS__)
#else
#define logc_logFineTEMP_(ident, formatStr, ...) \
   logc_log_nflf_(ident, LOG_FINE, formatStr, ## __VA_ARGS__)
#endif


#if defined (HAVE_FLF) || defined (HAVE_FLF_FINEST)
#define logc_logFinestTEMP_(ident, formatStr, ...) \
   logc_log_flf_(__FILE__, __LINE__, __func__, ident, LOG_FINEST, formatStr, ## __VA_ARGS__)
#else
#define logc_logFinestTEMP_(ident, formatStr, ...) \
   logc_log_nflf_(ident, LOG_FINEST, formatStr, ## __VA_ARGS__)
#endif


#if defined (HAVE_FLF)
#define logc_logArrayTEMP__(ident, level, desc, array, len) \
   logc_logArray_flf_(__FILE__, __LINE__, __func__, ident, level, desc, array, len)
#else
#define logc_logArrayTEMP__(ident, level, desc, array, len) \
   logc_logArray_nflf_(ident, level, desc, array, len)
#endif


#if defined (HAVE_FLF) || defined (HAVE_FLF_BASIC)
#define logc_logArrayBasicTEMP__(ident, desc, array, len) \
   logc_logArray_flf_(__FILE__, __LINE__, __func__, ident, LOG_BASIC, desc, array, len)
#else
#define logc_logArrayBasicTEMP__(ident, desc, array, len) \
   logc_logArray_nflf_(ident, LOG_BASIC, desc, array, len)
#endif


#if defined (HAVE_FLF) || defined (HAVE_FLF_WARNING)
#define logc_logArrayWarningTEMP_(ident, desc, array, len) \
   logc_logArray_flf_(__FILE__, __LINE__, __func__, ident, LOG_WARNING, desc, array, len)
#else
#define logc_logArrayWarningTEMP_(ident, desc, array, len) \
   logc_logArray_nflf_(ident, LOG_WARNING, desc, array, len)
#endif


#if defined (HAVE_FLF) || defined (HAVE_FLF_INFO)
#define logc_logArrayInfoTEMP_(ident, desc, array, len) \
   logc_logArray_flf_(__FILE__, __LINE__, __func__, ident, LOG_INFO, desc, array, len)
#else
#define logc_logArrayInfoTEMP_(ident, desc, array, len) \
   logc_logArray_nflf_(ident, LOG_INFO, desc, array, len)
#endif


#if defined (HAVE_FLF) || defined (HAVE_FLF_FINE)
#define logc_logArrayFineTEMP_(ident, desc, array, len) \
   logc_logArray_flf_(__FILE__, __LINE__, __func__, ident, LOG_FINE, desc, array, len)
#else
#define logc_logArrayFineTEMP_(ident, desc, array, len) \
   logc_logArray_nflf_(ident, LOG_FINE, desc, array, len)
#endif


#if defined (HAVE_FLF) || defined (HAVE_FLF_FINEST)
#define logc_logArrayFinestTEMP_(ident, desc, array, len) \
   logc_logArray_flf_(__FILE__, __LINE__, __func__, ident, LOG_FINEST, desc, array, len)
#else
#define logc_logArrayFinestTEMP_(ident, desc, array, len) \
   logc_logArray_nflf_(ident, LOG_FINEST, desc, array, len)
#endif



#if defined (HAVE_FLF) || defined (HAVE_FLF_FINEST)
#define logc_logEnterTEMP_(ident, functionname) \
   logc_logEnter_flf_(__FILE__, __LINE__, __func__, ident, functionname)
#else
#define logc_logEnterTEMP_(ident, functionname) \
   logc_logEnter_nflf_(ident, functionname)
#endif


#if defined (HAVE_FLF) || defined (HAVE_FLF_FINEST)
#define logc_logLeaveTEMP_(ident, functionname) \
   logc_logLeave_flf_(__FILE__, __LINE__, __func__, ident, functionname)
#else
#define logc_logLeaveTEMP_(ident, functionname) \
   logc_logLeave_nflf_(ident, functionname)
#endif



/*
 * disable / enable
 * log info messages from info to warning
 */
#if defined (LOGC_DISABLE_WARNLOGS)

#define logc_logWarningTEMP__(ident, formatStr, ...)

#define logc_logInfoTEMP__(ident, formatStr, ...)

#define logc_logArrayWarningTEMP__(ident, desc, array, len)

#define logc_logArrayInfoTEMP__(ident, desc, array, len)

#else

#define logc_logWarningTEMP__(ident, formatStr, ...) \
   logc_logWarningTEMP_(ident, formatStr, ## __VA_ARGS__)

#define logc_logInfoTEMP__(ident, formatStr, ...) \
   logc_logInfoTEMP_(ident, formatStr, ## __VA_ARGS__)

#define logc_logArrayWarningTEMP__(ident, desc, array, len) \
   logc_logArrayWarningTEMP_(ident, desc, array, len)

#define logc_logArrayInfoTEMP__(ident, desc, array, len) \
   logc_logArrayInfoTEMP_(ident, desc, array, len)

#endif



/*
 * disable / enable
 * log info messages from fine to finest
 */
#if defined (LOGC_ENABLE_LOW_LEVEL)

#define logc_logFineTEMP__(ident, formatStr, ...) \
   logc_logFineTEMP_(ident, formatStr, ## __VA_ARGS__)

#define logc_logFinestTEMP__(ident, formatStr, ...) \
   logc_logFinestTEMP_(ident, formatStr, ## __VA_ARGS__)

#define logc_logArrayFineTEMP__(ident, desc, array, len) \
   logc_logArrayFineTEMP_(ident, desc, array, len)

#define logc_logArrayFinestTEMP__(ident, desc, array, len) \
   logc_logArrayFinestTEMP_(ident, desc, array, len)

#define logc_logEnterTEMP__(ident, functionname) \
   logc_logEnterTEMP_(ident, functionname)

#define logc_logLeaveTEMP__(ident, functionname) \
   logc_logLeaveTEMP_(ident, functionname)

#else

#define logc_logFineTEMP__(ident, formatStr, ...)

#define logc_logFinestTEMP__(ident, formatStr, ...)

#define logc_logArrayFineTEMP__(ident, desc, array, len)

#define logc_logArrayFinestTEMP__(ident, desc, array, len)

#define logc_logEnterTEMP__(ident, functionname)

#define logc_logLeaveTEMP__(ident, functionname)

#endif

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

