

#ifndef __LOGC_PRINTOUT_H__
#define __LOGC_PRINTOUT_H__


/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

/* =========== DEFINES ===================================================== */
/* =========== DATA TYPES ================================================== */
/* =========== PUBLIC PROTOTYPES =========================================== */

/*---------------------------------------------------------------------------*/
/*
 * print message to standard out
 *
 * @param message        in : logging message
 * @return logError_t    LOG_ERR_OK for success
 *                       BASE_ERR_DATA  TODO
 */
logError_t
prn_stdprint(
      char* const message
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * print message to log file
 *
 * @param message        in : logging message
 * @return logError_t    LOG_ERR_OK for success
 *                       BASE_ERR_DATA  TODO
 */
logError_t
prn_fileprint(
      char* const message
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * print message to ringbuffer
 *
 * @param message        in : logging message
 * @return logError_t    LOG_ERR_OK for success
 *                       BASE_ERR_DATA  TODO
 */
logError_t
prn_rbufprint(
      char* const message
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

