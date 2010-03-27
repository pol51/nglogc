
/******************************************************************************
 *
 * nglogc - Flexible C Logging API
 *
 * Author:        Dennis Krzyzaniak
 * E-mail:        ebrosius@netgarage.org
 * WWW:           http://www.netgarage.org
 * Copyright (C): 2010 by Dennis Krzyzaniak
 *
 * This file is part of nglogc.
 *
 * nglogc is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * nglogc is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser Public License for more details.
 *
 * You should have received a copy of the GNU Lesser Public License
 * along with nglogc.  If not, see <http://www.gnu.org/licenses/>.
 *
 *****************************************************************************/

#ifndef __LOGC_LOG_PRIV_H__
#define __LOGC_LOG_PRIV_H__


/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "flf_log.h"
#include "flf_logtrace.h"
#include "nflf_log.h"
#include "nflf_logtrace.h"

#ifdef __cplusplus
extern "C" {
#endif /* ifdef __cplusplus */

/* =========== DEFINES ===================================================== */

#if __STDC_VERSION__ < 199901L
#if __GNUC__ >= 2
#define __func__ __FUNCTION__
#else
#define __func__ "<unknown>"
#endif
#endif




#if defined (LOGC_HAVE_FLF)
#define logc_logErrorTEMP__(ident, level, err, formatStr, ...) \
   logc_logError_flf_(__FILE__, __LINE__, __func__, ident, level, err, formatStr, ## __VA_ARGS__)
#else
#define logc_logErrorTEMP__(ident, level, err, formatStr, ...) \
   logc_logError_nflf_(ident, level, err, formatStr, ## __VA_ARGS__)
#endif


#if defined (LOGC_HAVE_FLF) || defined (LOGC_HAVE_FLF_BASIC)
#define logc_logErrorBasicTEMP__(ident, err, formatStr, ...) \
   logc_logError_flf_(__FILE__, __LINE__, __func__, ident, LOG_BASIC, err, formatStr, ## __VA_ARGS__)
#else
#define logc_logErrorBasicTEMP__(ident, err, formatStr, ...) \
   logc_logError_nflf_(ident, LOG_BASIC, err, formatStr, ## __VA_ARGS__)
#endif


#if defined (LOGC_HAVE_FLF) || defined (LOGC_HAVE_FLF_WARNING)
#define logc_logErrorWarningTEMP_(ident, err, formatStr, ...) \
   logc_logError_flf_(__FILE__, __LINE__, __func__, ident, LOG_WARNING, err, formatStr, ## __VA_ARGS__)
#else
#define logc_logErrorWarningTEMP_(ident, err, formatStr, ...) \
   logc_logError_nflf_(ident, LOG_WARNING, err, formatStr, ## __VA_ARGS__)
#endif


#if defined (LOGC_HAVE_FLF) || defined (LOGC_HAVE_FLF_INFO)
#define logc_logErrorInfoTEMP_(ident, err, formatStr, ...) \
   logc_logError_flf_(__FILE__, __LINE__, __func__, ident, LOG_INFO, err, formatStr, ## __VA_ARGS__)
#else
#define logc_logErrorInfoTEMP_(ident, err, formatStr, ...) \
   logc_logError_nflf_(ident, LOG_INFO, err, formatStr, ## __VA_ARGS__)
#endif


#if defined (LOGC_HAVE_FLF) || defined (LOGC_HAVE_FLF_FINE)
#define logc_logErrorFineTEMP_(ident, err, formatStr, ...) \
   logc_logError_flf_(__FILE__, __LINE__, __func__, ident, LOG_FINE, err, formatStr, ## __VA_ARGS__)
#else
#define logc_logErrorFineTEMP_(ident, err, formatStr, ...) \
   logc_logError_nflf_(ident, LOG_FINE, err, formatStr, ## __VA_ARGS__)
#endif


#if defined (LOGC_HAVE_FLF) || defined (LOGC_HAVE_FLF_FINEST)
#define logc_logErrorFinestTEMP_(ident, err, formatStr, ...) \
   logc_logError_flf_(__FILE__, __LINE__, __func__, ident, LOG_FINEST, err, formatStr, ## __VA_ARGS__)
#else
#define logc_logErrorFinestTEMP_(ident, err, formatStr, ...) \
   logc_logError_nflf_(ident, LOG_FINEST, err, formatStr, ## __VA_ARGS__)
#endif



#if defined (LOGC_HAVE_FLF)
#define logc_logTEMP__(ident, level, formatStr, ...) \
   logc_log_flf_(__FILE__, __LINE__, __func__, ident, level, formatStr, ## __VA_ARGS__)
#else
#define logc_logTEMP__(ident, level, formatStr, ...) \
   logc_log_nflf_(ident, level, formatStr, ## __VA_ARGS__)
#endif

#if defined (LOGC_HAVE_FLF) || defined (LOGC_HAVE_FLF_BASIC)
#define logc_logBasicTEMP__(ident, formatStr, ...) \
   logc_log_flf_(__FILE__, __LINE__, __func__, ident, LOG_BASIC, formatStr, ## __VA_ARGS__)
#else
#define logc_logBasicTEMP__(ident, formatStr, ...) \
   logc_log_nflf_(ident, LOG_BASIC, formatStr, ## __VA_ARGS__)
#endif

#if defined (LOGC_HAVE_FLF) || defined (LOGC_HAVE_FLF_WARNING)
#define logc_logWarningTEMP_(ident, formatStr, ...) \
   logc_log_flf_(__FILE__, __LINE__, __func__, ident, LOG_WARNING, formatStr, ## __VA_ARGS__)
#else
#define logc_logWarningTEMP_(ident, formatStr, ...) \
   logc_log_nflf_(ident, LOG_WARNING, formatStr, ## __VA_ARGS__)
#endif


#if defined (LOGC_HAVE_FLF) || defined (LOGC_HAVE_FLF_INFO)
#define logc_logInfoTEMP_(ident, formatStr, ...) \
   logc_log_flf_(__FILE__, __LINE__, __func__, ident, LOG_INFO, formatStr, ## __VA_ARGS__)
#else
#define logc_logInfoTEMP_(ident, formatStr, ...) \
   logc_log_nflf_(ident, LOG_INFO, formatStr, ## __VA_ARGS__)
#endif


#if defined (LOGC_HAVE_FLF) || defined (LOGC_HAVE_FLF_FINE)
#define logc_logFineTEMP_(ident, formatStr, ...) \
   logc_log_flf_(__FILE__, __LINE__, __func__, ident, LOG_FINE, formatStr, ## __VA_ARGS__)
#else
#define logc_logFineTEMP_(ident, formatStr, ...) \
   logc_log_nflf_(ident, LOG_FINE, formatStr, ## __VA_ARGS__)
#endif


#if defined (LOGC_HAVE_FLF) || defined (LOGC_HAVE_FLF_FINEST)
#define logc_logFinestTEMP_(ident, formatStr, ...) \
   logc_log_flf_(__FILE__, __LINE__, __func__, ident, LOG_FINEST, formatStr, ## __VA_ARGS__)
#else
#define logc_logFinestTEMP_(ident, formatStr, ...) \
   logc_log_nflf_(ident, LOG_FINEST, formatStr, ## __VA_ARGS__)
#endif


#if defined (LOGC_HAVE_FLF)
#define logc_logArrayTEMP__(ident, level, desc, array, len) \
   logc_logArray_flf_(__FILE__, __LINE__, __func__, ident, level, desc, array, len)
#else
#define logc_logArrayTEMP__(ident, level, desc, array, len) \
   logc_logArray_nflf_(ident, level, desc, array, len)
#endif


#if defined (LOGC_HAVE_FLF) || defined (LOGC_HAVE_FLF_BASIC)
#define logc_logArrayBasicTEMP__(ident, desc, array, len) \
   logc_logArray_flf_(__FILE__, __LINE__, __func__, ident, LOG_BASIC, desc, array, len)
#else
#define logc_logArrayBasicTEMP__(ident, desc, array, len) \
   logc_logArray_nflf_(ident, LOG_BASIC, desc, array, len)
#endif


#if defined (LOGC_HAVE_FLF) || defined (LOGC_HAVE_FLF_WARNING)
#define logc_logArrayWarningTEMP_(ident, desc, array, len) \
   logc_logArray_flf_(__FILE__, __LINE__, __func__, ident, LOG_WARNING, desc, array, len)
#else
#define logc_logArrayWarningTEMP_(ident, desc, array, len) \
   logc_logArray_nflf_(ident, LOG_WARNING, desc, array, len)
#endif


#if defined (LOGC_HAVE_FLF) || defined (LOGC_HAVE_FLF_INFO)
#define logc_logArrayInfoTEMP_(ident, desc, array, len) \
   logc_logArray_flf_(__FILE__, __LINE__, __func__, ident, LOG_INFO, desc, array, len)
#else
#define logc_logArrayInfoTEMP_(ident, desc, array, len) \
   logc_logArray_nflf_(ident, LOG_INFO, desc, array, len)
#endif


#if defined (LOGC_HAVE_FLF) || defined (LOGC_HAVE_FLF_FINE)
#define logc_logArrayFineTEMP_(ident, desc, array, len) \
   logc_logArray_flf_(__FILE__, __LINE__, __func__, ident, LOG_FINE, desc, array, len)
#else
#define logc_logArrayFineTEMP_(ident, desc, array, len) \
   logc_logArray_nflf_(ident, LOG_FINE, desc, array, len)
#endif


#if defined (LOGC_HAVE_FLF) || defined (LOGC_HAVE_FLF_FINEST)
#define logc_logArrayFinestTEMP_(ident, desc, array, len) \
   logc_logArray_flf_(__FILE__, __LINE__, __func__, ident, LOG_FINEST, desc, array, len)
#else
#define logc_logArrayFinestTEMP_(ident, desc, array, len) \
   logc_logArray_nflf_(ident, LOG_FINEST, desc, array, len)
#endif



#if defined (LOGC_HAVE_FLF) || defined (LOGC_HAVE_FLF_FINEST)
#define logc_logEnterTEMP_(ident, functionname) \
   logc_logEnter_flf_(__FILE__, __LINE__, __func__, ident, functionname)
#else
#define logc_logEnterTEMP_(ident, functionname) \
   logc_logEnter_nflf_(ident, functionname)
#endif


#if defined (LOGC_HAVE_FLF) || defined (LOGC_HAVE_FLF_FINEST)
#define logc_logLeaveTEMP_(ident, functionname) \
   logc_logLeave_flf_(__FILE__, __LINE__, __func__, ident, functionname)
#else
#define logc_logLeaveTEMP_(ident, functionname) \
   logc_logLeave_nflf_(ident, functionname)
#endif



/*
 * disable / enable
 * error messages from info to warning log level
 */
#if defined (LOGC_DISABLE_WARN_ERRS) || defined (LOGC_DISABLE_WARN)

#define logc_logErrorWarningTEMP__(ident, err, formatStr, ...)

#define logc_logErrorInfoTEMP__(ident, err, formatStr, ...)

#else

#define logc_logErrorWarningTEMP__(ident, err, formatStr, ...) \
   logc_logErrorWarningTEMP_(ident, err, formatStr, ## __VA_ARGS__)

#define logc_logErrorInfoTEMP__(ident, err, formatStr, ...) \
   logc_logErrorInfoTEMP_(ident, err, formatStr, ## __VA_ARGS__)

#endif



/*
 * disable / enable
 * log messages from info to warning log level
 */
#if defined (LOGC_DISABLE_WARN_LOGS) || defined (LOGC_DISABLE_WARN)

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
 * error messages from fine to finest
 */
#if defined (LOGC_ENABLE_LOW_LEVEL_ERRS) || defined (LOGC_ENABLE_LOW_LEVEL)

#define logc_logErrorFineTEMP__(ident, err, formatStr, ...) \
   logc_logErrorFineTEMP_(ident, err, formatStr, ## __VA_ARGS__)

#define logc_logErrorFinestTEMP__(ident, err, formatStr, ...) \
   logc_logErrorFinestTEMP_(ident, err, formatStr, ## __VA_ARGS__)

#else

#define logc_logErrorFineTEMP__(ident, err, formatStr, ...)

#define logc_logErrorFinestTEMP__(ident, err, formatStr, ...)

#endif



/*
 * disable / enable
 * log messages from fine to finest
 */
#if defined (LOGC_ENABLE_LOW_LEVEL_LOGS) || defined (LOGC_ENABLE_LOW_LEVEL)

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

#ifdef __cplusplus
}; /* close `extern "C" */
#endif /* ifdef __cplusplus */

#endif /* header guard */
/* ========================== END OF FILE ================================== */

/*
 * vim settings, please do not remove!
 * vim:autoindent:filetype=c:syntax=c:
 * vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=75:formatoptions=croql:
 * vim600:foldmethod=syntax:
 */

