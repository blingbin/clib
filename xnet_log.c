/*
 * xnet_log.c
 *
 *  Created on: May 31, 2016
 *      Author: a
 */
#include "xnet_log.h"
#include <time.h>
#include <sys/time.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

void xnet_log_init(LogTag** plogtag, char const* filename, int level)
{
	if (filename==NULL || plogtag==NULL) return;
	*plogtag = (LogTag*)malloc(sizeof(LogTag));
	if(*plogtag==NULL) return;

	(*plogtag)->buf = (char*)malloc(LOG_BUF_SIZE*sizeof(char));
	if((*plogtag)->buf == NULL)
	{
		free(*plogtag);
		*plogtag = NULL;
		return;
	}
	(*plogtag)->level = level;
	(*plogtag)->pfile = fopen(filename,"wt+");
	if((*plogtag)->pfile == NULL)
	{
		*plogtag = NULL;
		return;
	}
	return;
}

int xnet_log(LogTag* plogtag, char const* fmt, ...)
{
	if(plogtag->buf == NULL)
	{
		return -1;
	}
	memset(plogtag->buf, 0, LOG_BUF_SIZE*sizeof(char));
	time_t now;
	struct timeval nowtimeval;
	gettimeofday(&nowtimeval, NULL);

	struct tm* pst, st;
	(void)time(&now);
	pst = localtime_r(&now, &st);
	int n = snprintf(plogtag->buf, LOG_BUF_SIZE*sizeof(char), "[%04d,-%02d-%02d %02d:%02d:%02d.%03d]",
			pst->tm_year+1900, pst->tm_mon+1, pst->tm_mday,
			pst->tm_hour, pst->tm_min, pst->tm_sec,
			(int)nowtimeval.tv_usec/1000);
	if(n<0) return -1;
	size_t writedn = strlen(plogtag->buf);
	va_list ap;
	va_start(ap, fmt);
	n = vsnprintf(plogtag->buf+n, LOG_BUF_SIZE*sizeof(char)-writedn, (const char *)fmt, ap);
	va_end(ap);
	if(n<0) return -1;
	fprintf(plogtag->pfile, "%s",plogtag->buf);
	fflush(plogtag->pfile);
	return n;
}

void xnet_log_destroy(LogTag* plogtag)
{
	if(plogtag->pfile != NULL)
	{
		fclose(plogtag->pfile);
	}
	if(plogtag->buf != NULL)
	{
		free(plogtag->buf);
	}
}
