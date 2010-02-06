
/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "record.h"

#include <stdlib.h>
#include <string.h>

/* =========== MODULE CONFIGURATION ======================================== */
/* =========== DEFINES ===================================================== */
/* =========== DATA TYPES ================================================== */
/* =========== GLOBALS ===================================================== */
/* =========== PRIVATE PROTOTYPES ========================================== */
static char*
clean(
      const char* formatStr,
      va_list vaList
      );


static char*
err_tag(
      logc_error_t error,
      const char* formatStr,
      va_list vaList
      );


static char*
err_tag_timestamp(
      logc_error_t error,
      const char* formatStr,
      va_list vaList
      );


static char*
err_timestamp_tag(
      logc_error_t error,
      const char* formatStr,
      va_list vaList
      );


static char*
timestamp_err_tag(
      logc_error_t error,
      const char* formatStr,
      va_list vaList
      );

/* =========== PUBLIC FUNCTIONS ============================================ */
/*---------------------------------------------------------------------------*/
logc_error_t
newErrorRecord(
      char* record,
      logc_recordType_t rtype,
      logc_error_t error,
      const  char* formatStr,
      va_list vaList
      )
{
   /* TODO */
   logc_error_t err = LOG_ERR_OK;

   switch (rtype) {
      case CLEAN:
         record = clean(formatStr, vaList);
         break;
      case ERR_TAG:
         record = err_tag(error, formatStr, vaList);
         break;
      case ERR_TAG_TIMESTAMP:
         record = err_tag_timestamp(error, formatStr, vaList);
         break;
      case ERR_TIMESTAMP_TAG:
         record = err_timestamp_tag(error, formatStr, vaList);
         break;
      case TIMESTAMP_ERR_TAG:
         record = timestamp_err_tag(error, formatStr, vaList);
         break;
      default:
         break;
   }

   if (record == NULL) {
      err = LOG_ERR_MEM;
   }


   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logc_error_t
newInfoRecord(
      char* record,
      logc_recordType_t rtype,
      const  char* formatStr,
      va_list vaList
      )
{
   /* TODO */
   logc_error_t err = LOG_ERR_OK;
   return err;
}

/*---------------------------------------------------------------------------*/
/* =========== PRIVATE FUNCTIONS =========================================== */

static char*
clean(
      const char* formatStr,
      va_list vaList
      )
{
   char* record = NULL;
   return record;
}


static char*
err_tag(
      logc_error_t error,
      const char* formatStr,
      va_list vaList
      )
{
   char* record = NULL;
   return record;
}


static char*
err_tag_timestamp(
      logc_error_t error,
      const char* formatStr,
      va_list vaList
      )
{
   char* record = NULL;
   return record;
}


static char*
err_timestamp_tag(
      logc_error_t error,
      const char* formatStr,
      va_list vaList
      )
{
   char* record = NULL;
   return record;
}


static char*
timestamp_err_tag(
      logc_error_t error,
      const char* formatStr,
      va_list vaList
      )
{
   char* record = NULL;
   return record;
}

/* ========================== END OF FILE ================================== */

/*
 * vim settings, please do not remove!
 * vim:autoindent:
 * vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=75:formatoptions=croql:
 * vim600:foldmethod=syntax:
 */
