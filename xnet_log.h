/*
 * xnet_log.h
 *
 *  Created on: 2015年5月22日
 *      Author: houbin
 */

#ifndef CLIB_XNET_LOG_H_
#define CLIB_XNET_LOG_H_

#include <syslog.h>
#include <stdarg.h>


void xnet_set_loglevel( int log_level );
void xnet_log( int log_level, const char* file_name, int line_num, const char* format, ... );


#endif /* CLIB_XNET_LOG_H_ */
