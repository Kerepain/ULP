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
struct Pack *pack;
struct Pack packs
struct SYN syn;
int fd;
socklen_t len;
char buf [MTU];
struct sockaddr_in src;
int re;

char *Connect(struct sockaddr_in endport)
{
co:
   fd = socket(AF_INET,SOCK_DGRAM,0);
   memset(buf,0,MTU);
   syn._PLE=0x01;
   packs._TYPE =0x00;
   packs._DATA[0] = syn._PLE;
   pack = &packs;
   Sleep(1000);
   sendto(fd,pack,2,0,(struct sockaddr*)&endport,&len);
   int count = recvfrom(fd,&buf,MTU,MSG_DONTWAIT,&src,&len);
   pack = &buf;
    if (pack->_TYPE == 0x01&&pack->_DATA[0] == 0x01)
    {
        struct UFD ufd;
        ufd.EndPort = endport;
        ufd.fd = fd;
        pthread_t id;
        int ret = pthread_create(&id,NULL,(void *)KeepConnect,(void *)&ufd);
        if (ret!=0)
        {
            return -1;
        }
        char *Ufd ;
        Ufd = &ufd; 
        return *Ufd;
    }
    else
    {
        re++;
        if(re!=5)goto co;
        return -1;
    }
    
}

char buffer[MTU];
struct Pack *keep;
struct Pack *cheak;
void KeepConnect(void *ufds)
    {
       struct UFD *ufd ;
       ufd = ufds;
      keep ->_TYPE =0x03;
      keep->_DATA [0]=0x01;
      memset(buffer,0,MTU);
      int ret = 0;
      while (1)
      {
         Sleep(1000);
         for(size_t i = 0;i != 5;i++)
         {
         sendto(ufd->fd,keep,2,0,(struct sockaddr *)&ufd->EndPort,&len);
         }
          if(recvfrom(ufd->fd,&buffer,MTU,MSG_DONTWAIT,&src,&len) == -1 || ret == 5){
              close(ufd->fd);
              break;
          }
        cheak =  &buffer; 
         if(cheak->_TYPE = 0x05 && cheak->_DATA = 0x01)
         {
            close(ufd->fd);
            break;
         }
        if (cheak->_TYPE = 0x03 && cheak->_DATA  != 0x00)
        {
            ret == 0;
        }
        else
        {
            ret++;
        }
        
        
      }
      
    }

    int MackINIT()
    {

    }

