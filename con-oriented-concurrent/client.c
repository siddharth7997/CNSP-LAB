/*connection oriented concurrent echo client*/
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
int main()
{
        int s,t,len,a;
        struct sockaddr_in rem;
        char str[100];
        
        s=socket(AF_INET,SOCK_STREAM,0);
        if(s==-1)
        {
                perror("socket");
                exit(1);
        }
        printf("trying to connect to.......\n");
        bzero((char *)&rem,sizeof(rem));
        rem.sin_family=AF_INET;
        
        char port[100],ip[100];
        printf("enter the ip address");scanf("%s",ip);
        printf("enter the port");scanf("%s",port);
        
        rem.sin_port=htons(atoi(port));
        rem.sin_addr.s_addr=inet_addr(ip);
        a=connect(s,(struct sockaddr *)&rem,sizeof(rem));
        if(a==-1)
        {
                perror("connect");
                exit(1);
        }
        printf("connected\n");
        while(printf(">"),fgets(str,100,stdin),!feof(stdin))
        {
                if(send(s,str,strlen(str),0)==-1)
                {
                        perror("send");
                        exit(1);
                }
                if((t=recv(s,str,100,0))>0)
                  {
                        str[t]='\0';
                        printf("echo>%s",str);
                }
                else
                {
                        if(t<0)
                                perror("recv");
                        else
                                printf("server closed connection\n");
                        exit(1);
                }
        }
        close(s);
        return 0;
}
