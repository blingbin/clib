/*
 * xnet_log_unittest.c
 *
 *  Created on: Jun 1, 2016
 *      Author: a
 */

#include "xnet_log.h"


int main()
{

	pLogTag plogtag;
	xnet_log_init(&plogtag, "./txt.txt", 1);
	xnet_log(plogtag, "hello world\n");
	xnet_log_destroy(plogtag);
	return 0;

}
