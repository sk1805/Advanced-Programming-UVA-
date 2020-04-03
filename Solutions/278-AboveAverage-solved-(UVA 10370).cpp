#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int main(){
    
    cout<<fixed;
    cout<<setprecision(3);
    int cases;
    cin>> cases;
    for(int i=0;i<cases;i++){
        double n,x,total(0);
        cin>>n;
        
        vector<double> number_list;
        for(int j=0;j<n;j++){
            cin>>x;
            total+=x;
            number_list.push_back(x);
            
        }
        double average = total/n;
        double count =0;
        for(int j=0;j<number_list.size();j++){
            if(number_list[j]>average){
                count++;
            }
        }
        double ans = (count/(double)n)*100.000;
        cout<<ans<<"%"<<endl;
        number_list.clear();
    }
    
    return 0;
}
