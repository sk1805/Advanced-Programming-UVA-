#include <iostream>
#include <deque>
#include <limits.h>
#include <string.h>
using namespace std;

struct path{
    int junction_number, distance;
};
struct temp{
    int indexMin, cycle_or_not;
};
//deque<path> paths[501];
int paths[501][501]={INT_MAX};
int distanceArray[501][2];
bool included[501][2];
int caseCount=0;
int START=0;

temp minDist(int n){
    
    int minimum=INT_MAX;int indexMin= -1;int cycle_or_not=-1;
    for(int a=0;a<n;a++){
        for(int b=0;b<2;b++){
        if(included[a][b]==false && distanceArray[a][b]<=minimum){
            minimum=distanceArray[a][b];indexMin=a;cycle_or_not=b;
        }
        }
        
    }
    temp tp;
    tp.cycle_or_not=cycle_or_not;
    tp.indexMin=indexMin;
    
    return tp;
}

void shortestPath(int n){
    
    
    
    //distance[START]=0;
    for(int i=0;i<n;i++){
        distanceArray[i][0]=INT_MAX;
        distanceArray[i][1]=INT_MAX;
    }
    for(int i=0;i<n;i++){
        included[i][0]=false;
        included[i][1]=false;
    }
    distanceArray[0][1]=0;
    
    for(int count=0;count<2*n-2;count++){
        temp u= minDist(n);
        included[u.indexMin][u.cycle_or_not]=true;
        
        for(int i=0;i<n;i++){
            if(!included[i][1-u.cycle_or_not] && paths[u.indexMin][i]!= -1 && distanceArray[u.indexMin][u.cycle_or_not]!=INT_MAX){
                if((distanceArray[u.indexMin][u.cycle_or_not] +paths[u.indexMin][i]) <distanceArray[i][1-u.cycle_or_not]){
                    distanceArray[i][1-u.cycle_or_not]= distanceArray[u.indexMin][u.cycle_or_not]+paths[u.indexMin][i];
                }
            }
        }
        
        
    }
    cout<<"Set #"<<caseCount<<endl;
    //cout<<ans<<endl;
    if(distanceArray[n-1][1]!=INT_MAX)
    {
        cout<<distanceArray[n-1][1]<<endl;
    }
    else{
        cout<<"?"<<endl;
    }
    
    
}

int main()
{
//        cout<<"Lets start: "<<endl;
    
    int n,r;
    int to,from,distance;
    int ans=-1;
    
    while(cin>>n>>r){
        caseCount++;
        memset(paths, -1, sizeof(paths));
        
        for(int i=0;i<r;i++){
            cin>>to>>from>>distance;
            paths[to][from]=distance;
            paths[from][to]=distance;
        }
        
        shortestPath(n);
    }
    
    return 0;
    
}
