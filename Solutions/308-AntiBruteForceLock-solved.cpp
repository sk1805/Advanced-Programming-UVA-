#include <iostream>
#include <deque>
#include<string.h>
#include <cmath>
#include <queue>
#include <algorithm>
#include <limits.h>
#include<stdio.h>
#include<set>

using namespace std;
struct keys
{
    int val1,val2,val3,val4;
}KeysList[501];
struct Edges
{
    int id, key;//, from;
};


int fun1(int i, int j)
{
    int temp=abs(KeysList[i].val1-KeysList[j].val1);
    if(temp>5){
        return 10-temp;
    }
    else{
        return temp;
    }
}
int fun2(int i, int j){
    int temp=abs(KeysList[i].val2-KeysList[j].val2);
    if(temp>5){
        return 10-temp;
    }
    else{
        return temp;
    }
    
}
int fun3(int i, int j){
    int temp=abs(KeysList[i].val3-KeysList[j].val3);
    if(temp>5){
        return 10-temp;
    }
    else{
        return temp;
    }
    
}
int fun4(int i, int j){
    int temp=abs(KeysList[i].val4-KeysList[j].val4);
    if(temp>5){
        return 10-temp;
    }
    else{
        return temp;
    }
}
int dis(int a, int b)
{
    int dist=0;
    dist+=fun1(a, b);
    dist+=fun2(a, b);
    dist+=fun3(a, b);
    dist+=fun4(a, b);
    return dist;
    
}

int main()
{
//        cout<<"Start"<<endl;
    int cases;
    scanf("%d",&cases);
    for(int c=0;c<cases;c++){
        
        int n;
        int starter_pos=-1;
        int starter_val=INT_MAX;
        scanf("%d",&n);
        int N=n+1;
        
        keys k;k.val1=0;k.val2=0;k.val3=0;k.val4=0;
        KeysList[0]=k;
        
        for(int i=1;i<N;i++)
        {
            keys x;
            int temp;
            scanf("%d",&temp);
            
            x.val1=temp/1000;
            x.val2=(temp/100)%10;
            x.val3=(temp/10)%10;
            x.val4=temp%10;
            KeysList[i]=x;
            int t=dis(0, i);
            if(t<starter_val)
            {
                starter_val=t;starter_pos=i;
            }

        }
        //Start Calculation xxxxxxxxxxx
        int answer=0;
        int included=0;
        int key[N];
        bool visited[N];
        for(int i=1;i<N;i++)
        {
            key[i]=INT_MAX;
            visited[i]=false;
        }
        key[starter_pos]=starter_val;
        //MAIN LOOP --START
        while(included!=n)
        {
            int min=INT_MAX,pos=-1;
            for(int i=1;i<N;i++)
            {
                if(key[i]<min && !visited[i]){
                    min=key[i];pos=i;
                }
            }
            //            printf("position: %d, value: %d \n",pos,min);
            answer+=min;visited[pos]=true;included++;
            for(int i=1;i<N;i++)
            {
                int t= dis(pos,i);
                if(!visited[i] && t<key[i])
                {
                    key[i]=t;
                }
            }
        }
        //MAIN LOOP --END
        printf("%d\n",answer);
        
    }
    return 0;
}
