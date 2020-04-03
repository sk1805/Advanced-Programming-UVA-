#include <iostream>
#include <deque>
#include <queue>
#include <string.h>

using namespace std;

struct road{
    
    int start_u, end_v, capacity;
};

struct CompareRoad
{
    bool operator()(const road &l, const road &r)
    {
        return l.capacity < r.capacity;//MAX TO MIN
    }   
};

int roadsVisited[101];
int mainCounter=0;

void setup(){
    for(int y=0;y<101;y++){
        roadsVisited[y]=y;
    }
}

void changeIt(int a, int b){
    for(int x=0;x<mainCounter;x++){
        if(roadsVisited[x]==b||x==b){
            roadsVisited[x]= roadsVisited[a];
        }
    }
}

int main()
{
    priority_queue<road,vector<road>,CompareRoad> roads_PQ;
//    cout<<"start"<<endl;
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int n,m;
        cin>>n>>m;
        mainCounter=n;
        for(int j=0;j<m;j++)
        {
            setup();
            road r;
            cin>>r.start_u>>r.end_v>>r.capacity;
            if(r.start_u!=r.end_v)
                roads_PQ.push(r);
        }
    
        int count = 10001;
        while(!roads_PQ.empty())
        {
            road temp = roads_PQ.top();
            roads_PQ.pop();
            if(roadsVisited[temp.start_u]!=roadsVisited[temp.end_v])
            {
                changeIt(temp.start_u,roadsVisited[temp.end_v]);
                if(temp.capacity<count)
                {
                    count=temp.capacity;
                }
                
            }
        }
        cout<<"Case #"<<(i+1)<<": "<<count<<endl;
    }
}
