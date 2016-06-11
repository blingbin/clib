#include <stdio.h>

#include "xnet_process_info.h"

int main()
{
    char buf[32] = {0};
    (void)xnet_hostname(buf, sizeof(buf));
    printf("buf:%s\n", buf);
    return 0;
}
