#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int lcs(string a, string b, int aSize, int bSize)
{
    int Graph[aSize+1][bSize+1];
    for(int i=0;i<=aSize;i++)
    {
        for(int j=0;j<=bSize;j++)
        {
            if(i==0||j==0)
            {
                Graph[i][j]=0;
            }
            else if(a[i-1]==b[j-1])
            {
                Graph[i][j]=Graph[i-1][j-1]+1;
            }
            else
            {
                Graph[i][j]=max(Graph[i-1][j],Graph[i][j-1]);
            }
        }
    }
    return Graph[aSize][bSize];
}
int main()
{
//    printf("Start\n");
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        string a="";
        string b="";
        cin>>a;
        cin>>b;
        int aL=int(a.length());
        int bL=int(b.length());
        
        int lcsA =lcs(a,b,aL,bL);
        int scsA = aL+bL-lcsA;
        printf("%d\n",scsA);
    }
}