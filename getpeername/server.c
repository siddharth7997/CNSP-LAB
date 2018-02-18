/*GET PEER NAME SERVER*/

#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
int main()
{
        int s,s2,t,len;
        struct sockaddr_in local,rem;
        char str[100];
        s=socket(AF_INET,SOCK_STREAM,0);
        if(s==-1)
        {
                perror("socket");
                exit(1);
        }
        bzero((char *)&local,sizeof(local));
        local.sin_family=AF_INET;
        
        char port[100];
        printf("enter the port number");
        scanf("%s",port);
        local.sin_port=htons(atoi(port));
        
        local.sin_addr.s_addr=htonl(INADDR_ANY);
        
        if(bind(s,(struct sockaddr *)&local,sizeof(local))==-1)
        {
                perror("bind");
                exit(1);
        }
        if(listen(s,5)==-1)
        {
                perror("listen");
                exit(1);
        }
        for(;;)
        {
                int done,n;
                printf("waiting for a connection......\n");
                t=sizeof(rem);
                s2=accept(s,(struct sockaddr *)&rem,&t);
                if(s2==-1)
                {
                        perror("accept");
                        exit(1);
                }
        }
        close(s2);
        return 0;
}
