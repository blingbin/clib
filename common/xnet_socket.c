/*
 * xnet_socket.c
 *
 *  Created on: 2015年5月22日
 *      Author: houbin
 */


#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>
#include <assert.h>
#include <errno.h>
#include <stdio.h>


int timeout_connect( const char* ip, unsigned short port, int time )
{
    int ret = 0;
    struct sockaddr_in address;
    bzero( &address, sizeof( address ) );
    address.sin_family = AF_INET;
    inet_pton( AF_INET, ip, &address.sin_addr );
    address.sin_port = htons( port );

    int sockfd = socket( PF_INET, SOCK_STREAM, 0 );
    assert( sockfd >= 0 );

    struct timeval timeout;
    timeout.tv_sec = time;
    timeout.tv_usec = 0;
    socklen_t len = sizeof( timeout );
    ret = setsockopt( sockfd, SOL_SOCKET, SO_SNDTIMEO, &timeout, len );
    assert( ret != -1 );

    ret = connect( sockfd, ( struct sockaddr* )&address, sizeof( address ) );
    if ( ret == -1 )
    {
        if( errno == EINPROGRESS )
        {
            printf( "connecting timeout\n" );
            return -1;
        }
        printf( "error occur when connecting to server\n" );
        return -1;
    }

    return sockfd;
}
