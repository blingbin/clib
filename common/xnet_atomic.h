/*
 * xnet_atomic.h
 *
 *  Created on: Jun 2, 2016
 *      Author: houbin
 */

#ifndef COMMON_XNET_ATOMIC_H_
#define COMMON_XNET_ATOMIC_H_

/**
 * Built-in functions for atomic memory access (For gcc version 4.5.4)
 *
 * type __sync_fetch_and_add (type *ptr, type value, ...)
 * type __sync_fetch_and_sub (type *ptr, type value, ...)
 * type __sync_fetch_and_or (type *ptr, type value, ...)
 * type __sync_fetch_and_and (type *ptr, type value, ...)
 * type __sync_fetch_and_xor (type *ptr, type value, ...)
 * type __sync_fetch_and_nand (type *ptr, type value, ...)
 *
 * type __sync_add_and_fetch (type *ptr, type value, ...)
 * type __sync_sub_and_fetch (type *ptr, type value, ...)
 * type __sync_or_and_fetch (type *ptr, type value, ...)
 * type __sync_and_and_fetch (type *ptr, type value, ...)
 * type __sync_xor_and_fetch (type *ptr, type value, ...)
 * type __sync_nand_and_fetch (type *ptr, type value, ...)
 *
 * bool __sync_bool_compare_and_swap (type *ptr, type oldval type newval, ...)
 * type __sync_val_compare_and_swap (type *ptr, type oldval type newval, ...)
 *
 */
#include <stdint.h>

typedef  volatile int32_t Xnet_AtomicInt32;
typedef  volatile int64_t Xnet_AtomicInt64;

#define xnet_atomic_get(val) __sync_fetch_and_add(&(val), 0)
#define xnet_atomic_inc(val) __sync_add_and_fetch(&(val), 1)
#define xnet_atomic_dec(val) __sync_sub_and_fetch(&(val), 1)
#define xnet_atomic_zero(val) __sync_and_and_fetch(&(val), 0)








#endif /* COMMON_XNET_ATOMIC_H_ */
