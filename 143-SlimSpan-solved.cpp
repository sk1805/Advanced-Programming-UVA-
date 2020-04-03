#include <iostream>
#include <stdio.h>
#include <string.h>
#include <deque>
#include <algorithm>
#include <limits.h>
using namespace std;
int Parent[101];

struct edge{
    int from, to, value;
    edge(int u, int v, int w)
    {
        from=u;
        to=v;
        value=w;
    }
};

bool coEd(const edge &l, const edge &r)
{
    return l.value < r.value;
}

int find(int i)
{
    if(Parent[i]!=i)
        Parent[i]=find(Parent[i]);
    
    return Parent[i];
    
}

bool foundAll(int n){
    int req=find(0);
    
    for (int i=1;i<n;i++){
        if (find(i)!=req)
            return false;
    }
    
    return true;
}

int main()
{
//    printf("START\n");
    int n,m;
    while (true)
    {
        scanf("%d%d",&n,&m);
        if(n==0 && m==0){break;}
        deque<edge> Edges;
        for(int i=0;i<m;i++)
        {
            int a1,a2,a3;
            scanf("%d%d%d",&a1,&a2,&a3);
            edge e(a1-1,a2-1,a3);
            Edges.push_back(e);
        }
        
        sort(Edges.begin(),Edges.end(),coEd);
//        for(int i=0;i<Edges.size();i++)
//            cout<<Edges[i].value<<" "<<endl;
//        cout<<"------------------"<<endl;
        int span= INT_MAX;
        for(int i=0;i<m;i++)
        {
            //SETUP
            bool flag = false;
            int minV=0;int maxV =0;
            for(int j=0;j<n;j++)
            {
                Parent[j]=j;
            }
            //Kruskals
            for(int j=i;j<m;j++)
            {
                int uR = find(Edges[j].from);int vR = find(Edges[j].to);
                if(uR==vR)
                    continue;
                Parent[uR]=vR;
                if(minV==0 && maxV==0)
                    minV=maxV=Edges[j].value;
                else
                {
                    minV=min(minV,Edges[j].value);
                    maxV=max(maxV,Edges[j].value);
                }
                if(foundAll(n))
                {
                    flag=true;
                    break;
                }
            }
            if(flag)
                span=min(span,(maxV-minV));
        }
        if(span==INT_MAX)
            printf("-1\n");
        else
            printf("%d\n",span);
        
        Edges.clear();
    }
}
