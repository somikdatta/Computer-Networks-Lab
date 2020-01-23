#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>

int main(){
  int welcomeSocket,newSocket,newSocket1,newSocket2,port;
  printf("Enter port to listen on: ");
  scanf("%d",&port);
  int buffer[6];
  int buffer1[6];
  int buffer2[6];
  struct sockaddr_in serverAddr;
  struct sockaddr_storage serverStorage;
  struct sockaddr_storage serverStorage1;
  struct sockaddr_storage serverStorage2;
  socklen_t addr_size;
  socklen_t addr_size1;
  socklen_t addr_size2;
  welcomeSocket = socket(PF_INET,SOCK_STREAM,0);
  serverAddr.sin_family=AF_INET;
  serverAddr.sin_port=htons(port);
  serverAddr.sin_addr.s_addr= inet_addr("127.0.0.1");
  bind(welcomeSocket,(struct sockaddr*)& serverAddr,sizeof(serverAddr));
  if(listen(welcomeSocket,5)==0){
    printf("Listening\n");
  }
  else{
    printf("Error\n");
  }
  addr_size=sizeof(serverStorage);
  addr_size1=sizeof(serverStorage1);
  addr_size2=sizeof(serverStorage2);
  newSocket = accept(welcomeSocket,(struct sockaddr*)&serverStorage,&addr_size);
  newSocket1 = accept(welcomeSocket,(struct sockaddr*)&serverStorage1,&addr_size1);
  newSocket2 = accept(welcomeSocket,(struct sockaddr*)&serverStorage2,&addr_size2);
  recv(newSocket,buffer,sizeof(buffer),0);
  recv(newSocket1,buffer1,sizeof(buffer1),0);
  recv(newSocket2,buffer2,sizeof(buffer2),0);
  int sum,sum1,sum2;
  for(int i=0;i<5;i++){
    sum+=buffer[i];
    sum1+=buffer1[i];
    sum2+=buffer2[i];
  }
  buffer[5]=sum;
  buffer1[5]=sum1;
  buffer2[5]=sum2;
  bubblesort(buffer);
  bubblesort(buffer1);
  bubblesort(buffer2);
  send(newSocket,&buffer,sizeof(buffer),0);
  send(newSocket1,&buffer1,sizeof(buffer1),0);
  send(newSocket2,&buffer2,sizeof(buffer2),0);
  return 0;
}
void inline bubblesort(int arr[]){
  for(int i=0;i<5;i++){
    for(int j=0;j<5-i-1;j++){
      int temp=arr[j];
      arr[j]=arr[j+1];
      arr[j+1]=temp;
    }
  }
}
