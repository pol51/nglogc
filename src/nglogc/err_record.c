
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

#define MAX_INT   10

/* =========== DATA TYPES ================================================== */
/* =========== GLOBALS ===================================================== */
/* =========== PRIVATE PROTOTYPES ========================================== */

static void
err_record(
      errorRecord_t* rec
      );


static void
err_tag_record(
      errorRecord_t* rec
      );


static void
err_tag_timestamp_record(
      errorRecord_t* rec
      );


static void
err_timestamp_tag_record(
      errorRecord_t* rec
      );


static void
timestamp_err_tag_record(
      errorRecord_t* rec
      );

/* =========== PUBLIC FUNCTIONS ============================================ */

/*---------------------------------------------------------------------------*/
logc_error_t
newErrorRecord(
      errorRecord_t* rec
      )
{
   logc_error_t err = LOG_ERR_OK;

   if (rec == NULL) {
      err = LOG_ERR_NULL;
   }

   if (err == LOG_ERR_OK) {
      rec->newRecord = NULL;
      switch (rec->rtype) {
         case ERR:
            err_record(rec);
            break;
         case ERR_TAG:
            err_tag_record(rec);
            break;
         case ERR_TAG_TIMESTAMP:
            err_tag_timestamp_record(rec);
            break;
         case ERR_TIMESTAMP_TAG:
            err_timestamp_tag_record(rec);
            break;
         case TIMESTAMP_ERR_TAG:
            timestamp_err_tag_record(rec);
            break;
         default:
            err = LOG_ERR_PARAM;
            break;
      }
   }

   if (err == LOG_ERR_OK) {
      if (rec->newRecord == NULL) {
         err = LOG_ERR_MEM;
      }
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/* =========== PRIVATE FUNCTIONS =========================================== */

static void
err_record(
      errorRecord_t* rec
      )
{
   const char* const err = "ERR : ";
   int recordSize = 0;
   logc_bool_t flf = LOG_FALSE;


   if (rec->file == NULL) {
      recordSize = strlen(rec->formatStr) + strlen(err) +  2;
   } else {
      flf = LOG_TRUE;
      recordSize = strlen(rec->file) + MAX_INT + strlen(rec->function) +
         strlen(rec->formatStr) + strlen(err) + strlen(":  - ") + 2;
   }
   rec->newRecord = malloc(recordSize);

   if (rec->newRecord != NULL) {
      memset(rec->newRecord, 0, recordSize);
      strcpy(rec->newRecord, err);
      if (flf == LOG_TRUE) {
         sprintf(rec->newRecord + strlen(rec->newRecord), "%s:%d %s - ",
               rec->file, rec->line, rec->function);
      }
      vsprintf(rec->newRecord + strlen(rec->newRecord),
            rec->formatStr, rec->vaList);

      rec->newRecord[strlen(rec->newRecord)] = '\n';
   }
}


static void
err_tag_record(
      errorRecord_t* rec
      )
{
   const char* err = "ERR ";
   const char* tag = "0xYYYYYYYY : ";
   int recordSize = 0;
   logc_bool_t flf = LOG_FALSE;

   if (rec->file == NULL) {
      recordSize = strlen(rec->formatStr) + strlen(err) + strlen(tag) + 2;
   } else {
      flf = LOG_TRUE;
      recordSize = strlen(rec->file) + MAX_INT + strlen(rec->function) +
         strlen(rec->formatStr) + strlen(err) + strlen(":  - ") + strlen(tag) + 2;
   }
   rec->newRecord = malloc(recordSize);

   if (rec->newRecord != NULL) {
      memset(rec->newRecord, 0, recordSize);
      sprintf(rec->newRecord, "%s0x%08X : ", err, rec->error);
      if (flf == LOG_TRUE) {
         sprintf(rec->newRecord + strlen(rec->newRecord), "%s:%d %s - ",
               rec->file, rec->line, rec->function);
      }
      vsprintf(rec->newRecord + strlen(rec->newRecord),
            rec->formatStr, rec->vaList);

      rec->newRecord[strlen(rec->newRecord)] = '\n';
   }
}


static void
err_tag_timestamp_record(
      errorRecord_t* rec
      )
{
   const char* err = "ERR ";
   const char* tag = "0xYYYYYYYY ";
   const char* timest = "day mon dd hh:mm:ss YYYY : ";
   int recordSize = 0;
   logc_bool_t flf = LOG_FALSE;

   if (rec->file == NULL) {
      recordSize = strlen(rec->formatStr) + strlen(err) +
         strlen(tag) + strlen(timest) + 2;
   } else {
      flf = LOG_TRUE;
      recordSize = strlen(rec->file) + MAX_INT + strlen(rec->function) +
         strlen(rec->formatStr) + strlen(err) + strlen(tag) +
         strlen(":  - ") + strlen(timest) + 2;
   }
   rec->newRecord = malloc(recordSize);

   if (rec->newRecord != NULL) {
      memset(rec->newRecord, 0, recordSize);
      sprintf(rec->newRecord, "%s0x%08X %s", err, rec->error, timest);
      addTimestamp(rec->newRecord + strlen(err) + strlen(tag));
      if (flf == LOG_TRUE) {
         sprintf(rec->newRecord + strlen(rec->newRecord), "%s:%d %s - ",
               rec->file, rec->line, rec->function);
      }
      vsprintf(rec->newRecord + strlen(rec->newRecord),
            rec->formatStr, rec->vaList);

      rec->newRecord[strlen(rec->newRecord)] = '\n';
   }
}


static void
err_timestamp_tag_record(
      errorRecord_t* rec
      )
{
   const char* err = "ERR ";
   const char* timest = "day mon dd hh:mm:ss YYYY ";
   const char* tag = "0xYYYYYYYY : ";
   int recordSize = 0;
   logc_bool_t flf = LOG_FALSE;

   if (rec->file == NULL) {
      recordSize = strlen(rec->formatStr) + strlen(err) +
         strlen(timest) + strlen(tag) + 2;
   } else {
      flf = LOG_TRUE;
      recordSize = strlen(rec->file) + MAX_INT + strlen(rec->function) +
         strlen(rec->formatStr) + strlen(err) + strlen(timest) +
         strlen(":  - ") + strlen(tag) + 2;
   }
   rec->newRecord = malloc(recordSize);

   if (rec->newRecord != NULL) {
      memset(rec->newRecord, 0, recordSize);
      sprintf(rec->newRecord, "%s%s0x%08X : ", err, timest, rec->error);
      addTimestamp(rec->newRecord + strlen(err));
      if (flf == LOG_TRUE) {
         sprintf(rec->newRecord + strlen(rec->newRecord), "%s:%d %s - ",
               rec->file, rec->line, rec->function);
      }

      vsprintf(rec->newRecord+ strlen(rec->newRecord),
            rec->formatStr, rec->vaList);

      rec->newRecord[strlen(rec->newRecord)] = '\n';
   }
}


static void
timestamp_err_tag_record(
      errorRecord_t* rec
      )
{
   const char* timest = "day mon dd hh:mm:ss YYYY ";
   const char* err = "ERR ";
   const char* tag = "0xYYYYYYYY : ";
   int recordSize = 0;
   logc_bool_t flf = LOG_FALSE;

   if (rec->file == NULL) {
   recordSize = strlen(rec->formatStr) + strlen(timest) +
      strlen(err) + strlen(tag) + 2;
   } else {
      flf = LOG_TRUE;
      recordSize = strlen(rec->file) + MAX_INT + strlen(rec->function) +
         strlen(rec->formatStr) + strlen(timest) + strlen(err) +
         strlen(":  - ") + strlen(tag) + 2;
   }
   rec->newRecord = malloc(recordSize);

   if (rec->newRecord != NULL) {
      memset(rec->newRecord, 0, recordSize);
      sprintf(rec->newRecord, "%s%s0x%08X : ", timest, err, rec->error);
      addTimestamp(rec->newRecord);
      if (flf == LOG_TRUE) {
         sprintf(rec->newRecord + strlen(rec->newRecord), "%s:%d %s - ",
               rec->file, rec->line, rec->function);
      }
      vsprintf(rec->newRecord + strlen(rec->newRecord),
            rec->formatStr, rec->vaList);

      rec->newRecord[strlen(rec->newRecord)] = '\n';
   }
}

/* ========================== END OF FILE ================================== */

/*
 * vim settings, please do not remove!
 * vim:autoindent:
 * vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=75:formatoptions=croql:
 * vim600:foldmethod=syntax:
 */
