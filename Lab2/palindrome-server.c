#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>

int main(){
        int welcomeSocket,newSocket,port,number,copy,newnum=0,flag;
        printf("Enter port to listen on: ");
        scanf("%d",&port);
        char buffer[1024];
        struct sockaddr_in serverAddr;
        struct sockaddr_storage serverStorage;
        socklen_t addr_size;
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
        newSocket = accept(welcomeSocket,(struct sockaddr*)&serverStorage,&addr_size);
        recv(newSocket,buffer,1024,0);
        printf("Number received from client: %s\n",buffer);
        number=atoi(buffer);
        copy=number;
        while(copy>0){
          int d=copy%10;
          newnum=newnum*10+d;
          copy/=10;
        }
        if(newnum==number){
          flag=0;
        }else{
          flag=1;
        }
        send(newSocket,&flag,sizeof(int),0);
        close(newSocket);
        close(welcomeSocket);
        return 0;
      }
