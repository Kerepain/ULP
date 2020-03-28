#include<stdio.h>
#include"Pack.h"

typedef struct Pack
{
    char _TYPE;
    char _DATA[MTU - 1];
};

typedef struct SYN
{
   char _PLE;
};
typedef struct ACK
{
   char _OK;
};
typedef struct PSH
{
   char _NUB[2];
   char _DATA[MTU - 3];
};
typedef struct KEEPCONNECT
{
    char _CHEAK;
};
typedef struct INIT
{
    char _BUFF_LEN[16];
    char _QUANTITY[16];
};
typedef struct RST
{
     char rst;
};

