#include<bits/stdc++.h>
using namespace std;

class dv
{
    int a[1000][1000];
    int n;
    int dist[1000];
    int prev[1000];

    public:
    dv()
    {
        cout<<"enter the no of nodes\n";
        cin>>n;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                a[i][j]=-1;
            }
        }
    }
    public:
    void update(int r,int c,int n)
    {
        a[r][c]=a[c][r]=n;
    }
    void reset()
    {
        for(int i=0;i<n;i++)
        {
            dist[i]=INT_MAX;
            prev[i]=-1;
        }
    }
    void input()
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                cout<<"enter distance b/w "<<i<<" "<<j<<":";
                cin>>a[i][j];
                a[j][i]=a[i][j];
            }
        }
    }
    void display()
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    bool allvisited(bool ak[])
    {
        for(int i=0;i<n;i++)
        {
            if(ak[i]==false)
            return false;
        }
        return true;
    }

    void printcurrent(int table[])
    {
        for(int i=0;i<n;i++)
        cout<<i<<":"<<table[i]<<" ";
        cout<<endl;
    }

    void computeRoute(int source)
    {
        reset();
        dist[source]=0;
        bool visited[n];
        memset(visited,0,sizeof(visited));

        cout<<"steps to compute the route============\n";

        while(!allvisited(visited))
        {
            //selecting the non visited least key 
            int minindex;
            int minkey=INT_MAX;
            for(int i=0;i<n;i++)
            {
                if(!visited[i] and dist[i]<minkey)
                {
                    minindex=i;
                    minkey=dist[i];
                }
            }

            visited[minindex]=true;


            for(int i=0;i<n;i++)
            {
                if(!visited[i] and (a[i][minindex]>=0) and ((dist[minindex]+a[i][minindex])<dist[i]))
                {
                    dist[i]=dist[minindex]+a[i][minindex];
                    prev[i]=minindex;
                }
            }
            cout<<"current index is:"<<minindex<<endl;
            cout<<"current table";
            printcurrent(dist);
        }
        
        cout<<"\n\nThe source is:"<<source<<endl;
        for(int i=0;i<n;i++)
        {
            if(i!=source)
            {
                cout<<"route to "<<i<<"==>";
                traceroutei(source,i);
                cout<<"cost"<<dist[i]<<"\n";
            }
        }

    }

    void traceroutei(int source,int current)
    {
        if(prev[current]==-1)
        {
            cout<<source<<" ";
            return;
        }
        traceroutei(source,prev[current]);
        cout<<current<<" ";
    }

    
};

int main()
{
    dv k;
    k.input();
    while(1)
    {
        int n;
        printf("\noptions:\n1.display\n2.computeroute\n3.update n/w\n");
        cin>>n;
        switch(n)
        {
            case 1:k.display();break;
            case 2:cout<<"enter the source";int sc;cin>>sc;k.computeRoute(sc);break;
            case 3:int r,c,n;cout<<"enter the two nodes";cin>>r>>c;
            cout<<"enter the update";cin>>n;k.update(r,c,n);
            break;
            default:exit(0);break;
        }
    }
}