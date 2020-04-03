#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct Co
{
    long long int x,y;
};

struct Segment
{
    Co starting, ending;
};

long long int cw(Co a, Co b, Co c)
{
    return ((a.x*b.y)-(b.x*a.y))+((b.x*c.y)-(c.x*b.y))+((c.x*a.y)-(a.x*c.y));
}

bool check(Co a, Co b, Co c, Co d)
{
    long long int a1= cw(a,b,c)*cw(a,b,d);
    long long int a2= cw(c,d,a)*cw(c,d,b);
    if(a1<0 && a2<0)
        return true;
    return false;
}
bool inRange(Co b, Co c, Co a)
{
    if(a.x>=min(b.x,c.x) && a.x<=max(b.x,c.x) && a.y>=min(b.y,c.y) && a.y<=max(b.y,c.y))
        return true;
    return false;
}
bool check2(Co a, Co b, Co c, Co d)
{
    if(cw(a,b,c)==0 && inRange(a, b, c))
        return true;
    if(cw(a,b,d)==0 && inRange(a, b, d))
        return true;
    if(cw(c,d,a)==0 && inRange(c, d, a))
        return true;
    if(cw(c,d,b)==0 && inRange(c, d, b))
        return true;
    return false;
}
bool mainCheck(Co a, Co b, Co c, Co d)
{
    if(check(a,b,c,d))
        return true;
    if(check2(a,b,c,d))
        return true;
    return false;
}
int main()
{
    // printf("Lets Start\n");
    long long int n;
//    scanf("%d",&n);
    cin>>n;
    for(long long int i=0;i<n;i++)
    {
        long long int seg;
//        scanf("%d",&seg);
        cin>>seg;
        bool Isolated[seg];
        Segment Segments[seg];
        for(long long int s=0;s<seg;s++)
        {
            Segment S;
//            scanf("%d%d%d%d",&S.starting.x,&S.starting.y,&S.ending.x,&S.ending.y);
            cin>>S.starting.x>>S.starting.y>>S.ending.x>>S.ending.y;
            Segments[s]=S;
        }
        long long int main_count=0;
        memset(Isolated,false,sizeof(Isolated));
        for(long long int j=0;j<seg-1;j++)
        {
            for(long long int k=j+1;k<seg;k++)
            {
                if(mainCheck(Segments[j].starting, Segments[j].ending, Segments[k].starting, Segments[k].ending))
                {
                    Isolated[j]=true;
                    Isolated[k]=true;
                }
            }
        }
        for(long long int q=0;q<seg;q++)
        {
            if(!Isolated[q])
            {
                main_count++;
            }
        }
//        printf("%d\n",main_count);
        cout<<main_count<<endl;
        //        Segments.clear();
    }
    return 0;
}
