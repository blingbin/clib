#include <unistd.h>

int xnet_hostname(char* buf, int buf_len)
{
    buf[buf_len-1] = '\0';
    gethostname(buf, buf_len);
}
