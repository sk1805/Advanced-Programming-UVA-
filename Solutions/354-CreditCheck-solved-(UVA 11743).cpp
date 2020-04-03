#include <iostream>
using namespace std;

int findVal(int x){
    
    int y=x;
    y=y*2;
    int z= y%10;
    y=y/10;
    z+=y;
    return z;
}

int main()
{
//    cout<<"input test cases"<<endl;
    int cases;
    cin>> cases;
    for(int i=0;i<cases;i++){
        
        int ccc[4] = {0,0,0,0};
        for(int j=0;j<4;j++){
            cin>>ccc[j];
        }
        int final_count=0;
        int single_counts=0;
        int double_counts=0;
        
        for(int j=0;j<4;j++){
            int temp= ccc[j];
            //first digit
            int x= temp%10;
            single_counts+=x;
            temp=temp/10;
            //second digit
            x= temp%10;
            x= findVal(x);
            double_counts+=x;
            temp = temp/10;
            //third digit
            x= temp%10;
            single_counts+=x;
            temp=temp/10;
            //fourth digit
            x= temp%10;
            x= findVal(x);
            double_counts+=x;
        }
        
        final_count=single_counts+double_counts;
        if(final_count%10==0){
            cout<<"Valid"<<endl;
        }
        else{
            cout<<"Invalid"<<endl;
        }
    }
    return 0;
}
