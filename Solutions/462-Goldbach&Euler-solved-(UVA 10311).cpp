#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string.h>
#define M 100000000
using namespace std;


int NonPrimes[(M >> 6) + 1];
bool isNonPrime(int n)
{
    return NonPrimes[n>>6]&(1<<((n>>1)&31));
}
void makeNonPrime(int n)
{
    NonPrimes[n>>6]|=(1<<((n>>1)&31));
}
bool checkIfPrime(int n)
{
    if(n==2)
        return true;
    else if(n<2)
        return false;
    else if(n>2 && n%2==0)
        return false;
    else
        return !isNonPrime(n);
}

int main()
{
//    printf("Lets go\n");
//    memset(NonPrimes, 0, sizeof(int)*((M >> 6) + 1));

    //Sieve Method
    for(int i = 3; i*i<=M; i+=2)
    {
        if(!isNonPrime(i))
        {
            for(int j = i*i; j<=M; j += (2*i))
            {
                makeNonPrime(j);
            }
        }
    }

    int n;
   
//    while(scanf("%d",&n))
    while(cin>>n)
    {
        int val=0;
        bool checker=false;
        if(n%2!=0 && (n-2)>0)
        {
            if(checkIfPrime(n-2))
            {
                val=2;
                checker=true;
            }
        }
        else
        {
            int i=n/2;int temp=0;
            if(i%2==0)
            {
                temp=1;
            }
            for(int j=i-temp;j>=2;j--)
            {
                if(checkIfPrime(j) && checkIfPrime(n-j) && j!=(n-j))
                {
                    val=j;
                    checker=true;
                    break;
                }
            }
        }
        if(checker)
        {
            printf("%d is the sum of %d and %d.\n",n,val,(n-val));
//        cout<<n<<" is the sum of "<<val<<" and "<<(n-val)<<"."<<endl;
        }
        else
        {
             printf("%d is not the sum of two primes!\n",n);
//            cout<<n<<" is not the sum of two primes!"<<endl;
        }
    }
}
