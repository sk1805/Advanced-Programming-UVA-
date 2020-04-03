#include <iostream>
#include <stdio.h>
using namespace std;
#define SZ 32
int Bytes[SZ];
int pc,accu;
int binaryToDecimal(int j)
{
    int jt=j;
    int count =0;
    count+=(jt%10)*1;
    jt/=10;
    count+=(jt%10)*2;
    jt/=10;
    count+=(jt%10)*4;
    jt/=10;
    count+=(jt%10)*8;
    jt/=10;
    count+=(jt%10)*16;
    jt/=10;
    count+=(jt%10)*32;
    jt/=10;
    count+=(jt%10)*64;
    jt/=10;
    count+=(jt%10)*128;
    
    return count;
    
}
int decimalToBinary(int k)
{
    int jt=k;
    int count =0;
    count+=(jt%2)*1;
    jt/=2;
    count+=(jt%2)*10;
    jt/=2;
    count+=(jt%2)*100;
    jt/=2;
    count+=(jt%2)*1000;
    jt/=2;
    count+=(jt%2)*10000;
    jt/=2;
    count+=(jt%2)*100000;
    jt/=2;
    count+=(jt%2)*1000000;
    jt/=2;
    count+=(jt%2)*10000000;
    
    return count;
}
bool check(int i)
{
    int pre=i/100000;
    int post=i%100000;
    pc++;
    if(pc>31)
        pc-=32;
    
    //Check all Cases
    if(pre==0)
    {
        Bytes[binaryToDecimal(post)]=decimalToBinary(accu);
        return false;
    }
    else if(pre==1)
    {
        accu=binaryToDecimal(Bytes[binaryToDecimal(post)]);
        return false;
    }
    else if(pre==10)
    {
        if(accu==0)
        {
            pc=binaryToDecimal(post);
        }
        return false;
        
    }
    else if(pre==11)
    {
        return false;
    }
    else if(pre==100)
    {
        accu--;
        if(accu<0)
            accu+=256;
        return false;
    }
    else if(pre==101)
    {
        accu++;
        if(accu>255)
            accu-=256;
        return false;
    }
    else if(pre==110)
    {
       pc=binaryToDecimal(post);
        return false;
    }
    else if(pre==111)
    {
        return true;
    }
    
    return false;
}
int main()
{
//    cout<<"Les start"<<endl;
//    int s;
//    while(true)
//    {
//        cin>>s;
//        if(s==-1)
//            break;
//        cout<<decimalToBinary(s)<<endl;
//    }
    while(cin>>Bytes[0])
    {
        for(int i=1;i<SZ;i++)
        {
            cin>>Bytes[i];
        }
        pc=0;accu=0;
        
//        cout<<accu<<" "<<pc<<endl;
        while(true)
        {
            
            if(check(Bytes[pc]))
                break;

//            cout<<accu<<" "<<pc<<endl;
        }
//        cout<<accu<<" "<<pc<<"----"<<endl;
        printf("%08d\n",decimalToBinary(accu));
        
    }
}
