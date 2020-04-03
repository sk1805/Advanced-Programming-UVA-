#include <iostream>
#include <stdio.h>
#include <stack>
#include <cstdlib>
#include <deque>
#include <string>
using namespace std;
int main() {
    stack <int> s;
    stack<char> charlist;
    deque<char> dq;
    char k;
    int k1;
    int t1, t2,t3;
    string b;
//    cout<<"input"<<endl;
    while(getline(cin, b)) {
        stack<char> charlist;
        string a="";
        //Implemented from Solution for Equation
        for (int x=0;x<b.length();x++){
            if(b[x]>='0' && b[x]<='9'||b[x]>='A' && b[x]<='F'){
                a+= b[x];
            }
            else if(b[x]=='+'){
                if(charlist.empty()){charlist.push(b[x]);}
                else if(charlist.top()=='('){charlist.push(b[x]);}
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
                            a+=temp;
                            //                                charlist.pop();
                        }
                    }
                    charlist.push(b[x]);
                }
            }
            else if(b[x]=='*'){
                if(charlist.empty()){charlist.push(b[x]);}
                else if(charlist.top()=='('||charlist.top()=='+'){charlist.push(b[x]);}
                else{
                    while(true){
                        if(charlist.empty()||charlist.top()=='('||charlist.top()=='+')
                        {
                            break;
                        }
                        else
                        {
                            char temp= charlist.top();
                            charlist.pop();
                            a+=temp;
                            //                                charlist.pop();
                        }
                    }
                    charlist.push(b[x]);
                }
            }
            else if(b[x]=='('){
                charlist.push(b[x]);
            }
            else if(b[x]==')'){
                while(charlist.top()!='('){
                    a+=charlist.top();
                    charlist.pop();
                }
                charlist.pop();
            }
            
        }
        while(!charlist.empty())
        {
            a+=charlist.top();
            charlist.pop();
        }
        
        
        //Implemented from Solution for Reverse Polish Notation
        for (int i = 0;i < a.length();i++) {
            k = a[i];
            if (k == '0' || k == '1' || k == '2' || k == '3' || k == '4' || k == '5' || k == '6' || k == '7' || k == '8' || k == '9') {
                k1 = k - '0';
                s.push(k1);
            }
            else if(k>='A' && k<='F'){
                k1= k - 'A' +10;
                s.push(k1);
            }
            else if (k == '+') {
                t1 = s.top();
                s.pop();
                t2 = s.top();
                s.pop();
                t3 = t2 + t1;
                s.push(t3);
            }
            else if (k == '*') {
                t1 = s.top();
                s.pop();
                t2 = s.top();
                s.pop();
                t3 = t2 * t1;
                s.push(t3);
            }
            else if (k == ' ') {
                continue;
            }
        }
        cout << hex <<uppercase<<s.top() << endl;
        s.pop();
    }
    return 0;
}
