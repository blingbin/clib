/*
 * xnet_log.c
 *
 *  Created on: 2015年5月22日
 *      Author: houbin
 */


#include <stdio.h>
#include <time.h>
#include <string.h>
#include "xnet_log.h"

static int level = LOG_INFO;
static int LOG_BUFFER_SIZE = 2048;
static const char* loglevels[] =
{
    "emerge!", "alert!", "critical!", "error!", "warn!", "notice:", "info:", "debug:"
};

void xnet_set_loglevel( int log_level )
{
    level = log_level;
}

void xnet_log( int log_level,  const char* file_name, int line_num, const char* format, ... )
{
    if ( log_level > level )
    {
        return;
    }

    time_t tmp = time( NULL );
    struct tm* cur_time = localtime( &tmp );
    if ( ! cur_time )
    {
        return;
    }

    char arg_buffer[ LOG_BUFFER_SIZE ];
    memset( arg_buffer, '\0', sizeof(arg_buffer) );
    strftime( arg_buffer, (size_t)LOG_BUFFER_SIZE - 1, "[ %x %X ] ", cur_time );
    printf( "%s", arg_buffer );
    printf( "%s:%04d ", file_name, line_num );
    printf( "%s ", loglevels[ log_level - LOG_EMERG ] );

    va_list arg_list;
    va_start( arg_list, format );
    memset( arg_buffer, '\0', sizeof(arg_buffer) );
    vsnprintf( arg_buffer, (size_t)LOG_BUFFER_SIZE - 1, format, arg_list );
    printf( "%s\n", arg_buffer );
    fflush( stdout );
    va_end( arg_list );
}
