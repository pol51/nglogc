

#ifndef __LOGC_LOG_RECORD_H__
#define __LOGC_LOG_RECORD_H__


/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "types.h"

#include <stdarg.h>

/* =========== DEFINES ===================================================== */

/* =========== DATA TYPES ================================================== */

/* =========== PUBLIC PROTOTYPES =========================================== */

/*---------------------------------------------------------------------------*/
/*
 * TODO
 */
logc_error_t
newLogRecord(
      char** record,
      logc_logRecordType_t rtype,
      const char* formatStr,
      va_list vaList
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
