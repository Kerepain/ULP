#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include <netinet/in.h>
#include"Pack.h"
#include"Pack.c"
#include"Connect.h"
#include "Connect.c"

int CONNECTED;

 int Connect(struct sockaddr_in endport);

int DisConnect(){

}

int send(char *buf,int fd){
     if (CONNECTED)
     {
        
     }
     else
     {
         return -1;
     }
     
     
}

int receive(char *buf,int *len,int fd){
  
}

int bind(){

}