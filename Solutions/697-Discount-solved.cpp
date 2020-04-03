#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int main()
{
//    cout<<"Start"<<endl;
    int N;
    while(cin>>N)
    {
        deque<int> discounts;int ans=0;
        for(int i=0;i<N;i++)
        {
            int a,b;
            cin>>a>>b;
            ans+=a;
            discounts.push_back((a-b));
        }
        sort(discounts.begin(),discounts.end());
        if(ans>=100)
        {
            int n;
            if(N%2==0)
                n=N/2;
            else
                n=(N-1)/2;
            for(int i=0;i<n;i++)
            {
                ans-=discounts.back();discounts.pop_back();
            }
        }
        cout<<ans<<endl;
        discounts.clear();
    }
}
