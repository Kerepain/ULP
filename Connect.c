#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include"Connect.h"
#include "Pack.h"
#include"Pack.c"
struct Pack *pack;
struct SYN syn;
int fd;
socklen_t  len;
char *buf [MTU];
struct sockaddr_in src;

int Connect(struct sockaddr_in endport)
{
   fd = socket(AF_INET,SOCK_DGRAM,0);
   memset(*buf,0,MTU);
    syn._PLE=0x01;
     pack ->_TYPE =0x00;
    pack->_DATA[0] = syn._PLE;
    sendto(fd,&pack,2,0,(struct sockaddr*)&endport,&len);
    int count = recvfrom(fd,*buf,MTU,0,&src,&len);
    pack =  buf;
    if (pack->_TYPE == 0x00 && pack->_DATA[0] == 0x01)
    {
        return fd;
    }
    else
    {
        return -1;
    }
    
    
}
