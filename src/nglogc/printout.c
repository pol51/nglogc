
/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "printout.h"

#include "types.h"

#include <stdio.h>

/* =========== MODULE CONFIGURATION ======================================== */
/* =========== DEFINES ===================================================== */
/* =========== DATA TYPES ================================================== */
/* =========== GLOBALS ===================================================== */
/* =========== PRIVATE PROTOTYPES ========================================== */
/* =========== PUBLIC FUNCTIONS ============================================ */

/*---------------------------------------------------------------------------*/
logc_error_t
prn_stdprint(
      char* const message,
      FILE* fd
      )
{
   logc_error_t err = LOG_ERR_OK;

   if (message != NULL) {
      fprintf(stdout, message);
   } else {
      err = LOG_ERR_NULL;
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logc_error_t
prn_stderrprint(
      char* const message,
      FILE* fd
      )
{
   logc_error_t err = LOG_ERR_OK;

   if (message != NULL) {
      fprintf(stderr, message);
   } else {
      err = LOG_ERR_NULL;
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logc_error_t
prn_fileprint(
      char* const message,
      FILE* fd
      )
{
   logc_error_t err = LOG_ERR_OK;

   if (message == NULL || fd == NULL) {
      err = LOG_ERR_NULL;
   } else {
      fprintf(fd, message);
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logc_error_t
prn_rbufprint(
      char* const message,
      FILE* fd
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
