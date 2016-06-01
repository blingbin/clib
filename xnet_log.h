/*
 * xnet_log.h
 *
 *  Created on: May 31, 2016
 *      Author: a
 */

#ifndef XNET_LOG_H_
#define XNET_LOG_H_

#include <stdio.h>

//#ifdef __cplusplus

#define LOG_BUF_SIZE 1024

typedef struct LogTag_
{
	FILE * pfile;
	int level;
	char* buf;
}LogTag, *pLogTag;




void xnet_log_init(LogTag** plogtag, char const* filename, int level);
int xnet_log(LogTag* plogtag, char const* fmt, ...);
void xnet_log_destroy(LogTag* plogtag);





//typedef struct Logger_
//{
//	logTag* plogTag;
//	void* (*pxnet_log_init)(char const* , int);
//
//}Logger;







#endif /* XNET_LOG_H_ */
