#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct Co
{
    int x,y;
};

int cw(Co a, Co b, Co c)
{
    return ((a.x*b.y)-(b.x*a.y))+((b.x*c.y)-(c.x*b.y))+((c.x*a.y)-(a.x*c.y));
}

bool check(Co a, Co b, Co c, Co d)
{
    int a1= cw(a,b,c)*cw(a,b,d);
    int a2= cw(c,d,a)*cw(c,d,b);
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
bool in(int a, int b, int c)
{
    if(a>=b && a<=c)
        return true;
    return false;
}
bool inSide(Co a,Co b, int xS, int xE, int yS, int yE)
{
    if(in(a.x,xS,xE) && in(a.y,yS,yE))
        return true;
    if(in(b.x,xS,xE) && in(b.y,yS,yE))
        return true;
    return false;
}

int main()
{
//    printf("Lets Start\n");
    int n;
    Co lineSt,lineEnd,RecTopLeft,RecBotRight,RecBotLeft,RecTopRight;//get from input
    int xStart,xEnd,yStart,yEnd;

    bool intersection;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        intersection=false;
        int left,top,right,bottom;
        scanf("%d%d%d%d%d%d%d%d",&lineSt.x,&lineSt.y,&lineEnd.x,&lineEnd.y,&left,&top,&right,&bottom);
        if(left>right)
        {
            int temp=right;
            right=left;
            left=temp;
        }
        if(bottom>top)
        {
            int temp=top;
            top=bottom;
            bottom=temp;
        }
        RecTopLeft.x=RecBotLeft.x=left;
        RecTopRight.x=RecBotRight.x=right;
        RecTopLeft.y=RecTopRight.y=top;
        RecBotLeft.y=RecBotRight.y=bottom;
        
        xStart=left;
        xEnd=right;
        yStart=bottom;
        yEnd=top;

        if(inSide(lineSt,lineEnd,xStart,xEnd,yStart,yEnd))
        {
            intersection=true;
        }
        else if(mainCheck(lineSt,lineEnd,RecTopLeft,RecBotLeft)|| mainCheck(lineSt,lineEnd,RecTopRight,RecBotRight)||
                mainCheck(lineSt,lineEnd,RecTopLeft,RecTopRight)||mainCheck(lineSt,lineEnd,RecBotLeft,RecBotRight))
        {
            intersection=true;
        }

        if(intersection)
            printf("T\n");
        else
            printf("F\n");
    }
}
