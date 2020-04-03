#include <iostream>
#include <deque>
#include <queue>
#include <string.h>

using namespace std;

struct road{
    
    int start_u, end_v, weight;
};

struct CompareRoad
{
    bool operator()(const road &l, const road &r)
    {
        return l.weight > r.weight;
    }
    
};
int roadsVisited[1001];
int mainCounter=0;
void changeIt(int a, int b){
    for(int x=0;x<mainCounter;x++){
        if(roadsVisited[x]==b){
            roadsVisited[x]= roadsVisited[a];
        }
    }
}

bool check_if_done(){
    int val= roadsVisited[0];
    
    for(int xxx=1;xxx<mainCounter;xxx++){
        if(roadsVisited[xxx]!=val){
            return false;
        }
    }
    return true;
    
}

int main()
{
    //    cout<<"Lets start"<<endl;
    priority_queue<road,vector<road>,CompareRoad> roads_PQ;
    
    int n,m;
    while(cin>>n>>m){
        if(n==0 && m==0){
            return 0;
        }
        else{
            mainCounter=n;
            for(int x=0;x<n;x++){
                roadsVisited[x]=x;
            }
            
            for(int j=0;j<m;j++)
            {
                road r;
                cin>>r.start_u>>r.end_v>>r.weight;
                if(r.start_u!=r.end_v)
                    roads_PQ.push(r);
            }
            
            deque<int> extra_values;
            int count=0;
            while (!roads_PQ.empty()) {
                road temp = roads_PQ.top();
                roads_PQ.pop();
                if(roadsVisited[temp.start_u]!=roadsVisited[temp.end_v])
                {
                    changeIt(temp.start_u,roadsVisited[temp.end_v]);
                    count+=temp.weight;
                }
                else
                {
                    extra_values.push_back(temp.weight);
                }
                
                
            }
            bool flag =check_if_done();
            if(!flag){
                cout<<"\\(^o^)/ pray to god"<<endl;
            }
            else{
                cout<<"Min cost: "<<count<<endl;
                for(int xyz=0;xyz<extra_values.size();xyz++){
                    cout<<extra_values[xyz];
                    if(xyz!=(extra_values.size()-1))
                    {
                        cout<<" ";
                    }
                }
                cout<<endl;
            }
            extra_values.clear();
        }
    }
}


