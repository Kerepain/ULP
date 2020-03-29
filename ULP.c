#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<pthread.h>
#include<string.h>
#include"Connect.h"
#include"Pack.h"
#include"Pack.c"
socklen_t len;

char *Connect(struct sockaddr_in endport);

int DisConnect(char *ufd)
{
    struct UFD *ufdd;
     ufdd = ufd;
     struct Pack pack;
     pack._TYPE=0x05;
     pack._DATA[0]=0x01;
     for(size_t i;i !=5;i++){
     sendto(ufdd->fd,&pack,2,0,&ufdd->EndPort,&len);
     }
     close(ufdd->fd);
}

int send(char *buff,int Fd,int nub){
     
}

int receive(char *buff,int *len,int Fd){
  
}

int bind(){

}
