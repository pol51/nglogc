
/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "timestamp.h"

#include <time.h>

/* =========== MODULE CONFIGURATION ======================================== */
/* =========== DEFINES ===================================================== */
/* =========== DATA TYPES ================================================== */
/* =========== GLOBALS ===================================================== */
/* =========== PRIVATE PROTOTYPES ========================================== */
/* =========== PUBLIC FUNCTIONS ============================================ */

void
addTimestamp(
      char* str
      )
{
   struct tm tim;
   time_t now;

   if (str != NULL) {
      now = time(NULL);
      tim = *(localtime(&now));
      strftime(str, TIMEST_LENGTH, "%c", &tim);
      str[TIMEST_LENGTH-1] = 0x20;
   }
}


/* =========== PRIVATE FUNCTIONS =========================================== */
/* ========================== END OF FILE ================================== */

/*
 * vim settings, please do not remove!
 * vim:autoindent:
 * vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=75:formatoptions=croql:
 * vim600:foldmethod=syntax:
 */
