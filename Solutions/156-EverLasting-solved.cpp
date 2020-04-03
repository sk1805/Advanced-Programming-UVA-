#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
priority_queue<int> factorsOfA;
priority_queue<int> factorsOfB;

void getFactorsOfA(int n){
    bool flag=false;
    while (n % 2 == 0)
    {
        if(!flag){
            factorsOfA.push(2);
            flag=true;
        }
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        flag=false;
        while (n % i == 0)
        {
            if(!flag){
                factorsOfA.push(i);
                flag=true;
            }
            n = n/i;
        }
    }
    if (n > 2)
        factorsOfA.push(n);
}

void getFactorsOfB(int n){
    bool flag=false;
    while (n % 2 == 0)
    {
        if(!flag){
            factorsOfB.push(2);
            flag=true;
        }
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        flag=false;
        while (n % i == 0)
        {
            if(!flag){
                factorsOfB.push(i);
                flag=true;
            }
            n = n/i;
        }
    }
    if (n > 2)
        factorsOfB.push(n);
}

int getKeyOfA(){
    int max = factorsOfA.top();factorsOfA.pop();
    int temp=0;
    while(!factorsOfA.empty()){
        temp+=factorsOfA.top();factorsOfA.pop();
    }
    return max-temp;
}
int getKeyOfB(){
    int max = factorsOfB.top();factorsOfB.pop();
    int temp=0;
    while(!factorsOfB.empty()){
        temp+=factorsOfB.top();factorsOfB.pop();
    }
    return max-temp;
}
int main()
{
//    cout<<"Lets Start"<<endl;
    int a,b;
    
    while(true){
        cin>>a>>b;
        if(a==0 && b==0){break;}
        getFactorsOfA(a);
        getFactorsOfB(b);
        int key_of_A= getKeyOfA();
        int key_of_B= getKeyOfB();
        if(key_of_A>key_of_B){
            cout<<"a"<<endl;
        }
        else{
            cout<<"b"<<endl;
        }
    }
}
