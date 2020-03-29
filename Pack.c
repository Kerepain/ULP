#include<stdio.h>
#include"Pack.h"

typedef struct Pack
{
    char _TYPE;
    char _DATA[MTU - 1];
};

//0x00
typedef struct SYN
{
   char _PLE;
};
//0x01
typedef struct ACK
{
   char _OK;
};
//0x02
typedef struct PSH
{
   char _NUB;
   char _DATA[MTU - 2];
};
//0x03
typedef struct KEEPCONNECT
{
    char _CHEAK;
};
//0x04
typedef struct INIT
{
    char _NUB;
    char _BUFF_LEN[16];
    char _QUANTITY[16];
};
//0x05
typedef struct RST
{
     char rst;
};

typedef struct  UFD
{
    int fd;
    struct sockaddr_in EndPort;
};
