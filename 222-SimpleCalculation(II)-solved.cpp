#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <sstream>
using namespace std;
int main()
{
//    cout<<"S"<<endl; 
    long double ans=0.0,t;
    string input;
    bool flag=false;
    while(getline(cin,input))
    {
        stringstream ss(input);
        while(ss>>t)
        {
            ans+=t;
        }
        if(flag)
            cout<<endl;
        cout<<setprecision(4)<<fixed<<ans<<endl;
        flag=true;
        ans=0.0;
    }
}


