#include <iostream>
#include <deque>
#include <limits.h>
#include <algorithm>
using namespace std;

deque<int> numbers;

bool check(int i)
{
//    int temp=0;
    for(int j=0;j<numbers.size();j++)
    {
        if(i%(2*numbers[j])>= (numbers[j]-5))
        {
            return false;
        }
    }
    return true;
}
void printTime(int i)
{
    int h= i/3600;
    i=i%3600;
    int m=i/60;
    i=i%60;
    int s=i;
    string hS,mS,sS;
    //hour
    if(h>9)
        hS=to_string(h);
    else
        hS='0'+to_string(h);
    //min
    if(m>9)
        mS=to_string(m);
    else
        mS='0'+to_string(m);
    //sec
    if(s>9)
        sS=to_string(s);
    else
        sS='0'+to_string(s);
    cout<<hS<<":"<<mS<<":"<<sS<<endl;
}
int main()
{
    //    cout<<"start"<<endl;
    numbers.clear();
    int n;
    while(cin>>n)
    {
        int minN=INT_MAX;
        if(numbers.empty() && n==0)
        {
            int a,b;
            cin>>a>>b;
            if(a==0 && b==0)
            {
                return 0;
            }
        }
        else
        {
            while(n!=0)
            {
                minN=min(minN,n);
                numbers.push_back(n);
                cin>>n;
            }
            
        }
        bool within5H=false;int ans=-1;
        for(int i=(minN*2);i<=18000;i++)
        {
            if(check(i))
            {
                within5H=true;
                ans=i;
                break;
            }
        }
        if(within5H)
            printTime(ans);
        else
            cout<<"Signals fail to synchronise in 5 hours"<<endl;
        
        numbers.clear();  
    }
    
    return 0;
}
