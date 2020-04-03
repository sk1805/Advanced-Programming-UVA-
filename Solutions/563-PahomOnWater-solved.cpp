#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
#include <limits.h>
#define MaxNodes 301
using namespace std;

struct pad{
    int x,y,r;
    double Frequency;
    pad(){}
    pad(double f1,int x1, int y1, int r1)
    {
        Frequency=f1;
        x=x1;
        y=y1;
        r=r1;
    }
}Pads[MaxNodes];

int Graph[MaxNodes][MaxNodes],parent[MaxNodes];//,Graph2[MaxNodes][MaxNodes],parent2[MaxNodes];
bool bfs(int N,int src, int trgt)
{
    bool visited[N];
    memset(visited, false, sizeof(visited));
    queue<int> Q;
    Q.push(src);
    visited[src]=true;
    parent[src]=-1;
    while (!Q.empty())
    {
        int u = Q.front();Q.pop();
        for (int n=1; n<N; n++)
        {
            if (!visited[n] && Graph[u][n] > 0)
            {
                Q.push(n);
                parent[n] = u;
                visited[n] = true;
            }
        }
    }
    return (visited[trgt]==true);
    
}
int ffs(int N,int src, int trgt)
{
    //    for (int u = 0; u < N; u++)
    //        for (int v = 0; v < N; v++)
    //            resGraph[u][v] = mainGraph[u][v];
    
    int maxflow=0;
    
    while(bfs(N,src,trgt))
    {
        int path=INT_MAX;
        int x= trgt;
        while(x!=src)
        {
            path=min(path,Graph[parent[x]][x]);
            x=parent[x];
        }
        x=trgt;
        while(x!=src)
        {
            Graph[parent[x]][x]-=path;
            Graph[x][parent[x]]+=path;
            x=parent[x];
        }
        maxflow+=path;
    }
    return maxflow;
}
bool Intersection(int a,int b){
    int dist=(Pads[a].x-Pads[b].x)*(Pads[a].x-Pads[b].x)+(Pads[a].y-Pads[b].y)*(Pads[a].y-Pads[b].y);
    int rad=(Pads[a].r+Pads[b].r)*(Pads[a].r+Pads[b].r);
    if (dist<=rad)
        return true;
    else
        return false;
}
int main()
{
//            printf("Lets Start\n");
    int K;
    scanf("%d",&K);
    for(int i=0;i<K;i++)
    {
        memset(Graph, 0, sizeof(Graph));
//        memset(Graph2, 0, sizeof(Graph2));
        int N;
        int rp, vp;
        scanf("%d",&N);
        for(int j=1;j<N+1;j++)
        {
            
            scanf("%lf%d%d%d",&Pads[j].Frequency,&Pads[j].x,&Pads[j].y,&Pads[j].r);
            if(Pads[j].Frequency==400.0)
            {
                rp=j;
            }
            else if(Pads[j].Frequency==789.0)
            {
                vp=j;
            }
        }
        for(int j=1;j<N;j++)
        {
            for(int k=j+1;k<N+1;k++)
            {
                if(Intersection(j,k) && Pads[j].Frequency<Pads[k].Frequency)
                {

                    Graph[j][k]=1;
//                    Graph2[j][k]=1;
                }
                else if(Intersection(j,k) && Pads[k].Frequency<Pads[j].Frequency)
                {
                    Graph[k][j]=1;
//                    Graph2[k][j]=1;
                }
            }
        }
        Graph[0][rp]=2;
        Graph[vp][N+1]=2;
        int ans=ffs(N+2, 0, N+1);
        if(ans==2)
        {
            printf("Game is VALID\n");
        }
        else
        {
            printf("Game is NOT VALID\n");
        }
        
    }
    return 0;
}

