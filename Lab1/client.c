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
  int clientSocket;
  char buffer[1024];
  struct sockaddr_in serverAddr;
  socklen_t addr_size;
  clientSocket = socket(PF_INET,SOCK_STREAM,0);
  serverAddr.sin_family=AF_INET;
  serverAddr.sin_port=htons(7891);
  serverAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
  addr_size=sizeof(serverAddr);
  connect(clientSocket,(struct sockaddr*)&serverAddr,addr_size);
  recv(clientSocket,buffer,1024,0);
  printf("Data recieved: %s",buffer);
  return 0;
}
