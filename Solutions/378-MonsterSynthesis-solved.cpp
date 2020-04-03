#include <iostream>
#include <stdio.h>
#include <deque>
#include <limits.h>
#include <algorithm>
#include <queue>
using namespace std;
struct forQ{
    int i, d;
    forQ(int a1,int a2)
    {
        i=a1;
        d=a2;
    }
};
struct compareQ{
    bool operator()(const forQ &l, const forQ &r)
    {
        return l.d > r.d;
    }
};
struct synRule{
    int levelBefore,Cost;
    synRule(int lb,int c)
    {
        levelBefore=lb;
        Cost=c;
    }
};
struct monster{
    int price,level, syn_rules;
    deque<synRule> Rules;
};

monster Monsters[101];

int djikstras(int N, int minL,int maxL)
{
    int Cost[N];
    
    for(int i=0;i<N;i++)
    {
        Cost[i]=INT_MAX;
    }
    
    Cost[1]=0;
    
    priority_queue<forQ,vector<forQ>,compareQ> Q;
    Q.push(forQ(1,0));
    while(!Q.empty())
    {
        forQ u=Q.top();Q.pop();
        if(u.i==0){break;}
        int tI=u.i;
        for(int i=0;i<Monsters[tI].Rules.size();i++)
        {
            int l=Monsters[tI].Rules[i].levelBefore;
            int c=Monsters[tI].Rules[i].Cost;
            if(Monsters[l].level>=minL && Monsters[l].level<=maxL)
            {
                if((Cost[tI]+c)<Cost[l])
                {
                    Cost[l]=Cost[tI]+c;
                    Q.push(forQ(l,Cost[l]));
                }
            }
            else
            {
                continue;
            }
        }
    }
    return Cost[0];
}
int main()
{
//        printf("Start\n");
    int M,N;
    //while(scanf("%d%d",&M,&N))
    while(cin>>M>>N)
    {
        //monster Monsters[N+1];
        for(int i=1;i<N+1;i++)
        {
            //scanf("%d%d%d",&Monsters[i].price,&Monsters[i].level,&Monsters[i].syn_rules);
            cin>>Monsters[i].price>>Monsters[i].level>>Monsters[i].syn_rules;
            Monsters[i].Rules.clear();
            for(int j=0;j<Monsters[i].syn_rules;j++)
            {
                int a,b;
                //scanf("%d%d",&a,&b);
                cin>>a>>b;
                Monsters[i].Rules.push_back(synRule(a,b));
            }
        }
        Monsters[0].level=Monsters[1].level;
//        Monsters[0].price=0;
        for(int i=1;i<N+1;i++){
            
            Monsters[i].Rules.push_back(synRule(0,Monsters[i].price));
        }
        
        int mainAns=INT_MAX;int levelz=Monsters[1].level;
        for (int i=(levelz-M); i<=levelz; i++)
        {
            mainAns= min(mainAns,djikstras(N+1,i,i+M));
           
        }
//        printf("%d\n",mainAns);
        cout<<mainAns<<endl;
        
    }
    
}

