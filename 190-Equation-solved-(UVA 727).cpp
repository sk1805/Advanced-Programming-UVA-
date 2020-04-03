#include <iostream>
#include <stdio.h>
#include <stack>
#include <cstdlib>
#include <deque>

using namespace std;


int main() {
    
//    cout<<"input"<<endl;
    int cases;
    stack<char> charlist;
    deque<char> dq;
    string xx;
    getline(cin,xx);
    cases = xx[0]-'0';
    getline(cin,xx);
    for(int i=0;i<cases;i++){

            while(getline(cin,xx)){
                
                if(xx[0]=='\n'||xx[0]=='\0'){
                    break;
                }
                else if(xx[0]>='0' && xx[0]<='9'){
                    dq.push_back(xx[0]);
                }
                else if(xx[0]=='-'||xx[0]=='+'){
                    if(charlist.empty()){charlist.push(xx[0]);}
                    else if(charlist.top()=='('){charlist.push(xx[0]);}
                    else{
                        while(true){
                            if(charlist.empty()||charlist.top()=='(')
                            {
                                break;
                            }
                            else
                            {
                                char temp= charlist.top();
                                charlist.pop();
                                dq.push_back(temp);
//                                charlist.pop();
                            }
                        }
                        charlist.push(xx[0]);
                    }
                }
                else if(xx[0]=='*'||xx[0]=='/'){
                    if(charlist.empty()){charlist.push(xx[0]);}
                    else if(charlist.top()=='('||charlist.top()=='+'||charlist.top()=='-'){charlist.push(xx[0]);}
                    else{
                        while(true){
                            if(charlist.empty()||charlist.top()=='('||charlist.top()=='+'||charlist.top()=='-')
                            {
                                break;
                            }
                            else
                            {
                                char temp= charlist.top();
                                charlist.pop();
                                dq.push_back(temp);
                                //                                charlist.pop();
                            }
                        }
                        charlist.push(xx[0]);
                    }
                }
                else if(xx[0]=='('){
                    charlist.push(xx[0]);
                }
                else if(xx[0]==')'){
                    while(charlist.top()!='('){
                        dq.push_back(charlist.top());
                        charlist.pop();
                    }
                    charlist.pop();
                }
            }
        while(!charlist.empty())
        {
            dq.push_back(charlist.top());
            charlist.pop();
        }
                if(i!=0){cout<<endl;}
        while(!dq.empty()){
            cout<<dq.front();
            dq.pop_front();
        }
        cout<<endl;
    }
    return 0;
}
