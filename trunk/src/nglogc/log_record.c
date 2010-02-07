
/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "log_record.h"

#include "timestamp.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* =========== MODULE CONFIGURATION ======================================== */
/* =========== DEFINES ===================================================== */
/* =========== DATA TYPES ================================================== */
/* =========== GLOBALS ===================================================== */
/* =========== PRIVATE PROTOTYPES ========================================== */
static char*
clean_record(
      const char* formatStr,
      va_list vaList
      );


static char*
timestamp_record(
      const char* formatStr,
      va_list vaList
      );

/* =========== PUBLIC FUNCTIONS ============================================ */

/*---------------------------------------------------------------------------*/
logc_error_t
newLogRecord(
      char** record,
      logc_logRecordType_t rtype,
      const  char* formatStr,
      va_list vaList
      )
{
   /* TODO */
   logc_error_t err = LOG_ERR_OK;

   if (record == NULL) {
      err = LOG_ERR_NULL;
   }

   if (err == LOG_ERR_OK) {
      *record = NULL;
      switch (rtype) {
         case CLEAN:
            *record = clean_record(formatStr, vaList);
            break;
         case TIMESTAMP:
            *record = timestamp_record(formatStr, vaList);
            break;
         default:
            err = LOG_ERR_PARAM;
            break;
      }
   }

   if (err == LOG_ERR_OK) {
      if (*record == NULL) {
         err = LOG_ERR_MEM;
      }
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/* =========== PRIVATE FUNCTIONS =========================================== */

/*---------------------------------------------------------------------------*/
static char*
clean_record(
      const char* formatStr,
      va_list vaList
      )
{
   char* record = NULL;
   int recordSize = 0;

   recordSize = strlen(formatStr) + 2;
   record = malloc(recordSize);
   if (record != NULL) {
      vsprintf(record, formatStr, vaList);
      record[recordSize-2] = '\n';
      record[recordSize-1] = '\0';
   }
   return record;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
static char*
timestamp_record(
      const char* formatStr,
      va_list vaList
      )
{
   char* record = NULL;
   const char* timest = "day mon dd hh:mm:ss YYYY : ";
   int recordSize = 0;

   recordSize = strlen(formatStr) + strlen(timest) + 2;
   record = malloc(recordSize);
   if (record != NULL) {
      strcpy(record, timest);
      addTimestamp(record);
      vsprintf(record + strlen(timest), formatStr, vaList);
      record[recordSize-2] = '\n';
      record[recordSize-1] = '\0';
   }

   return record;
}
/*---------------------------------------------------------------------------*/

/* ========================== END OF FILE ================================== */

/*
 * vim settings, please do not remove!
 * vim:autoindent:
 * vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=75:formatoptions=croql:
 * vim600:foldmethod=syntax:
 */
