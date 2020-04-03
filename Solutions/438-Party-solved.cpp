#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        if(m>1){
            cout<<m-2<<endl;
        }
        else{
            cout<<'0'<<endl;
        }
    }
    
}
