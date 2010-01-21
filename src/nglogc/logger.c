
/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "logger.h"

#include "types.h"

/* =========== MODULE CONFIGURATION ======================================== */
/* =========== DEFINES ===================================================== */
/* =========== DATA TYPES ================================================== */
/* =========== GLOBALS ===================================================== */
/* =========== PRIVATE PROTOTYPES ========================================== */
/* =========== PUBLIC FUNCTIONS ============================================ */

/*---------------------------------------------------------------------------*/
logError_t
log_setLogger(
      log_loggerType_t type,
      log_logLevel_t level
      )
{
   /* TODO */
   logError_t err = LOG_ERR_OK;
   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logError_t
log_removeLogger(
      log_loggerType_t type
      )
{
   /* TODO */
   logError_t err = LOG_ERR_OK;
   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logError_t
log_changeLogLevel(
      log_loggerType_t type,
      log_logLevel_t level
      )
{
   /* TODO */
   logError_t err = LOG_ERR_OK;
   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logError_t
log_setLogfile(
      const char* const filename
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
