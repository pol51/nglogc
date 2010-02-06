
/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "err_record.h"

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
err_record(
      const char* formatStr,
      va_list vaList
      );


static char*
err_tag_record(
      logc_error_t error,
      const char* formatStr,
      va_list vaList
      );


static char*
err_tag_timestamp_record(
      logc_error_t error,
      const char* formatStr,
      va_list vaList
      );


static char*
err_timestamp_tag_record(
      logc_error_t error,
      const char* formatStr,
      va_list vaList
      );


static char*
timestamp_err_tag_record(
      logc_error_t error,
      const char* formatStr,
      va_list vaList
      );

/* =========== PUBLIC FUNCTIONS ============================================ */
/*---------------------------------------------------------------------------*/
logc_error_t
newErrorRecord(
      char** record,
      logc_errRecordType_t rtype,
      logc_error_t error,
      const  char* formatStr,
      va_list vaList
      )
{
   /* TODO */
   logc_error_t err = LOG_ERR_OK;

   switch (rtype) {
      case ERR:
         *record = err_record(formatStr, vaList);
         break;
      case ERR_TAG:
         *record = err_tag_record(error, formatStr, vaList);
         break;
      case ERR_TAG_TIMESTAMP:
         *record = err_tag_timestamp_record(error, formatStr, vaList);
         break;
      case ERR_TIMESTAMP_TAG:
         *record = err_timestamp_tag_record(error, formatStr, vaList);
         break;
      case TIMESTAMP_ERR_TAG:
         *record = timestamp_err_tag_record(error, formatStr, vaList);
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

/* =========== PRIVATE FUNCTIONS =========================================== */

static char*
err_record(
      const char* formatStr,
      va_list vaList
      )
{
   char* record = NULL;
   const char* const rec = "ERR : ";
   int recordSize = 0;

   recordSize = strlen(formatStr) + strlen(rec) + 1;
   record = malloc(recordSize);
   if (record != NULL) {
      strcpy(record, rec);
      vsprintf(record + strlen(rec), formatStr, vaList);
      record[recordSize-1] = '\n';
   }
   return record;
}


static char*
err_tag_record(
      logc_error_t error,
      const char* formatStr,
      va_list vaList
      )
{
   char* record = NULL;
   const char* err = "ERR ";
   const char* tag = "0xYYYYYYYY : ";
   int recordSize = 0;

   recordSize = strlen(formatStr) + strlen(err) + strlen(tag) + 1;
   record = malloc(recordSize);
   if (record != NULL) {
      sprintf(record, "%s0x%08X : ", err, error);
      vsprintf(record + strlen(err) + strlen(tag), formatStr, vaList);
      record[recordSize-1] = '\n';
   }

   return record;
}


static char*
err_tag_timestamp_record(
      logc_error_t error,
      const char* formatStr,
      va_list vaList
      )
{
   char* record = NULL;
   const char* err = "ERR ";
   const char* tag = "0xYYYYYYYY ";
   const char* timest = "day mon dd hh:mm:ss YYYY : ";
   int recordSize = 0;

   recordSize = strlen(formatStr) + strlen(err) +
      strlen(tag) + strlen(timest) + 1;
   record = malloc(recordSize);
   if (record != NULL) {
      sprintf(record, "%s0x%08X %s", err, error, timest);
      addTimestamp(record + strlen(err) + strlen(tag));
      vsprintf(record + strlen(err) + strlen(tag) + strlen(timest),
            formatStr, vaList);
      record[recordSize-1] = '\n';
   }

   return record;
}


static char*
err_timestamp_tag_record(
      logc_error_t error,
      const char* formatStr,
      va_list vaList
      )
{
   char* record = NULL;
   const char* err = "ERR ";
   const char* timest = "day mon dd hh:mm:ss YYYY ";
   const char* tag = "0xYYYYYYYY : ";
   int recordSize = 0;

   recordSize = strlen(formatStr) + strlen(err) +
      strlen(timest) + strlen(tag) + 1;
   record = malloc(recordSize);
   if (record != NULL) {
      sprintf(record, "%s%s0x%08X : ", err, timest, error);
      addTimestamp(record + strlen(err));
      vsprintf(record + strlen(err) + strlen(timest) +
            strlen(tag), formatStr, vaList);
      record[recordSize-1] = '\n';
   }

   return record;
}


static char*
timestamp_err_tag_record(
      logc_error_t error,
      const char* formatStr,
      va_list vaList
      )
{
   char* record = NULL;
   const char* timest = "day mon dd hh:mm:ss YYYY ";
   const char* err = "ERR ";
   const char* tag = "0xYYYYYYYY : ";
   int recordSize = 0;

   recordSize = strlen(formatStr) + strlen(timest) +
      strlen(err) + strlen(tag) + 1;
   record = malloc(recordSize);
   if (record != NULL) {
      sprintf(record, "%s%s0x%08X : ", timest, err, error);
      addTimestamp(record);
      vsprintf(record + strlen(timest) + strlen(err) +
            strlen(tag), formatStr, vaList);
      record[recordSize-1] = '\n';
   }

   return record;
}

/* ========================== END OF FILE ================================== */

/*
 * vim settings, please do not remove!
 * vim:autoindent:
 * vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=75:formatoptions=croql:
 * vim600:foldmethod=syntax:
 */
