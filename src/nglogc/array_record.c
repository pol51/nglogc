
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
      const char* descriptor,
      const uint8_t* array,
      size_t len
      );


static char*
timestamp_record(
      const char* descriptor,
      const uint8_t* array,
      size_t len
      );

/* =========== PUBLIC FUNCTIONS ============================================ */

/*---------------------------------------------------------------------------*/
logc_error_t
newArrayRecord(
      char** record,
      logc_logRecordType_t rtype,
      const char* descriptor,
      const uint8_t* array,
      size_t len
      )
{
   logc_error_t err = LOG_ERR_OK;

   if (record == NULL) {
      err = LOG_ERR_NULL;
   }

   if (err == LOG_ERR_OK) {
      *record = NULL;
      switch (rtype) {
         case CLEAN:
            *record = clean_record(descriptor, array, len);
            break;
         case TIMESTAMP:
            *record = timestamp_record(descriptor, array, len);
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
      const char* descriptor,
      const uint8_t* array,
      size_t len
      )
{
   char* record = NULL;
   int recordSize = 0;
   int i = 0, j = 0;

   recordSize = strlen(descriptor) + strlen(" : ") + (len * 2) + 2;
   record = malloc(recordSize);
   if (record != NULL) {
      strcpy(record, descriptor);
      strcat(record, " : ");
      for (i=0; i<len; i++) {
         sprintf(record + strlen(descriptor) + strlen(" : ") + j, "%02X", array[i]);
         j+=2;
      }

      record[recordSize-2] = '\n';
      record[recordSize-1] = '\0';
   }
   return record;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
static char*
timestamp_record(
      const char* descriptor,
      const uint8_t* array,
      size_t len
      )
{
   char* record = NULL;
   const char* timest = "day mon dd hh:mm:ss YYYY ";
   int recordSize = 0;
   int i = 0, j = 0;

   recordSize = strlen(descriptor) + strlen(" : ") + (len * 2) +
      strlen(timest) + 2;
   record = malloc(recordSize);
   if (record != NULL) {
      strcpy(record, timest);
      addTimestamp(record);
      strcat(record, descriptor);
      strcat(record, " : ");
      for (i=0; i<len; i++) {
         sprintf(record + strlen(descriptor) + strlen(" : ") +
               strlen(timest) + j, "%02X", array[i]);
         j+=2;
      }

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
