#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
#include <limits.h>
#define MaxNodes 1025
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
    int k,p;
    while(true)
    {
        scanf("%d%d",&k,&p);
        if(k==0 && p==0){break;}
        memset(Graph, 0, sizeof(Graph));
        int total_questions=0;
        for(int i=0;i<k;i++)
        {
            int a;
            scanf("%d",&a);
            Graph[0][i+1]=a;
            total_questions+=a;
        }
        int x=k+1;
        int sink=k+p+1;
        for(int i=0;i<p;i++)
        {
            int a;
            scanf("%d",&a);
            Graph[i+x][sink]=1;
            for(int j=0;j<a;j++)
            {
                int b;
                scanf("%d",&b);
                Graph[b][i+x]=1;
            }
            
        }
        
        int ans =ffs(sink+1,0,sink);
        
        if(ans==total_questions)
            printf("1\n");
        else
            printf("0\n");

    }
    return 0;
}
