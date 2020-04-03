#include <iostream>
#include <string>
#include <sstream>

using namespace std;
string SI="SIMPLE",FG="FULLY-GROWN",MG="MUTAGENIC",MT="MUTANT";
string line;
string check(int start, int end){
    
    if(start==end && line[start]=='A'){
        return SI;
    }
    if(line[end]=='B' && line[end-1]=='A'){
        if(start+1==end)
        {
            return MT;
        }
        else if(check(start,end-2)!=MT)
        {
            return FG;
        }
    }
    if(line[start]=='B' && line[end]=='A'){
        if(start+1==end)
        {
            return MT;
        }
        else if(check(start+1,end-1)!=MT)
        {
            return MG;
        }
    }
    return MT;
}

int main()
{
//    cout<<"begin"<<endl;
    int cases;
    getline(cin,line);
    stringstream(line)>>cases;
    for(int i=0;i<cases;i++)
    {
        getline(cin,line);
        int ln=(int)line.length()-1;
        string ans=check(0, ln);
        cout<<ans<<endl;
        
    }
}
