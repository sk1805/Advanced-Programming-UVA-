#include <iostream>
//#include <deque>
#include <list>
#include <deque>
#include <iomanip>
using namespace std;

deque<int> countries[21];
int visited[21]={0};
int steps[21]={0};
int caseCount=0;
deque<int> bfs;
void performBFS(int val){
    int step = steps[val]+1;
    int x;
    for(int i=0;i<countries[val].size();i++)
    {
        x= countries[val][i];
        if(visited[x]!=caseCount){
            bfs.push_back(x);
            visited[x]= caseCount;
            steps[x]=step;
        }
        
    }
}

void clean(){
    for(int i=0;i<21;i++){
        steps[i]=0;
    }
    for(int i=0;i<21;i++){
        visited[i]=0;
    }
   
}
void clean2(){
    for(int i=0;i<21;i++){
        countries[i].clear();
    }
}


int main()
{
    cout << fixed;
    cout << setprecision(2);
//    cout<<"lets begin"<<endl;
    int neighbours, neighbour_specs;
    int ccc=0;
    while(cin>>neighbours){
        ccc++;
        caseCount=0;
        for(int i=0;i<neighbours;i++){
            cin>>neighbour_specs;
            countries[1].push_back(neighbour_specs);
            countries[neighbour_specs].push_back(1);
        }
        for(int j=2;j<20;j++){
            cin>>neighbours;
            for(int i=0;i<neighbours;i++){
                cin>>neighbour_specs;
                countries[j].push_back(neighbour_specs);
                countries[neighbour_specs].push_back(j);
            }
        }
        int cases,from,to;
        cout<<"Test Set #"<<ccc<<endl;
        cin>>cases;
        for(int i=0;i<cases;i++){
            cin>>from>>to;
            caseCount++;
            bfs.push_back(from);
            visited[from]=caseCount;
            int temp=-10;
            while(!bfs.empty())
            {
                temp= bfs.front();
                bfs.pop_front();
                if(temp==to){
                    break;
                }
                performBFS(temp);
                
                
            }
            cout.width(2);cout<<right<<from<<" to ";
            cout.width(2);cout<<right<<to<<": ";
            cout<<left<<steps[temp]<<endl;
            bfs.clear();
            clean();
            
        }
        cout<<endl;
        clean2();
    }
}
