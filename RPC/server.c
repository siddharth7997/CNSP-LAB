/*RCMD server*/

#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#define MAX 1024
int main()
{
        int sockfd,addrlen,new,n;
        char buff1[MAX];
        struct sockaddr_in serv_addr,peer;
        sockfd=socket(AF_INET,SOCK_STREAM,0);
        if(sockfd==-1)
        {
                perror("error in server");
                exit(1);
        }
        serv_addr.sin_family=AF_INET;
        char port[100];
        printf("enter port no");
        scanf("%s",port);
        serv_addr.sin_port=htons(atoi(port));
        
        serv_addr.sin_addr.s_addr=inet_addr("192.168.1.3");
        
        if(bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
        {
                perror("error in server binding");
                exit(1);
        }
        if(listen(sockfd,5)<0)
        {
                perror("error in server listening");
                exit(1);
        }
        for(;;)
        {
                if((new=accept(sockfd,(struct sockaddr*)&peer,&addrlen))<0)
                {
                        perror("error in server accept");
                        exit(1);
                }
                if((fork())==0)
                {
                        for(;;)
                        {
                                if((n=read(new,buff1,MAX))<0)
                                   {
                                        perror("error in server read");
                                        exit(1);
                                }
                                if(n==0)
                                        break;
                                buff1[n]='\0';
                                if(!strcmp("exit",buff1))
                                {
                                        printf("\a\a server is exciting");
                                        exit(1);
                                }
                                close(1);
                                if(dup(new)<0)
                                        printf("\n server:dup system call failure");
                                fflush(stdout);
                                system(buff1);
                                if((write(new,"\n",1))<0)
                                        perror("write error");
                        }
                        close(new);
                }
        }
}


