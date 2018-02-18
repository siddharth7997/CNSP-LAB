/*GET PEER NAME CLIENT*/

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
int main()
{
        int s;
        struct sockaddr_in server,addr;
        socklen_t len;
        s=socket(AF_INET,SOCK_STREAM,0);
        server.sin_family=AF_INET;
        inet_aton("192.168.1.3",&server.sin_addr);
        
        char port[100];
        printf("enter the port number");
        scanf("%s",port);
        
        server.sin_port=htons(atoi(port));
        if(connect(s,(struct sockaddr *)&server,sizeof(server))<0)
        {
                perror("connect");
                exit(0);
        }
        len=sizeof(addr);
        getpeername(s,(struct sockaddr *)&addr,&len);
        //printf("peer IP address:%s\n",inet_ntoa(addr.sin_addr));
        printf("peer port:%d\n",ntohs(addr.sin_port));
        return 0;
}
