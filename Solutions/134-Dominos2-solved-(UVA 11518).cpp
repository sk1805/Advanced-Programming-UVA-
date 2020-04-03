#include <iostream>
#include <deque>
#include <vector>
#include <stack>
using namespace std;

deque<int> dominos[10001];
int flag[10001] ={0};
int caseCount= 0;
int total=0;
vector<int> poip;
void calculate(int z){
    total++;
    flag[z]=caseCount;
    for(int i=0;i<dominos[z].size();i++){
        if(flag[dominos[z][i]]!=caseCount)
        {
            calculate(dominos[z][i]);
        }
    } 
}

int main()
{
//    cout<<"lets begin"<<endl;
    int cases;
    cin>>cases;
    for(int i=0;i<cases;i++)
    {
        caseCount++;
        int n,m,l;
        cin>>n>>m>>l;
        int x,y;
        for(int j=0;j<m;j++){
            cin>>x>>y;
            dominos[x].push_back(y);
        }
        int z;
        for(int j=0;j<l;j++){
            cin>>z;
            if(flag[z]!=caseCount){
                calculate(z);
            }
        }
        cout<<total<<endl;
        total=0;
        for(int j=0;j<n;j++){
            dominos[j].clear();
        }
    }
}
