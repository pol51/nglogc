
/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "logger.h"

#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "printout.h"

/* TODO remove me, just for test */
#include <stdio.h>

/* =========== MODULE CONFIGURATION ======================================== */
/* =========== DEFINES ===================================================== */
/* =========== DATA TYPES ================================================== */

/* double linked list type of loggers */
struct loggerList_s {
   logger_t logger;
   struct loggerList_s* next;
   struct loggerList_s* before;
};
typedef struct loggerList_s loggerList_t;

/* =========== GLOBALS ===================================================== */

static
loggerList_t* loggerList = NULL;

static
loggerList_t* loggerLast = NULL;

/* =========== PRIVATE PROTOTYPES ========================================== */
/* =========== PUBLIC FUNCTIONS ============================================ */

/*---------------------------------------------------------------------------*/
logc_error_t
logc_registerLogger(
      uint16_t ident,
      logc_loggerType_t type,
      logc_logLevel_t level
      )
{
   logc_error_t err = LOG_ERR_OK;
   loggerList_t* newLogger = NULL;

   if (type < STDOUT || type > RBUFOUT ||
         level < LOG_BASIC || level > LOG_SILENT) {
      err = LOG_ERR_PARAM;
   }

   if (err == LOG_ERR_OK) {
      newLogger = (loggerList_t*)malloc(sizeof(*newLogger));
      if (newLogger != NULL) {
         memset(newLogger, 0, sizeof(*newLogger));
      } else {
         err = LOG_ERR_MEM;
      }
   }

   if (err == LOG_ERR_OK) {
      newLogger->logger.id = ident;
      newLogger->logger.level = level;

      switch (type) {
         case STDOUT:
            newLogger->logger.publisher = &prn_stdprint;
            break;
         case STDERROUT:
            newLogger->logger.publisher = &prn_stderrprint;
            break;
         case FILEOUT:
            newLogger->logger.publisher = &prn_fileprint;
            break;
         case RBUFOUT:
            /* TODO */
            break;
      }
   }

   if (err == LOG_ERR_OK) {
      if (loggerLast == NULL) {
         loggerList = newLogger;
         loggerLast = loggerList;
      } else {
         newLogger->before = loggerLast;
         loggerLast->next = newLogger;
         loggerLast = newLogger;
      }
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logc_error_t
logc_removeLogger(
      uint16_t ident
      )
{
   logc_error_t err = LOG_ERR_NOT_FOUND;
   loggerList_t* iter = NULL;

   iter = loggerList;
   while (iter != NULL) {
      if (iter->logger.id == ident) {
         err = LOG_ERR_OK;
         break;
      }
      iter = iter->next;
   }

   if (err == LOG_ERR_OK) {
      if (iter->before) {
         iter->before->next = iter->next;
         if (iter->next) {
            iter->next->before = iter->before;
         }
      } else {
         loggerList = iter->next;
         if (iter->next) {
            iter->next->before = NULL;
         }
      }

      if (iter->next == NULL) {
         loggerLast = iter->before;
      }

      free(iter);
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logc_error_t
logc_changeLogLevel(
      uint16_t ident,
      logc_logLevel_t level
      )
{
   /* TODO */
   logc_error_t err = LOG_ERR_OK;
   loggerList_t* iter = NULL;

   if (level < LOG_BASIC || level > LOG_SILENT) {
      err = LOG_ERR_PARAM;
   }

   if (err == LOG_ERR_OK) {
      err = LOG_ERR_NOT_FOUND;
      iter = loggerList;

      while (iter != NULL) {
         if (iter->logger.id == ident) {
            iter->logger.level = level;
            err = LOG_ERR_OK;
            break;
         }
         iter = iter->next;
      }
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logc_error_t
logc_setLogfile(
      uint16_t ident,
      const char* const filename
      )
{
   /* TODO */
   logc_error_t err = LOG_ERR_OK;
   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * TODO should be private
 */
logger_t*
getLogger(
      uint16_t ident
      )
{
   logger_t* ret = NULL;
   loggerList_t* iter = loggerList;

   while (iter != NULL) {
      if (iter->logger.id == ident) {
         ret = &(iter->logger);
         break;
      }
      iter = iter->next;
   }

   return ret;
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
