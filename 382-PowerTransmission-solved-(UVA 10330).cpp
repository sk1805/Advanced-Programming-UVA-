#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
#include <limits.h>
#define MaxNodes 205
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
//        printf("Lets Start\n");
    int N;
    while(cin>>N)
    {
        memset(Graph, 0, sizeof(Graph));
        
        for(int i=1;i<=N;i++)
        {
            int a;
            cin>>a;
            Graph[i+100][i]=a;
        }
        int M;
        cin>>M;
        for(int i=0;i<M;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            Graph[a][b+100]=c;
        }
        int S,E;
        cin>>S>>E;
        for(int i=0;i<S;i++)
        {
            int a;
            cin>>a;
            Graph[0][a+100]=INT_MAX;
        }
        for(int i=0;i<E;i++)
        {
            int a;
            cin>>a;
            Graph[a][N+101]=INT_MAX;
        }
        
        int ans =ffs(N+102,0,N+101);
        printf("%d\n",ans);
    }
    return 0;
}

