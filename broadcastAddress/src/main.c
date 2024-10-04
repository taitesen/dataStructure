#include "../include/lib.h"
#include <stdio.h>
#include <string.h>
int main() {
    char broadcast_address_buffer[PREFIX_LEN];
    memset(broadcast_address_buffer, 0, PREFIX_LEN);
    char *ip_addr = "192.168.1.8";
    char mask = 20;
    get_broadcast_address(ip_addr, mask, broadcast_address_buffer);
    printf("Broadcast Address: %s\n", broadcast_address_buffer);
    return 0;
}
