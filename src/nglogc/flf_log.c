
/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "flf_log.h"

#include "types.h"

/* =========== MODULE CONFIGURATION ======================================== */
/* =========== DEFINES ===================================================== */
/* =========== DATA TYPES ================================================== */
/* =========== GLOBALS ===================================================== */
/* =========== PRIVATE PROTOTYPES ========================================== */
/* =========== PUBLIC FUNCTIONS ============================================ */

/*---------------------------------------------------------------------------*/
logError_t
logc_logError_flf_(
      const char* file,
      int line,
      const char* func,
      logError_t err,
      log_loggerType_t type,
      const* char formatStr,
      ...
      )
{
   /* TODO */
   logError_t err = LOG_ERR_OK;
   return er;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logError_t
logc_logLevelError_flf_(
      const char* file,
      int line,
      const char* func,
      logError_t err,
      log_logLevel_t level,
      log_loggerType_t type,
      const* char formatStr,
      ...
      )
{
   /* TODO */
   logError_t err = LOG_ERR_OK;
   return er;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logError_t
logc_log_flf_(
      const char* file,
      int line,
      const char* func,
      log_logLevel_t level,
      log_loggerType_t type,
      const* char formatStr,
      ...
      )
{
   /* TODO */
   logError_t err = LOG_ERR_OK;
   return er;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logError_t
logc_logArray_flf_(
      const char* file,
      int line,
      const char* func,
      log_logLevel_t level,
      log_loggerType_t type,
      const* char descriptor,
      const* uint8_t array,
      size_t len
      )
{
   /* TODO */
   logError_t err = LOG_ERR_OK;
   return er;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logError_t
logc_logEnter_flf_(
      const char* file,
      int line,
      const char* func,
      log_loggerType_t type,
      const* char functionName
      )
{
   /* TODO */
   logError_t err = LOG_ERR_OK;
   return er;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logError_t
logc_logLeave_flf_(
      const char* file,
      int line,
      const char* func,
      log_loggerType_t type,
      const* char functionName
      )
{
   /* TODO */
   logError_t err = LOG_ERR_OK;
   return er;
}
/*---------------------------------------------------------------------------*/


/* =========== PRIVATE FUNCTIONS =========================================== */
/* ========================== END OF FILE ================================== */

/*
 * vim settings, please do not remove!
 * vim:autoindent:
 * vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=75:formatoptions=croql:
 * vim600:foldmethod=syntax:
 */
