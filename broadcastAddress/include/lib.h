#ifndef _BROADCAST_ADDRESS_H
#define _BROADCAST_ADDRESS_H

#define PREFIX_LEN 16
#define FULLFLAG 255

void get_broadcast_address(char*, char, char*);
/*void get_broadcast_address(char *ip_address, char mask, char *output_buffer);
 * Will read an ip address and fetch the broadcast address of the given IP Address
 * depending on the mask provided, and assign the broadcast address to the output_buffer.
*/

#endif //_BROADCAST_ADDRESS_H
