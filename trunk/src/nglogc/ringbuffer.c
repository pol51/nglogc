
/******************************************************************************
 *
 * nglogc - Flexible C Logging API
 *
 * Author:        Dennis Krzyzaniak
 * E-mail:        ebrosius@netgarage.org
 * WWW:           http://www.netgarage.org
 * Copyright (C): 2010 by Dennis Krzyzaniak
 *
 * This file is part of nglogc.
 *
 * nglogc is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * nglogc is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser Public License for more details.
 *
 * You should have received a copy of the GNU Lesser Public License
 * along with nglogc.  If not, see <http://www.gnu.org/licenses/>.
 *
 *****************************************************************************/

/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "ringbuffer.h"

#include <string.h>
#include <assert.h>

/* =========== MODULE CONFIGURATION ======================================== */

/* =========== DEFINES ===================================================== */

/* =========== DATA TYPES ================================================== */

/** private ringbuffer */
struct rng_ringBuffer_s {
   /** size of data buffer */
   size_t bufferSize;
   /** count of stored entries */
   size_t entries;
   /** read position of first entry */
   char* readAt;
   /** write position for next entry */
   char* writeAt;
   /** data buffer */
   char* buffer;
};

/* =========== GLOBALS ===================================================== */

/* single ringbuffer instance */
static rng_ringBuffer_t* rbuf = NULL;

/* count of pointers to this ringbuffer */
static size_t rbufUsed = 0;

/* =========== PRIVATE PROTOTYPES ========================================== */

/*---------------------------------------------------------------------------*/
/**
 * returns the size of one entry from ringbuffer, starting at readAt.
 * entry ends with '\n'.
 *
 * @param rngBuf         in : ringbuffer
 * @param readAt         in : pointer to begin of entry
 * @return size_t       out : size of entry
 *
 */
static size_t
getEntrySize(
      const rng_ringBuffer_t* const rngBuf,
      const char* const readAt
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/**
 * writes one entry from ringbuffer to given buffer
 * entry ends with '\n'.
 *
 * @param buffer        out : memory to write entry
 * @param rngBuf         in : ringbuffer
 * @param readAt     in/out : pointer to begin of entry, is set to next
 *                            entry after successful call.
 *
 */
static void
getEntry(
      char* const buffer,
      const rng_ringBuffer_t* const rngBuf,
      char** readAt
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/**
 * creates a new ringbuffer with given size, memory is allocated on heap.
 *
 * @param size           in : size of ringbuffer memory
 * @return rng_ringBuffer_t   pointer to allocated ringbuffer instance.
 *                            NULL if error occurs.
 *
 */
static rng_ringBuffer_t*
createRingbuffer(
      const size_t size
      );
/*---------------------------------------------------------------------------*/

/* =========== PUBLIC FUNCTIONS ============================================ */

/*---------------------------------------------------------------------------*/
rng_ringBuffer_t*
rng_newRingbuffer(
      const size_t size
      )
{
   if (rbuf == NULL) {
      rbuf = createRingbuffer(size);
   }

   if (rbuf != NULL) {
      rbufUsed++;
   }

   return rbuf;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
void
rng_delRingbuffer(
      rng_ringBuffer_t* rngBuf
      )
{
   assert(rngBuf != NULL);

   if (rbufUsed > 0) {
      rbufUsed--;
      if (rbufUsed == 0) {
         free(rngBuf->buffer);
         free(rngBuf);
         rbuf = NULL;
      }
   }
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
void
rng_resetRingbuffer(
      rng_ringBuffer_t* const rngBuf
      )
{
   assert(rngBuf != NULL);

   if (rngBuf->entries != 0) {
      rngBuf->entries = 0;
      rngBuf->readAt = rngBuf->buffer;
      rngBuf->writeAt = rngBuf->buffer;
   }
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logc_error_t
rng_writeRingbuffer(
      rng_ringBuffer_t* const rngBuf,
      const char* const message
      )
{
   logc_error_t err = LOG_ERR_OK;
   size_t len = 0;
   size_t available = 0;

   assert(rngBuf != NULL);
   assert(message != NULL);

   len = strlen(message);
   available = (rngBuf->buffer + rngBuf->bufferSize) - rngBuf->writeAt;

   if (len > available) {
      memcpy(rngBuf->writeAt, message, available);
      rngBuf->writeAt = rngBuf->buffer;
      while ((rngBuf->readAt - rngBuf->buffer) < (len - available)) {
         while (*rngBuf->readAt++ != '\n') {}
         rngBuf->entries--;
      }
      memcpy(rngBuf->writeAt, message + available, len - available);
      rngBuf->writeAt += len - available;
      rngBuf->entries++;
   } else {
      memcpy(rngBuf->writeAt, message, len);
      rngBuf->writeAt += len;
      assert(rngBuf->writeAt < (rngBuf->buffer + rngBuf->bufferSize));
      rngBuf->entries++;
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
logc_error_t
rng_readRingbuffer(
      const rng_ringBuffer_t* const rngBuf,
      char* const buffer,
      const size_t size,
      size_t* const writtenBytes
      )
{
   logc_error_t err = LOG_ERR_OK;

   assert(rngBuf != NULL);
   assert(buffer != NULL);
   assert(writtenBytes != NULL);

   *writtenBytes = 0;

   if (rngBuf->entries == 0) {
      err = LOG_ERR_NO_ENTRIES;
   }

   if (err == LOG_ERR_OK) {
      size_t entries = rngBuf->entries;
      char* bufptr = buffer;
      char* tmpReadAt = rngBuf->readAt;

      while (entries-- != 0) {
         size_t entrySize = getEntrySize(rngBuf, tmpReadAt);
         if ((*writtenBytes + entrySize) < size) {
            getEntry(bufptr, rngBuf, &tmpReadAt);
            *writtenBytes += entrySize;
            bufptr += entrySize;
         } else {
            err = LOG_ERR_INSUFFICIENT_BUFFER;
            break;
         }
      }
      buffer[*writtenBytes] = 0;
      (*writtenBytes)++;
   }

   return err;
}
/*---------------------------------------------------------------------------*/

/* =========== PRIVATE FUNCTIONS =========================================== */

/*---------------------------------------------------------------------------*/
static size_t
getEntrySize(
      const rng_ringBuffer_t* const rngBuf,
      const char* const readAt
      )
{
   size_t size = 1;
   char* read = (char*)readAt;

   while (*read++ != '\n') {
      size++;
      if (read >= rngBuf->buffer + rngBuf->bufferSize) {
         read = rngBuf->buffer;
      }
   }

   return size;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
static void
getEntry(
      char* buffer,
      const rng_ringBuffer_t* const rngBuf,
      char** readAt
      )
{
   char* read = *readAt;

   while (*read != '\n') {
      *buffer++ = *read++;
      if (read >= rngBuf->buffer + rngBuf->bufferSize) {
         read = rngBuf->buffer;
      }
   }
   *buffer = *read++;
   *readAt = read;
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
static rng_ringBuffer_t*
createRingbuffer(
      const size_t size
      )
{
   logc_error_t err = LOG_ERR_OK;
   rng_ringBuffer_t* rngBuf = NULL;

   if (err == LOG_ERR_OK) {
      rngBuf = malloc(sizeof(*rngBuf));
      if (rngBuf == NULL) {
         err = LOG_ERR_MEM;
      } else {
         memset(rngBuf, 0, sizeof(*rngBuf));
      }
   }

   if (err == LOG_ERR_OK) {
      rngBuf->buffer = malloc(size);
      if (rngBuf->buffer == NULL) {
         err = LOG_ERR_MEM;
      } else {
         rngBuf->bufferSize = size;
         memset(rngBuf->buffer, 0, rngBuf->bufferSize);
         rngBuf->writeAt = rngBuf->buffer;
         rngBuf->readAt = rngBuf->buffer;
      }
   }

   if (err != LOG_ERR_OK) {
      if (rngBuf != NULL) {
         if (rngBuf->buffer != NULL) {
            free(rngBuf->buffer);
         }
         free(rngBuf);
         rngBuf = NULL;
      }
   }

   return rngBuf;
}
/*---------------------------------------------------------------------------*/

/* ========================== END OF FILE ================================== */

/*
 * vim settings, please do not remove!
 * vim:autoindent:
 * vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=75:formatoptions=croql:
 * vim600:foldmethod=syntax:
 */
