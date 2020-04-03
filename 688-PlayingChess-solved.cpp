#include <iostream>
#include <deque>
#include <algorithm>
#include <limits.h>
#include <string.h>
using namespace std;
int CaseNum=0;
int visited[8][8];
int board[8][8];
struct step
{
    int a,b,val;
    step(){}
    step(int a1,int a2, int v1)
    {
        a=a1;
        b=a2;
        val=v1;
    }
};
bool check(step s)
{
    if(s.a>7||s.b>7||s.a<0||s.b<0)
        return false;
    if(visited[s.a][s.b]==CaseNum||board[s.a][s.b]==1)
        return false;
    return true;
}
int main()
{
//    cout<<"STart"<<endl;
    int N;
    cin>>N;
    memset(visited, 0, sizeof(visited));
    for(int i=0;i<N;i++)
    {
        CaseNum++;
        string s;
        int BK[2];int WK[2];
        
        for(int j=0;j<8;j++)
        {
            cin>>s;
            for(int k=0;k<8;k++)
            {
                if(s[k]=='#')
                {
                    BK[0]=j;BK[1]=k;
                    board[j][k]=1;
                }
                else if (s[k]=='@')
                {
                    WK[0]=j;WK[1]=k;
                    board[j][k]=2;
                }
                else if (s[k]=='*')
                {
                    board[j][k]=1;
                }
                else
                {
                    board[j][k]=0;
                }
            }
                
        }
        deque<step> bfs;
        int ans=-1;bool flag=false;
        bfs.push_back(step(BK[0],BK[1],0));
        //cout<<BK[0]<<" "<<BK[1]<<" "<<WK[0]<<" "<<WK[1]<<endl;
        while(!bfs.empty())
        {
            step s=bfs.front();bfs.pop_front();
            //cout<<s.a<<" "<<s.b<<" "<<s.val<<endl;
            if(WK[0]==s.a && WK[1]==s.b)
            {
                ans=s.val;flag=true;break;
            }
            step s1=step(s.a+2,s.b+1,s.val+1);
            //cout<<s1.a<<" "<<s1.b<<" "<<s1.val<<" -------"<<endl;
            if(check(s1))
            {bfs.push_back(s1);visited[s1.a][s1.b]=CaseNum;}
            
            s1=step(s.a-2,s.b+1,s.val+1);
            if(check(s1))
                {bfs.push_back(s1);visited[s1.a][s1.b]=CaseNum;}
            
            s1=step(s.a+2,s.b-1,s.val+1);
            if(check(s1))
                {bfs.push_back(s1);visited[s1.a][s1.b]=CaseNum;}
            
            s1=step(s.a-2,s.b-1,s.val+1);
            if(check(s1))
                {bfs.push_back(s1);visited[s1.a][s1.b]=CaseNum;}
            
            s1=step(s.a+1,s.b+2,s.val+1);
            if(check(s1))
                {bfs.push_back(s1);visited[s1.a][s1.b]=CaseNum;}
            
            s1=step(s.a+1,s.b-2,s.val+1);
            if(check(s1))
                {bfs.push_back(s1);visited[s1.a][s1.b]=CaseNum;}
            
            s1=step(s.a-1,s.b+2,s.val+1);
            if(check(s1))
                {bfs.push_back(s1);visited[s1.a][s1.b]=CaseNum;}
            
            s1=step(s.a-1,s.b-2,s.val+1);
            if(check(s1))
                {bfs.push_back(s1);visited[s1.a][s1.b]=CaseNum;}
        }
        if(flag)
            cout<<"Case "<<CaseNum<<": "<<ans<<endl;
        else
            cout<<"Case "<<CaseNum<<": "<<"IMPOSSIBLE"<<endl;
    }
}
