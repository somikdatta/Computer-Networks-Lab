#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>

int main(){
  int clientSocket,port,flag;
  printf("Enter port to send data: ");
  scanf("%d",&port);
  char buffer[1024];
  struct sockaddr_in serverAddr;
  socklen_t addr_size;
  clientSocket = socket(PF_INET,SOCK_STREAM,0);
  serverAddr.sin_family=AF_INET;
  serverAddr.sin_port=htons(port);
  serverAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
  addr_size=sizeof(serverAddr);
  connect(clientSocket,(struct sockaddr*)&serverAddr,addr_size);
  printf("Enter string to check for palindrome: ");
  scanf("%s", &buffer);
  send(clientSocket,buffer,sizeof(buffer),0);
  recv(clientSocket,&flag,sizeof(int),0);
  if(flag==0){
    printf("%s is a palindrome\n", buffer);
  }else{
    printf("%s is not a palindrome\n", buffer);
  }
  close(clientSocket);
  return 0;
}
