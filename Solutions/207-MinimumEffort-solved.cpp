#include <iostream>
#include <deque>
#include <string.h>
#include <queue>
#include <sstream>
#include <limits.h>
using namespace std;
deque<string> places;
struct Edge{
    int i, dist;
    Edge(int i1,int d1)
    {
        i=i1;
        dist=d1;
    }
};
struct CompareEdge
{
    bool operator()(const Edge &l, const Edge &r)
    {
        return l.dist > r.dist;
    }
};

int N;
int d1,d2;
int Graph[201][201];

int getPos(string s)
{
    for(int i=0;i<places.size();i++)
    {
        if(s.compare(places[i])==0)
        {
            return i;
        }
    }
    return -1;
}

string djikstrasAlg(int source, int trgt,bool retJour)
{
    int parent[N];
    int distance[N];
    for(int i=0;i<N;i++)
        distance[i]=INT_MAX;
    priority_queue<Edge,vector<Edge>,CompareEdge> Q;
    Q.push(Edge(source,0));
    parent[source]=-1;
    distance[source]=0;
    while(!Q.empty())
    {
        Edge e =Q.top();Q.pop();
        if(e.i==trgt)
            break;
        for(int i=0;i<N;i++)
        {
            if(Graph[e.i][i]!=-1)
            {
                if((e.dist+Graph[e.i][i])<distance[i])
                {
                    distance[i]=e.dist+Graph[e.i][i];
                    parent[i]=e.i;
                    Q.push(Edge(i,distance[i]));
                }
            }
        }
    }
    string temp= "";
    int ix=trgt;
    while(ix!=source)
    {
        temp= " -> "+places[ix]+temp;
        ix=parent[ix];
        
    }
    if(!retJour)
    {
        d1=distance[trgt];
    }
    else
    {
        d2=distance[trgt];
    }
    return temp;
}
int main()
{
    //     cout<<"Start"<<endl;
    //    int N,
    int P;
    int officePos(-1),hallPos(-1);
    string q;
    while(getline(cin,q))
    {
        stringstream(q)>>N;
        for(int i=0;i<N;i++)
        {
            string s;
            getline(cin, s);
            places.push_back(s);
            if(s=="office")
                officePos=i;
            if(s=="hall")
                hallPos=i;
            
        }
        //-------------------------
        //        cout<<"---------"<<endl;
        //        for(int i=0;i<places.size();i++)
        //        {
        //            cout<<"|"<<places[i]<<"|"<<endl;
        //        }
        //        cout<<"---------"<<endl;
        //-------------------------
        
        memset(Graph, -1, sizeof(Graph));
        string t;
        getline(cin, t);
        stringstream(t)>>P;
        
        for(int i=0;i<P;i++)
        {
            bool beforeColon = true;
            string z;
            getline(cin, z);
            string p1,p2;
            int pos1(-1),pos2(-1),pos0(-1),w1(0),w2(0);
            int j;
            for (j=0; j < z.length(); j++) {
                if (z[j] == ':') {
                    beforeColon = false;
                    continue;
                }
                if (beforeColon == true) {
                    p1 += z[j];
                    continue;
                }
                if (z[j] == ' ' && z[j + 1] >= '0'&&z[j + 1] <= '9') {
                    pos2 = getPos(p2);
                    if (pos2 == -1) {
                        p2 += z[j];
                        continue;
                    }
                    else {
                        w1 = z[++j] - '0';
                        while (j <z.length() && z[++j] >= '0'&&z[j] <= '9') {
                            w1 = (w1 * 10) + z[j] - '0';
                        }
                        break;
                    }
                    
                }
                else
                    p2 += z[j];
            }
            pos0 = getPos(p1);
            pos1 = getPos(p2);
            
            Graph[pos0][pos1]=w1;
            
            while  ((++j) < z.length()&& z[j]>='0'&&z[j]<='9') {
                w2 = (w2*10) + z[j] - '0';
            }
            if(w2>0)
                Graph[pos1][pos0]=w2;
            
        }
        
        //Print Graph For debugging
        //        for(int i=0;i<N;i++)
        //        {
        //            for(int j=0;j<N;j++)
        //            {
        //                cout<<Graph[i][j]<<" ";
        //            }
        //            cout<<endl;
        //        }
        //        cout<<endl;
        
        
        string s1=djikstrasAlg(officePos, hallPos,false);
        string s2=djikstrasAlg(hallPos, officePos,true);
        string mainString="office"+s1+s2;
        cout<<(d1+d2)<<endl;
        cout<<mainString<<endl<<endl;
        places.clear();
    }
}
