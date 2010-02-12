
/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "flf_log.h"

#include "types.h"
#include "logger.h"
#include "err_record.h"
#include "log_record.h"
#include "array_record.h"

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/* =========== MODULE CONFIGURATION ======================================== */
/* =========== DEFINES ===================================================== */

#define MAX_INT   10

/* =========== DATA TYPES ================================================== */
/* =========== GLOBALS ===================================================== */
/* =========== PRIVATE PROTOTYPES ========================================== */
/* =========== PUBLIC FUNCTIONS ============================================ */

/*---------------------------------------------------------------------------*/
extern logger_t*
getLogger(
      uint16_t ident
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logc_error_t
logc_logError_flf_(
      const char* file,
      int line,
      const char* func,
      uint16_t ident,
      logc_error_t error,
      const char* formatStr,
      ...
      )
{
   logc_error_t err = LOG_ERR_OK;
   logger_t* logger = NULL;
   va_list vaList;
   errorRecord_t record = {0};

   if (formatStr == NULL) {
      err = LOG_ERR_NULL;
   }

   if (err == LOG_ERR_OK) {
      logger = getLogger(ident);
      if (logger == NULL) {
         err = LOG_ERR_NOT_FOUND;
      }
   }

   if (err == LOG_ERR_OK) {
      if (logger->level < LOG_BASIC) {
         err = LOG_ERR_LEVEL;
      } else {
         va_start(vaList, formatStr);
         record.file = file;
         record.line = line;
         record.function = func;
         record.rtype = logger->errRecordType;
         record.error = error;
         record.formatStr = formatStr;
         record.vaList = vaList;
         err = newErrorRecord(&record);
      }
   }

   if (err == LOG_ERR_OK) {
      logger->publisher(record.newRecord, logger->fd);
   }

   if (record.newRecord != NULL) {
      free(record.newRecord);
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logc_error_t
logc_logLevelError_flf_(
      const char* file,
      int line,
      const char* func,
      uint16_t ident,
      logc_logLevel_t level,
      logc_error_t error,
      const char* formatStr,
      ...
      )
{
   logc_error_t err = LOG_ERR_OK;
   logger_t* logger = NULL;
   va_list vaList;
   errorRecord_t record = {0};

   if (formatStr == NULL) {
      err = LOG_ERR_NULL;
   }

   if (err == LOG_ERR_OK) {
      logger = getLogger(ident);
      if (logger == NULL) {
         err = LOG_ERR_NOT_FOUND;
      }
   }

   if (err == LOG_ERR_OK) {
      if (logger->level < level) {
         err = LOG_ERR_LEVEL;
      } else {
         va_start(vaList, formatStr);
         record.file = file;
         record.line = line;
         record.function = func;
         record.rtype = logger->errRecordType;
         record.error = error;
         record.formatStr = formatStr;
         record.vaList = vaList;
         err = newErrorRecord(&record);
      }
   }

   if (err == LOG_ERR_OK) {
      logger->publisher(record.newRecord, logger->fd);
   }

   if (record.newRecord != NULL) {
      free(record.newRecord);
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logc_error_t
logc_log_flf_(
      const char* file,
      int line,
      const char* func,
      uint16_t ident,
      logc_logLevel_t level,
      const char* formatStr,
      ...
      )
{
   logc_error_t err = LOG_ERR_OK;
   logger_t* logger = NULL;
   va_list vaList;
   logRecord_t record = {0};

   if (formatStr == NULL) {
      err = LOG_ERR_NULL;
   }

   if (err == LOG_ERR_OK) {
      logger = getLogger(ident);
      if (logger == NULL) {
         err = LOG_ERR_NOT_FOUND;
      }
   }

   if (err == LOG_ERR_OK) {
      if (logger->level < level) {
         err = LOG_ERR_LEVEL;
      } else {
         va_start(vaList, formatStr);
         record.file = file;
         record.line = line;
         record.function = func;
         record.rtype = logger->logRecordType;
         record.formatStr = formatStr;
         record.vaList = vaList;
         err = newLogRecord(&record);
      }
   }

   if (err == LOG_ERR_OK) {
      logger->publisher(record.newRecord, logger->fd);
   }

   if (record.newRecord != NULL) {
      free(record.newRecord);
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logc_error_t
logc_logArray_flf_(
      const char* file,
      int line,
      const char* func,
      uint16_t ident,
      logc_logLevel_t level,
      const char* descriptor,
      const uint8_t* array,
      size_t len
      )
{
   logc_error_t err = LOG_ERR_OK;
   logger_t* logger = NULL;
   arrayRecord_t record = {0};

   if (descriptor == NULL || array == NULL) {
      err = LOG_ERR_NULL;
   }

   if (err == LOG_ERR_OK) {
      logger = getLogger(ident);
      if (logger == NULL) {
         err = LOG_ERR_NOT_FOUND;
      }
   }

   if (err == LOG_ERR_OK) {
      if (logger->level < level) {
         err = LOG_ERR_LEVEL;
      } else {
         record.file = file;
         record.line = line;
         record.function = func;
         record.rtype = logger->logRecordType;
         record.descriptor = descriptor;
         record.array = array;
         record.len = len;
         err = newArrayRecord(&record);
      }
   }

   if (err == LOG_ERR_OK) {
      logger->publisher(record.newRecord, logger->fd);
   }

   if (record.newRecord != NULL) {
      free(record.newRecord);
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logc_error_t
logc_logEnter_flf_(
      const char* file,
      int line,
      const char* func,
      uint16_t ident,
      const char* functionName
      )
{
   logc_error_t err = LOG_ERR_OK;
   logger_t* logger = NULL;
   char* record = NULL;

   if (functionName == NULL) {
      err = LOG_ERR_NULL;
   }

   if (err == LOG_ERR_OK) {
      logger = getLogger(ident);
      if (logger == NULL) {
         err = LOG_ERR_NOT_FOUND;
      } else {
         if (logger->level < LOG_FINEST) {
            err = LOG_ERR_LEVEL;
         }
      }
   }

   if (err == LOG_ERR_OK) {
      if (file != NULL) {
         record = malloc(strlen(file) + MAX_INT + strlen(func) +
               sizeof("Enter > ") + strlen(": ") + 1);
      } else {
         record = malloc(strlen(functionName) + sizeof("Enter > ") + 1);
      }

      if (record == NULL) {
         err = LOG_ERR_MEM;
      } else {
         if (file != NULL) {
            sprintf(record, "Enter > %s:%d %s\n", file, line, func);
         } else {
            sprintf(record, "Enter > %s\n", functionName);
         }
         logger->publisher(record, logger->fd);
      }
   }

   if (record != NULL) {
      free(record);
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logc_error_t
logc_logLeave_flf_(
      const char* file,
      int line,
      const char* func,
      uint16_t ident,
      const char* functionName
      )
{
   logc_error_t err = LOG_ERR_OK;
   logger_t* logger = NULL;
   char* record = NULL;

   if (functionName == NULL) {
      err = LOG_ERR_NULL;
   }

   if (err == LOG_ERR_OK) {
      logger = getLogger(ident);
      if (logger == NULL) {
         err = LOG_ERR_NOT_FOUND;
      }
   }

   if (err == LOG_ERR_OK) {
      if (file != NULL) {
         record = malloc(strlen(file) + MAX_INT + strlen(func) +
               sizeof("Leave < ") + strlen(": ") + 1);
      } else {
         record = malloc(strlen(functionName) + sizeof("Leave < ") + 1);
      }

      if (record == NULL) {
         err = LOG_ERR_MEM;
      } else {
         if (file != NULL) {
            sprintf(record, "Leave < %s:%d %s\n", file, line, func);
         } else {
            sprintf(record, "Leave < %s\n", functionName);
         }
         logger->publisher(record, logger->fd);
      }
   }

   if (record != NULL) {
      free(record);
   }

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
