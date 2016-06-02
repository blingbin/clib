/*
 * xnet_atomic_unittest.c
 *
 *  Created on: Jun 3, 2016
 *      Author: houbin
 */
#include <assert.h>
#include <stdio.h>
#include <xnet_atomic.h>


int main()
{
	Xnet_AtomicInt32 atomic32_a = 1;
	assert(atomic32_a == 1);

	printf("xnet_atomic_get atomic32_a=%d\n", xnet_atomic_get(atomic32_a));
	printf("xnet_atomic_inc atomic32_a=%d\n", xnet_atomic_inc(atomic32_a));
	printf("xnet_atomic_dec atomic32_a=%d\n", xnet_atomic_dec(atomic32_a));
	printf("xnet_atomic_zero atomic32_a=%d\n", xnet_atomic_zero(atomic32_a));
	//printf("atomic32_a=%d\n", xnet_atomic_get(atomic32_a));
	return 0;
}
