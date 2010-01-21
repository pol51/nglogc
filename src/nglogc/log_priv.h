

#ifndef __LOGC_LOG_H__
#define __LOGC_LOG_H__


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


#if defined (HAVE_FLF) || if defined (HAVE_FLF_BASIC)
#define logc_logErrorTEMP_(err, type, formatStr, args...) \
   logc_logError_flf_(__FILE__, __LINE__, __func__, err, type, formatStr, ##args)
#else
#define logc_logErrorTEMP_(err, type, formatStr, args...) \
   logc_logError_nflf_(err, type, formatStr, ##args)
#endif


#if defined (HAVE_FLF)
#define logc_logLevelErrorTEMP_(err, level, type, formatStr, args...) \
   logc_logLevelError_flf_(__FILE__, __LINE__, __func__, err, level, type, formatStr, ##args)
#else
#define logc_logLevelErrorTEMP_(err, type, formatStr, args...) \
   logc_logLevelError_nflf_(err, level, type, formatStr, ##args)
#endif


#if defined (HAVE_FLF) || if defined (HAVE_FLF_WARNING)
#define logc_logErrorWarningTEMP_(err, type, formatStr, args...) \
   logc_logLevelError_flf_(__FILE__, __LINE__, __func__, err, WARNING, type, formatStr, ##args)
#else
#define logc_logErrorWarningTEMP_(err, type, formatStr, args...) \
   logc_logLevelError_nflf_(err, WARNING, type, formatStr, ##args)
#endif


#if defined (HAVE_FLF) || if defined (HAVE_FLF_INFO)
#define logc_logErrorInfoTEMP_(err, type, formatStr, args...) \
   logc_logLevelError_flf_(__FILE__, __LINE__, __func__, err, INFO, type, formatStr, ##args)
#else
#define logc_logErrorInfoTEMP_(err, type, formatStr, args...) \
   logc_logLevelError_nflf_(err, INFO, type, formatStr, ##args)
#endif


#if defined (HAVE_FLF) || if defined (HAVE_FLF_FINE)
#define logc_logErrorFineTEMP_(err, type, formatStr, args...) \
   logc_logLevelError_flf_(__FILE__, __LINE__, __func__, err, FINE, type, formatStr, ##args)
#else
#define logc_logErrorFineTEMP_(err, type, formatStr, args...) \
   logc_logLevelError_nflf_(err, FINE, type, formatStr, ##args)
#endif


#if defined (HAVE_FLF) || if defined (HAVE_FLF_FINEST)
#define logc_logErrorFinestTEMP_(err, type, formatStr, args...) \
   logc_logLevelError_flf_(__FILE__, __LINE__, __func__, err, FINEST, type, formatStr, ##args)
#else
#define logc_logErrorFinestTEMP_(err, type, formatStr, args...) \
   logc_logLevelError_nflf_(err, FINEST, type, formatStr, ##args)
#endif



#if defined (HAVE_FLF)
#define logc_logTEMP_(level, type, formatStr, args...) \
   logc_log_flf_(__FILE__, __LINE__, __func__, level, type, formatStr, ##args)
#else
#define logc_logTEMP_(level, type, formatStr, args...) \
   logc_log_nflf_(level, type, formatStr, ##args)
#endif


#if defined (HAVE_FLF) || if defined (HAVE_FLF_BASIC)
#define logc_logBasicTEMP_(type, formatStr, args...) \
   logc_log_flf_(__FILE__, __LINE__, __func__, BASIC, type, formatStr, ##args)
#else
#define logc_logBasicTEMP_(type, formatStr, args...) \
   logc_log_nflf_(BASIC, type, formatStr, ##args)
#endif


#if defined (HAVE_FLF) || if defined (HAVE_FLF_WARNING)
#define logc_logWarningTEMP_(type, formatStr, args...) \
   logc_log_flf_(__FILE__, __LINE__, __func__, WARNING, type, formatStr, ##args)
#else
#define logc_logWarningTEMP_(type, formatStr, args...) \
   logc_log_nflf_(WARNING, type, formatStr, ##args)
#endif


#if defined (HAVE_FLF) || if defined (HAVE_FLF_INFO)
#define logc_logInfoTEMP_(type, formatStr, args...) \
   logc_log_flf_(__FILE__, __LINE__, __func__, INFO, type, formatStr, ##args)
#else
#define logc_logInfoTEMP_(type, formatStr, args...) \
   logc_log_nflf_(INFO, type, formatStr, ##args)
#endif


#if defined (HAVE_FLF) || if defined (HAVE_FLF_FINE)
#define logc_logFineTEMP_(type, formatStr, args...) \
   logc_log_flf_(__FILE__, __LINE__, __func__, FINE, type, formatStr, ##args)
#else
#define logc_logFineTEMP_(type, formatStr, args...) \
   logc_log_nflf_(FINE, type, formatStr, ##args)
#endif


#if defined (HAVE_FLF) || if defined (HAVE_FLF_FINEST)
#define logc_logFinestTEMP_(type, formatStr, args...) \
   logc_log_flf_(__FILE__, __LINE__, __func__, FINEST, type, formatStr, ##args)
#else
#define logc_logFinestTEMP_(type, formatStr, args...) \
   logc_log_nflf_(FINEST, type, formatStr, ##args)
#endif


#if defined (HAVE_FLF)
#define logc_logArrayTEMP_(level, type, desc, array, len) \
   logc_logArray_flf_(__FILE__, __LINE__, __func__, level, type, desc, array, len)
#else
#define logc_logArrayTEMP_(level, type, desc, array, len) \
   logc_logArray_nflf_(level, type, desc, array, len)
#endif


#if defined (HAVE_FLF) || if defined (HAVE_FLF_BASIC)
#define logc_logArrayBasicTEMP_(type, desc, array, len) \
   logc_logArray_flf_(__FILE__, __LINE__, __func__, BASIC, type, desc, array, len)
#else
#define logc_logArrayBasicTEMP_(type, desc, array, len) \
   logc_logArray_nflf_(BASIC, type, desc, array, len)
#endif


#if defined (HAVE_FLF) || if defined (HAVE_FLF_WARNING)
#define logc_logArrayWarningTEMP_(type, desc, array, len) \
   logc_logArray_flf_(__FILE__, __LINE__, __func__, WARNING, type, desc, array, len)
#else
#define logc_logArrayWarningTEMP_(type, desc, array, len) \
   logc_logArray_nflf_(WARNING, type, desc, array, len)
#endif


#if defined (HAVE_FLF) || if defined (HAVE_FLF_INFO)
#define logc_logArrayInfoTEMP_(type, desc, array, len) \
   logc_logArray_flf_(__FILE__, __LINE__, __func__, INFO, type, desc, array, len)
#else
#define logc_logArrayInfoTEMP_(type, desc, array, len) \
   logc_logArray_nflf_(INFO, type, desc, array, len)
#endif


#if defined (HAVE_FLF) || if defined (HAVE_FLF_FINE)
#define logc_logArrayFineTEMP_(type, desc, array, len) \
   logc_logArray_flf_(__FILE__, __LINE__, __func__, FINE, type, desc, array, len)
#else
#define logc_logArrayFineTEMP_(type, desc, array, len) \
   logc_logArray_nflf_(FINE, type, desc, array, len)
#endif


#if defined (HAVE_FLF) || if defined (HAVE_FLF_FINEST)
#define logc_logArrayFinestTEMP_(type, desc, array, len) \
   logc_logArray_flf_(__FILE__, __LINE__, __func__, FINEST, type, desc, array, len)
#else
#define logc_logArrayFinestTEMP_(type, desc, array, len) \
   logc_logArray_nflf_(FINEST, type, desc, array, len)
#endif



#if defined (HAVE_FLF) || if defined (HAVE_FLF_FINEST)
#define logc_logEnterTEMP_(type, functionname) \
   logc_logEnter_flf_(__FILE__, __LINE__, __func__, type, functionname)
#else
#define logc_logEnterTEMP_(type, functionname) \
   logc_logEnter_nflf_(type, functionname)
#endif


#if defined (HAVE_FLF) || if defined (HAVE_FLF_FINEST)
#define logc_logLeaveTEMP_(type, functionname) \
   logc_logLeave_flf_(__FILE__, __LINE__, __func__, type, functionname)
#else
#define logc_logLeaveTEMP_(type, functionname) \
   logc_logLeave_nflf_(type, functionname)
#endif

------------------------------------------------------------------------------------------------

#if defined (LOGC_DISABLE_WARNLOGS)

#define logc_logWarningTEMP__(type, formatStr, args...)

#define logc_logInfoTEMP__(type, formatStr, args...)

#define logc_logArrayWarningTEMP__(type, desc, array, len)

#define logc_logArrayInfoTEMP__(type, desc, array, len)

#else

#define logc_logWarningTEMP__(type, formatStr, args...) \
   logc_logWarningTEMP_(type, formatStr, ##args)

#define logc_logInfoTEMP__(type, formatStr, args...) \
   logc_logInfoTEMP_(type, formatStr, ##args)

#define logc_logArrayWarningTEMP__(type, desc, array, len) \
   logc_logArrayWarningTEMP_(type, desc, array, len)

#define logc_logArrayInfoTEMP__(type, desc, array, len) \
   logc_logArrayInfoTEMP_(type, desc, array, len)

#endif


#if defined (LOGC_ENABLE_LOW_LEVEL)

#define logc_logFineTEMP__(type, formatStr, args...)

#define logc_logFinestTEMP__(type, formatStr, args...)

#define logc_logArrayFineTEMP__(type, desc, array, len)

#define logc_logArrayFinestTEMP__(type, desc, array, len)

#define logc_logEnterTEMP__(type, functionname)

#define logc_logLeaveTEMP__(type, functionname)

#else

#define logc_logFineTEMP__(type, formatStr, args...) \
   logc_logFineTEMP_(type, formatStr, ##args)

#define logc_logFinestTEMP__(type, formatStr, args...) \
   logc_logFinestTEMP_(type, formatStr, ##args)

#define logc_logArrayFineTEMP__(type, desc, array, len) \
   logc_logArrayFineTEMP_(type, desc, array, len)

#define logc_logArrayFinestTEMP__(type, desc, array, len) \
   logc_logArrayFinestTEMP_(type, desc, array, len)

#define logc_logEnterTEMP__(type, functionname) \
   logc_logEnterTEMP_(type, functionname)

#define logc_logLeaveTEMP__(type, functionname) \
   logc_logLeaveTEMP_(type, functionname)

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

