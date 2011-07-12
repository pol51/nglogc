
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

#ifndef __LOGC_RINGBUFFER_H__
#define __LOGC_RINGBUFFER_H__


/* =========== INCLUDES ==================================================== */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif /* ifdef __cplusplus */

/* =========== DEFINES ===================================================== */
/* =========== DATA TYPES ================================================== */

/** forward declaration of ringbuffer */
struct rng_ringBuffer_s;
typedef struct rng_ringBuffer_s rng_ringBuffer_t;

/* =========== PUBLIC PROTOTYPES =========================================== */

/*---------------------------------------------------------------------------*/
/**
 * creates a new ringbuffer with given size, memory is allocated on heap.
 *
 * @param size           in : size of ringbuffer memory
 * @return rng_ringBuffer_t   pointer to allocated ringbuffer instance.
 *                            NULL if error occurs.
 *
 */
rng_ringBuffer_t*
rng_newRingbuffer(
      const size_t size
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/**
 * deletes given ringbuffer, frees the memory.
 *
 * @param rngBuf         in : ringbuffer to free
 *
 */
void
rng_delRingbuffer(
      rng_ringBuffer_t* rngBuf
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/**
 * resets given ringbuffer, clears content.
 *
 * @param rngBuf         in : ringbuffer to reset
 *
 */
void
rng_resetRingbuffer(
      rng_ringBuffer_t* const rngBuf
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/**
 * writes string to given ringbuffer.
 *
 * @param rngBuf         in : ringbuffer to write in
 * @param message        in : message to write, must be end with '\n'
 * @return logc_error_t       LOG_ERR_OK for success
 *                            LOG_ERR_PARAM for invalid parameter
 */
logc_error_t
rng_writeRingbuffer(
      rng_ringBuffer_t* const rngBuf,
      const char* const message
      );
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/**
 * reads content from ringbuffer and writes it to given buffer. starting
 * at first stored entry stopping at last entry which could be fully
 * written.
 *
 * @param rngBuf         in : ringbuffer to read from
 * @param buffer        out : buffer to write content in
 * @param size           in : size of buffer
 * @param writtenBytes  out : size of written content in buffer
 * @return logc_error_t       LOG_ERR_OK for success
 *                            LOG_ERR_NOT_FOUND ringbuffer has no data
 *
 */
logc_error_t
rng_readRingbuffer(
      const rng_ringBuffer_t* const rngBuf,
      char* const buffer,
      const size_t size,
      size_t* const writtenBytes
      );
/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
}; /* close `extern "C" */
#endif /* ifdef __cplusplus */

#endif
/* ========================== END OF FILE ================================== */

/*
 * vim settings, please do not remove!
 * vim:autoindent:filetype=c:syntax=c:
 * vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=75:formatoptions=croql:
 * vim600:foldmethod=syntax:
 */

