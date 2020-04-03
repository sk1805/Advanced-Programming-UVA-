#include <iostream>
#include <deque>
using namespace std;
int check(int LW, int LD, int RW, int RD)
{
    int lw=LW, ld=LD, rw=RW,rd=RD;
    if(lw==0){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        lw= check(a,b,c,d);
    }
    if(rw==0){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        rw= check(a,b,c,d);
    }
    if(lw*ld==rw*rd){
        return lw+rw;
    }
    else{
        return -1;
    }
}

int main()
{
//    cout<<"begin"<<endl;
    int left_W,left_D, right_W, right_D,cases;
    cin>>cases;
    
    for(int i=0;i<cases;i++)
    {
        cin>>left_W>>left_D>>right_W>>right_D;
        int ans=check(left_W,left_D,right_W,right_D);
        if(ans>0){
            if(i==0)
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<endl<<"YES"<<endl;
            }
        }
        else{
            if(i==0)
            {
                cout<<"NO"<<endl;
                
            }
            else
            {
                cout<<endl<<"NO"<<endl;
            }
        }
        
    }
    
}
