#include <iostream>
using namespace std;
int main()
{
    // cout<<"start"<<endl;
    
    int coins[5]={1,5,10,25,50};
    int mainArray[7490]={};
    mainArray[0]=1;
    for(int i=0;i<5;i++){
        
        for(int j=coins[i];j<7490; j++){
            
            mainArray[j] += mainArray[j - coins[i]];
        }
    }
    int n;
    while (cin>>n) {
        cout<<mainArray[n]<<endl;
    }
}
