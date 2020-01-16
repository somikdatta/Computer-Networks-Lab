#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>

// #define BUFSIZE 1024
// #if 0
// struct in_addr{
//   unsigned int s_addr;
// };
// struct sockaddr_in{
//   unsigned short int sin_family;
//   unsigned short int sin_port;
//   struct in_addr sin_addr;
//   unsigned char sin_zero[...];
//
// };
//
// struct hostent{
//   char *h_name;
//   char **h_aliases;
//   char h_addrtype;
//   int h_length;
//   char **h_addr_list;
// }
//
// void error(char *msg){
//   perror(msg);
//   exit(1);
// }

int main(){
        int welcomeSocket,newSocket;
        char buffer[1024];
        struct sockaddr_in serverAddr;
        struct sockaddr_storage serverStorage;
        socklen_t addr_size;
        welcomeSocket = socket(PF_INET,SOCK_STREAM,0);
        serverAddr.sin_family=AF_INET;
        serverAddr.sin_port=htons(7891);
        serverAddr.sin_addr.s_addr= inet_addr("127.0.0.1");
        bind(welcomeSocket,(struct sockaddr*)& serverAddr,sizeof(serverAddr));
        if(listen(welcomeSocket,5)==0){
          printf("Listening");
        }
        else{
          printf("Error\n");
        }
        addr_size=sizeof(serverStorage);
        newSocket = accept(welcomeSocket,(struct sockaddr*)&serverStorage,&addr_size);
        strcpy(buffer,"Hello World!");
        send(newSocket,buffer,13,0);
        return 0;
      }
