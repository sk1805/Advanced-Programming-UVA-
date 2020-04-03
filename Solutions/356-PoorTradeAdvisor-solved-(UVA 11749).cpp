#include <iostream>
#include<stdio.h>
#include <queue>
#include <string.h>


struct road{
    int c1,c2, val;
    road(int a, int b, int c)
    {
        c1=a;
        c2=b;
        val=c;
    }
};
struct compareRoads{
    bool operator()(const road &l, const road &r)
    {
        return l.val < r.val;
    }
};


using namespace std;
int main()
{
//    printf("Start\n");
    int N,M;
    while(true)
    {
        scanf("%d%d",&N,&M);
        if(N==0 && M==0){break;}
        priority_queue<road,vector<road>,compareRoads> Q;
        for(int i=0;i<M;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            Q.push(road(a,b,c));
        }
        int set[N+1];
        for (int i=0; i<N+1; i++)
        {
            set[i]=i;
        }
        int maxA=Q.top().val;
        while(!Q.empty())
        {
            road r=Q.top();Q.pop();
//            printf("From: %d, To: %d, Val:%d \n",r.c1,r.c2,r.val);
            if(r.val<maxA){break;}
            int x=set[r.c1];
            if(set[r.c1]!=set[r.c2])
            {
                for(int i=1;i<N+1;i++)
                {
                    if(set[i]==x)
                    {
                        set[i]=set[r.c2];
//                        printf("%d %d\n",i,set[i]);
                    }
                }
            }
            
        }
        int CountR[N+1];
        memset(CountR, 0, sizeof(CountR));
        for(int i=1;i<N+1;i++)
        {
            CountR[set[i]]+=1;
        }
        int ans=-1;
        for(int i=1;i<N+1;i++)
        {
           if(CountR[i]>ans)
               ans=CountR[i];
        }
        printf("%d\n",ans);
        while(!Q.empty())
        {
            Q.pop();
        }
//        cout<<endl;
    }
}
