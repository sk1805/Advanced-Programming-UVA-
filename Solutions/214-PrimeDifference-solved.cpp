#include <iostream>
#include <cmath>
#include <algorithm>
#include<stdio.h>
#define N 1299709
#define M 100000
using namespace std;
int PrimesList[M];
bool NonPrimes[N+1];

int main(){
//            cout<<"start"<<endl;
    int n;
    //Get Primes -- start
    //Sieve Method
    NonPrimes[0]=NonPrimes[1]=true;
    for(int i = 2; i<=int(sqrt(double(N))); i++)
    {
        if(NonPrimes[i]==false)
        {
            for(int j = i*i; j<=N; j += i)
            {
                NonPrimes[j] = true;
            }
        }
    }
    //Get Primes -- end
    int pos=0;
    for(int i=2;i<N+1;i++){
        if(NonPrimes[i]==false)
            PrimesList[pos++]=i;
    }
    while(true){
        scanf("%d",&n);
//        cin>>n;
        if(n==0){break;}
        if(NonPrimes[n]==false)
        {
            printf("0\n");
//            cout<<0<<endl;
        }
        else
        {
            int pos_of_higher=lower_bound(PrimesList, PrimesList+M,n)-PrimesList;
            int ans=PrimesList[pos_of_higher]-PrimesList[pos_of_higher-1];
//            cout<<ans<<endl;
            printf("%d\n",ans);
        }
    }
    return 0;
}
