//SuperSale - 218

#include <iostream>
#include <deque>
#include <string.h>
using namespace std;
//struct object{
//    int P,W;
//};

//deque<object> objects;

int value[31];

int maximum(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}
int main()
{
//    cout<<"Start"<<endl;
    int T,N,G,MW,count(0);
    cin>>T;
    for(int T_temp=0;T_temp<T;T_temp++)
    {
        memset(value, 0, sizeof(value));
        cin>>N;
        for(int N_temp=0;N_temp<N;N_temp++)
        {
            int P, W;
            cin>>P>>W;
            for(int j=30;j>=W;j--)
            {
                value[j] = maximum(value[j], value[j-W]+P);
            }
        }
        cin>>G;
        for(int G_temp=0;G_temp<G;G_temp++)
        {
            cin>>MW;
            int ans=value[MW];
            count+=ans;
        }
        
        cout<<count<<endl;
        count=0;
    }
}
