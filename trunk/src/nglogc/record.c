
/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "record.h"

/* =========== MODULE CONFIGURATION ======================================== */
/* =========== DEFINES ===================================================== */
/* =========== DATA TYPES ================================================== */
/* =========== GLOBALS ===================================================== */
/* =========== PRIVATE PROTOTYPES ========================================== */
/* =========== PUBLIC FUNCTIONS ============================================ */
/*---------------------------------------------------------------------------*/
logc_error_t
newErrorRecord(
      char* record,
      logc_recordType_t rtype,
      va_list vaList
      )
{
   /* TODO */
   logc_error_t err = LOG_ERR_OK;
   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logc_error_t
newInfoRecord(
      char* record,
      logc_recordType_t rtype,
      va_list vaList
      )
{
   /* TODO */
   logc_error_t err = LOG_ERR_OK;
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
