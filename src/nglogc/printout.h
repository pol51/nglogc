

#ifndef __LOGC_PRINTOUT_H__
#define __LOGC_PRINTOUT_H__


/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "types.h"

#include <stdio.h>

/* =========== DEFINES ===================================================== */
/* =========== DATA TYPES ================================================== */
/* =========== PUBLIC PROTOTYPES =========================================== */

/*---------------------------------------------------------------------------*/
/*
 * print message to standard out
 *
 * @param message        in : logging message
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if message is NULL
 */
logc_error_t
prn_stdprint(
      char* const message,
      FILE* fd
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * print message to standard err
 *
 * @param message        in : logging message
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if message is NULL
 */
logc_error_t
prn_stderrprint(
      char* const message,
      FILE* fd
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * print message to log file
 *
 * @param message        in : logging message
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if message or fd is NULL
 */
logc_error_t
prn_fileprint(
      char* const message,
      FILE* fd
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * print message to ringbuffer
 *
 * @param message        in : logging message
 * @return logc_error_t  LOG_ERR_OK for success
 *                       LOG_ERR_NULL if message or fd is NULL
 *                       TODO not implemented
 */
logc_error_t
prn_rbufprint(
      char* const message,
      FILE* fd
      );
/*---------------------------------------------------------------------------*/

#endif /* header guard */
/* ========================== END OF FILE ================================== */

/*
 * vim settings, please do not remove!
 * vim:autoindent:filetype=c:syntax=c:
 * vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=75:formatoptions=croql:
 * vim600:foldmethod=syntax:
 */

