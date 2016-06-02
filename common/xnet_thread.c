/*
 * xnet_thread.c
 *
 *  Created on: 2015年11月22日
 *      Author: houbin
 */


#include "xnet_thread.h"
#include <unistd.h>
#include <sys/syscall.h>



pid_t gettid() {
	return (pid_t)syscall(SYS_gettid);
}



