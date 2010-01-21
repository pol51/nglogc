
/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "nflf_log.h"

#include "types.h"

/* =========== MODULE CONFIGURATION ======================================== */
/* =========== DEFINES ===================================================== */
/* =========== DATA TYPES ================================================== */
/* =========== GLOBALS ===================================================== */
/* =========== PRIVATE PROTOTYPES ========================================== */
/* =========== PUBLIC FUNCTIONS ============================================ */

/*---------------------------------------------------------------------------*/
logError_t
logc_logError_nflf_(
      logError_t err,
      log_loggerType_t type,
      const* char formatStr,
      ...
      )
{
   /* TODO */
   logError_t err = LOG_ERR_OK;
   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logError_t
logc_logLevelError_nflf_(
      logError_t err,
      log_logLevel_t level,
      log_loggerType_t type,
      const* char formatStr,
      ...
      )
{
   /* TODO */
   logError_t err = LOG_ERR_OK;
   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logError_t
logc_log_nflf_(
      log_logLevel_t level,
      log_loggerType_t type,
      const* char formatStr,
      ...
      )
{
   /* TODO */
   logError_t err = LOG_ERR_OK;
   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logError_t
logc_logArray_nflf_(
      log_logLevel_t level,
      log_loggerType_t type,
      const* char descriptor,
      const* uint8_t array,
      size_t len
      )
{
   /* TODO */
   logError_t err = LOG_ERR_OK;
   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logError_t
logc_logEnter_nflf_(
      log_loggerType_t type,
      const* char functionName
      )
{
   /* TODO */
   logError_t err = LOG_ERR_OK;
   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logError_t
logc_logLeave_nflf_(
      log_loggerType_t type,
      const* char functionName
      )
{
   /* TODO */
   logError_t err = LOG_ERR_OK;
   return err;
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
