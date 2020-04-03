#include <iostream>
#include <deque>
#include <cmath>
#include <queue>
#include <algorithm>
#include <string.h>
#include <iomanip>
using namespace std;
struct pos{
    int x,y;
    
};
deque<pos> stones;
double Distance(pos a, pos b)
{
    int xA= (a.x-b.x);
    int yA=(a.y-b.y);
    return sqrt(pow(xA,2)+pow(yA,2));
}

int main()
{
//    cout<<"Start"<<endl;
    int n,x,y;
    int count=0;
    while(true)
    {
        cin>>n;
        if(n==0){break;}
        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            pos p;
            p.x=x;p.y=y;
            stones.push_back(p);
        }
        double mainGraph[n][n];
        memset(mainGraph, 0, sizeof(mainGraph));
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                double distance = Distance(stones[i], stones[j]);
                mainGraph[i][j]=mainGraph[j][i]=distance;
            }
        }
        //Print Graph - for debugging
//        for(int i=0;i<n;i++)
//        {
//            for (int j=0; j<n; j++) {
//                cout<<mainGraph[i][j]<<" ";
//            }
//            cout<<endl;
//        }

        // FLOYD WARSHALL
        for(int k=0;k<n;k++)
        {
            for (int i=0; i<n; i++)
            {
                for (int j=0; j<n; j++)
                {
                    double temp=max(mainGraph[i][k],mainGraph[k][j]);
                    if(temp<mainGraph[i][j])
                    {
                        mainGraph[i][j]=temp;
                    }
                }
            }
        }
        
        cout<<"Scenario #"<<++count<<endl;
        cout<<"Frog Distance = "<<fixed<<setprecision(3)<<mainGraph[0][1]<<endl<<endl;
        stones.clear();
    }
}
