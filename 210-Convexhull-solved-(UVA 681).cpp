#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
bool last_case=false;

struct Point
{
    int x, y;
    Point(){}
    Point(int x1, int y1)
    {
        x=x1;
        y=y1;
    }
};
vector<Point> points;Point p0;

Point nextToTop(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}
void swap(int a, int b)
{
    
    int tempx=points[a].x;int tempy=points[a].y;
    points[a].x=points[b].x;points[a].y=points[b].y;
    points[b].x=tempx;points[b].y=tempy;
    
}

int distSq(Point a, Point b)
{
    int xD=a.x-b.x;
    int yD=a.y-b.y;
    return (xD*xD) + (yD*yD);
}
int orientation(Point a, Point b, Point c)
{
    int val = ((a.x*b.y)-(b.x*a.y))+((b.x*c.y)-(c.x*b.y))+((c.x*a.y)-(a.x*c.y));

    if (val == 0)
        return 0;
    else if(val>0)
        return 1;
    else
        return 2;

}

bool Compare(Point p1, Point p2)
{
    int orn=orientation(p0, p1, p2);
    if(orn==0)
        return distSq(p0, p1)<distSq(p0, p2);
    else
        return (orn==2);
        
}


void convexHullCalculation()
{
    int n=int(points.size());
    
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++)
    {
        int y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
        {
            ymin = points[i].y;
            min = i;
        }
        
    }
    swap(0,min);
    p0 = points[0];
    vector<Point> ::iterator pi=points.begin();
    pi++;
    sort(pi,points.end(),Compare);
    
    int m = 1;
    for (int i=1; i<n; i++)
    {
        while (i < n-1 && orientation(p0, points[i],points[i+1]) == 0)
            i++;
        points[m] = points[i];
        m++;
    }
    
    if (m < 3) return;

    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);
    
    for (int i = 3; i < m; i++)
    {
        while (orientation(nextToTop(S), S.top(), points[i]) != 2)
        {
            S.pop();
            
        }
        S.push(points[i]);
    }
    
    cout<<S.size()+1<<endl;
    cout << p0.x << " " << p0.y <<endl;
    while (!S.empty())
    {
        Point p = S.top();
        cout << p.x << " " << p.y << endl;
        S.pop();
    }
}

int main()
{
//        cout<<"start"<<endl;
    int cases;
    cin>> cases;
    cout<<cases<<endl;
    for(int i=0;i<cases;i++)
    {
        if(i==(cases-1)){last_case=true;}
        int n;
        cin>>n;
        points.clear();
        int a,b;
        for(int j=0;j<n;j++)
        {
            cin>>a>>b;
            points.push_back(Point(a,b));
        }
        
        int ex;
        if(!last_case)
            cin>>ex;
        convexHullCalculation();
        if(!last_case)
            cout<<-1<<endl;
    }
    
}

