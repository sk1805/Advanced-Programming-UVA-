#include <iostream>
#include <set>
using namespace std;
int main()
{
    //    cout<<"Start"<<endl;
    set<string> wordList;
    string input;
    
    while(cin>>input)
    {
        string changed="";
        for(int i=0;i<input.length();i++)
        {
            if(input[i]>='A' && input[i]<='Z')
            {
                changed += input[i] - 'A' + 'a';
            }
            else if(input[i]>='a' && input[i]<='z')
            {
                changed+=input[i];
            }
            else
            {
                if(changed!="")
                {
                    if(wordList.find(changed)==wordList.end())
                    {
                        wordList.insert(changed);
                        
                    }
                    changed="";
                }
            }
        }
        if(changed!="" && wordList.find(changed)==wordList.end())
        {
            wordList.insert(changed);
        }   
    }
    set<string> ::iterator it;
    for(it=wordList.begin();it!=wordList.end();++it)
    {
        cout<<*it<<endl;
    }
}
