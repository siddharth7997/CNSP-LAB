/* A program to create a socket using socket systemcall*/
#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<stdlib.h>
int main()
{
        int sfd,n,len,s,nsfd,i;
        struct sockaddr_in sa;
        if((sfd=socket(AF_INET,SOCK_STREAM,0))<0)
        {
                perror("socket error");
                exit(-1);
        }
        printf("\nSOCKET CREATED....\nsfd:%d\n",sfd);
        close(sfd);
        return 0;
}



/*
siddharth@siddharth-Inspiron-N5050:~/Desktop/nplab2$ ./a.out

SOCKET CREATED....
sfd:3
*/