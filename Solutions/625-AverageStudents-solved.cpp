#include <iostream>
#include <deque>
#include <algorithm>
#include <limits.h>
using namespace std;
int main()
{
    deque<int> Val;
    int N;
    while(cin>>N)
    {
        for(int i=0;i<N;i++)
        {
            int x;
            cin>>x;
            Val.push_back(x);
        }
        sort(Val.begin(),Val.end());
        int n=N/2;
        int maxV=-1;
        int minV=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int a=Val.front();int b=Val.back();Val.pop_back();Val.pop_front();
            int c= a+b;
            maxV=max(c,maxV);
            minV=min(c,minV);
        }
        cout<<(maxV-minV)<<endl;
        
    }
}