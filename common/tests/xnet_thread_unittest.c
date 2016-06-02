/*
 * xnet_thread_unittest.c
 *
 *  Created on: 2015年11月22日
 *      Author: houbin0902
 */

#include <stdio.h>
#include "xnet_thread.h"

int main()
{
	int a = (int)gettid();
	printf("tid = %d\n", a);
	return 0;
}
