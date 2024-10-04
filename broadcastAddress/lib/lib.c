#include "../include/lib.h"
#include <stdio.h>

void get_broadcast_address(char *ipAddress, char mask, char *outputBuffer) {
    int octet1, octet2, octet3, octet4;
    if (sscanf(ipAddress, "%d.%d.%d.%d", &octet1, &octet2, &octet3, &octet4) != 4) {
        fprintf(stderr, "Invalid IPv4 address\n");
        return;
    }
    int k = 32 - (int)mask;
    if( k == 32 || k == 0 ) {
        fprintf(stderr, "Invalid Mask\n");
        return;
    }
    if(k <= 8) {
        octet4 |= (1 << k) - 1;
        sprintf(outputBuffer, "%d.%d.%d.%d", octet1, octet2, octet3, octet4);
        return;
    }
    if(k >= 9 && k <= 16) {
        octet4 |= FULLFLAG;
        k -= 8;
        octet3 |= (1 << k) - 1;
        sprintf(outputBuffer, "%d.%d.%d.%d", octet1, octet2, octet3, octet4);
        return;
    }
    if(k >= 17 && k <= 24) {
        octet4 |= FULLFLAG;
        octet3 |= FULLFLAG;
        k -= 16;
        octet2 |= (1 << k) - 1;
        sprintf(outputBuffer, "%d.%d.%d.%d", octet1, octet2, octet3, octet4);
        return;
    }
    if(k >= 25 && k <= 31) {
        octet4 |= FULLFLAG;
        octet3 |= FULLFLAG;
        octet2 |= FULLFLAG;
        k -= 24;
        octet1 |= (1 << k) - 1;
        sprintf(outputBuffer, "%d.%d.%d.%d", octet1, octet2, octet3, octet4);
        return;
    }
}
