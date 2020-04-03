#include <iostream>
#include <queue>
#include <cmath>
#include <deque>
#include <string.h>
#include <algorithm>
using namespace std;

bool contains(deque<int> dq, int t)
{
    for(int i=0;i<dq.size();i++){
        if(dq[i]==t){
            return true;
        }
    }
    return false;
}
struct rowss{
    int row_number;
    deque<int> seats;
};
deque<rowss> listOfOccRows;
void add(int temp2, int temp){
    for(int i=0;i<listOfOccRows.size();i++){
        if(listOfOccRows[i].row_number==temp2){
            listOfOccRows[i].seats.push_back(temp);
            return;
        }
    }
}
int main()
{
    
//    cout<<"Start"<<endl;
    deque<int> rows;
    deque<int> rows2;
   
    int cases;
    cin>>cases;
    for(int c=0;c<cases;c++){
        listOfOccRows.clear();
        int n,m,seats_reserved,temp;
        cin>>n>>m>>seats_reserved;
        
        for(int i=0;i<seats_reserved;i++){
            cin>>temp;
            rows.push_back(temp);
            if(!contains(rows2,temp)){
                rows2.push_back(temp);
                rowss r;
                r.row_number=temp;
                r.seats.clear();
                r.seats.push_back(0);
                listOfOccRows.push_back(r);
            }
        }
        for(int i=0;i<seats_reserved;i++){
            cin>>temp;
            int temp2=rows[i];
            add(temp2, temp);
//            listOfOccRows[temp2].seats.push_back(temp);
        }
        
        long long main_count=0;
        //calculate -start
        for(int i=0;i<listOfOccRows.size();i++)
        {
            listOfOccRows[i].seats.push_back(m+1);
            sort(listOfOccRows[i].seats.begin(), listOfOccRows[i].seats.end());
            long long temp_count=0;
            for(int j=1;j<listOfOccRows[i].seats.size();j++)
            {
                int temp=(listOfOccRows[i].seats[j]-listOfOccRows[i].seats[j-1])-1;
                if(temp>1)
                {
                    temp_count+=temp-1;
                }
            }
            main_count+=temp_count;
        }
        
        //calculate -end
        main_count+=(n-rows2.size())*(m-1);
        cout<<"Case #"<<(c+1)<<": "<<main_count<<endl;
        rows.clear();rows2.clear();//listOfOccRows.clear();
        
        
        
    }
    
}
