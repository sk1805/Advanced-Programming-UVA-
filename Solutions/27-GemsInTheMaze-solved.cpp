#include <iostream>
#include <deque>
using namespace std;

bool check_if_already_there(deque<int> x, int y)
{
    for(int xx=0;xx<x.size();xx++){
        if(x[xx]==y)
            return true;
    }
    return false;
}

int main()
{
//    cout<<"enter here:"<<endl;
    int cases;
    cin>>cases;
    for(int i=0;i<cases;i++)
    {
        int max_answer=0;
        int a,b,c,n;
        cin>>a>>b>>c>>n;
        deque<int> visited_paths;
        for(int j=0;j<n;j++){
            visited_paths.clear();
            bool flags= false;
            int value = j;
            int ans=1;
            visited_paths.push_back(j);
            while(flags != true){
                value = ((a*value*value)+(b*value)+c)%n;
                if(check_if_already_there(visited_paths, value)){
                    flags = true;
                }
                else{
                    visited_paths.push_back(value);
                    ans++;
                }
            }
            if(ans> max_answer){
                max_answer=ans;
            }
        }
        cout<<max_answer<<endl;
    }
}
