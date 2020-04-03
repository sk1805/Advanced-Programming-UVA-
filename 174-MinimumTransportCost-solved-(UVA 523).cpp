#include <iostream>
#include <deque>
#include <sstream>
#include<vector>
#include <limits.h>
using namespace std;
deque<deque<int> > mainShit;
deque<int> tax;

int countT=0;

void getInput(string toExtract,bool firstTime){
    deque<int> temp;
    stringstream ss(toExtract);
    int temps;
    while(ss>>temps){
        temp.push_back(temps);
    }
    if(firstTime){
        countT=(int)temp.size();
    }
    mainShit.push_back(temp);
    
}
int minDistance(deque<int> d, deque<bool>in){
    int minimum= INT_MAX,indexMin=-1;
    for(int i=0;i<countT;i++){
        if(in[i]==false && d[i]<=minimum){
            minimum=d[i];indexMin=i;
        }
    }
    return indexMin;
}
deque<int> getParentList(deque<int> temp,int n){
    deque<int> t;
    t.push_back(n);
    int xx=n;
    while(1){
        xx= temp[xx];
        if(xx==-1)
            break;
        t.push_back(xx);
    }
    return t;
    
}

void solve(int n1, int n2){
    //    int x=countT;
    //    int distanceArray[x]={INT_MAX};
    if(n1==n2){
        cout<<"From "<<n1<<" to "<<n2<<" :"<<endl;
        cout<<"Path: "<<n1<<endl;
        cout<<"Total cost : "<<0<<endl;
        return;
    }
    deque<int> distanceArray;deque<bool> visitedArray;deque<int> parent;
    //    bool visitedArray[x]={false};
    for(int i=0;i<countT;i++){
        distanceArray.push_back(INT_MAX);
        parent.push_back(INT_MAX);
        visitedArray.push_back(false);
    }
    distanceArray[n1-1]=0;
    parent[n1-1]=-1;
    for(int count=0;count<countT-1;count++){
        int u = minDistance(distanceArray,visitedArray);
        visitedArray[u]=true;
        
        for(int i=0;i<countT;i++){
            if(!visitedArray[i] && mainShit[u][i]!=-1){
                if(distanceArray[u]+mainShit[u][i]+tax[i]<distanceArray[i]){
                    distanceArray[i]=distanceArray[u]+mainShit[u][i]+tax[i];
                    parent[i]=u;
                }
            }
        }
    }
    
    // for(int i=0;i<countT)
    deque<int> listToUse = getParentList(parent, n2-1);
    
    cout<<"From "<<n1<<" to "<<n2<<" :"<<endl;
    cout<<"Path: "<<listToUse.back()+1;listToUse.pop_back();
    while(!listToUse.empty()){
        cout<<"-->"<<listToUse.back()+1;listToUse.pop_back();
    }
    cout<<endl;
    cout<<"Total cost : "<<distanceArray[n2-1]-tax[n2-1]<<endl;
}



int main()
{
//    cout<<"start"<<endl;
    string x;
    int n;
    getline(cin,x);
    stringstream(x)>>n;
    
    getline(cin,x);
    for(int m=0;m<n;m++){
        
        //city to city info
        getline(cin,x);
        getInput(x, true);
        
        for(int i=0;i<countT-1;i++){
            getline(cin,x);
            getInput(x, false);
        }
        
        //tax
        getline(cin,x);
        stringstream qq(x);
        int t;
        while(qq>>t){
            tax.push_back(t);
        }
        bool flag= false;
        while(getline(cin,x)){
            
            if(x[0]=='\n'||x[0]=='\0'){
                break;
            }
            else{
                vector<int> caseToSolve;
                caseToSolve.clear();
                stringstream qq(x);
                int t;
                while(qq>>t){
                    caseToSolve.push_back(t);
                }
                if (flag)
                    cout << endl;
                else
                    flag = true;
                
                solve(caseToSolve[0],caseToSolve[1]);
                
                
            }
        }
        mainShit.clear();
        tax.clear();
        if(m!=n-1){
            cout<<endl;
        }
        
    }
}


