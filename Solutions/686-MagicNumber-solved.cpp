#include <iostream>
using namespace std;
int main()
{
//    cout<<"S"<<endl;
    string s;
    while(cin>>s)
    {
        bool flag=false;
        string t="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1')
            {
                if(t=="")
                {t+=s[i];}
                else if(t=="1"||t=="14"||t=="144")
                {
                   t=s[i];
                }
                else
                {
                    flag=true;
                    break;
                }
            }
            else if(s[i]=='4')
            {
                if(t=="1"||t=="14")
                {
                    t+=s[i];
                }
                else
                {
                    flag=true;
                    break;
                }
                
            }
            else
            {
                flag=true;
                break;
            }
        }
        
        if(flag)
            cout<<"NO"<<endl;//<<endl;
        else
            cout<<"YES"<<endl;//<<endl;
    }
}
