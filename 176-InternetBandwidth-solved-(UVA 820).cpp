#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
#include <limits.h>
#define MaxNodes 101
using namespace std;

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
int main()
{
//    printf("Lets Start\n");
    int N,source,target,C,count(1);
    while(true)
    {
        scanf("%d",&N);
        if(N==0){break;}
        scanf("%d%d%d",&source,&target,&C);
//        int Graph[N][N];
        memset(Graph, 0, sizeof(Graph));
        for(int i=0;i<C;i++)
        {
            int a,b,w;
            scanf("%d%d%d",&a,&b,&w);
            Graph[a][b]+=w;
            Graph[b][a]+=w;
        }
        int ans =ffs(N+1,source,target);
        printf("Network %d\n",count++);
        printf("The bandwidth is %d.\n\n",ans);
    }
    return 0;
}
