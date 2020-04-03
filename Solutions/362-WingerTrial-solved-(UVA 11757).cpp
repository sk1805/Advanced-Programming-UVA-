#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
#include <limits.h>
#define MaxNodes 205
using namespace std;

struct point{
    int x,y;
    point(){}
    point(int x1, int y1)
    {
        x=x1;
        y=y1;
    }
}Point[MaxNodes];

int Graph[MaxNodes][MaxNodes],parent[MaxNodes];
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
bool Intersection(point a,point b, int d){
    int dist=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
    int rad=d*d*4;
    if (dist<=rad)
        return true;
    else
        return false;
}
int main()
{
    //            printf("Lets Start\n");
    int L,W,N,d;int count=0;
    while(true)
    {
        scanf("%d%d%d%d",&L,&W,&N,&d);
        if(L==0 && W==0 && N==0 && d==0){break;}
        for(int i=1;i<N+1;i++)
        {
            scanf("%d%d",&Point[i].x,&Point[i].y);
        }
        memset(Graph, 0, sizeof(Graph));
        int start=0;int end=(2*N)+1;
        for(int i=1;i<N+1;i++)
        {
            Graph[(2*i)-1][2*i]=1;
            if(Point[i].y<=d)
            {
                Graph[start][(2*i)-1]=1;
            }
            if((W-Point[i].y)<=d)
            {
                Graph[2*i][end]=1;
            }
        }
        for(int i=1;i<N+1;i++)
        {
            for(int j=1;j<N+1;j++)
            {
                if(i==j)
                    continue;
                else
                    if(Intersection(Point[i], Point[j], d))
                    {
                        Graph[i*2][j*2-1] = 1;
                    }
            }
        }
        int ans= ffs(end+1, start, end);
        printf("Case %d: %d\n",++count,ans);
        
        
    }
    return 0;
}

