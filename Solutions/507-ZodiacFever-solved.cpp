#include <iostream>
#include <string.h>
#include <limits.h>
#include <deque>
#include <queue>
using namespace std;
//Arr[0]==total_number_of_rooms,Arr[1]==number_of_corridors,Arr[2]==number_of_traps
//Arr[3]==room_no_of_entrance,Arr[4]==initial_ring_position,Arr[5]==room_number_of_treasure_room,Arr[6]==open_ring_position
int Arr[7];

struct trap{
    int  trap_mov_beh;
    char trap_type;
};
struct to_use_in_q{
    int ring_pos,total_distance, room_number;
};
struct CompareStructs
{
    bool operator()(const to_use_in_q &l, const to_use_in_q &r)
    {
        return l.total_distance > r.total_distance;//MIN TO MAX
    }
    
};

int main()
{
//    cout<<"start"<<endl;
    while(cin>>Arr[0]){
        for(int i=1;i<7;i++)
        {
            cin>>Arr[i];
        }
        int NoOfRooms=Arr[0]+1;
        int Graph[NoOfRooms][NoOfRooms];
        trap Traps[NoOfRooms];
        trap t;t.trap_mov_beh=-1;
        fill(Traps,Traps+(NoOfRooms),t);
        memset(Graph, -1, sizeof(Graph));
        for(int i=0;i<Arr[1];i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            Graph[a][b]=c;
            Graph[b][a]=c;
        }
        for(int i=0;i<Arr[2];i++)
        {
            int a,b;char c;
            cin>>a>>c>>b;
            Traps[a].trap_mov_beh=b;
            Traps[a].trap_type=c;
        }
        int final_array[NoOfRooms][13];
        for(int i=0;i<NoOfRooms;i++){
            for(int j=0;j<13;j++){
                final_array[i][j]=INT_MAX;
            }
        }
        final_array[Arr[3]][Arr[4]]=0;
        
        to_use_in_q temp;
        temp.ring_pos=Arr[4];temp.total_distance=0;temp.room_number=Arr[3];
        priority_queue<to_use_in_q,vector<to_use_in_q>,CompareStructs> Q;
        Q.push(temp);
//        bool flag=false;
        while(!Q.empty()){
            to_use_in_q t=Q.top();Q.pop();
            for(int i=1;i<NoOfRooms;i++){
                if(Graph[t.room_number][i]!=-1){
                    int roomTo=i;
                    int dis_bw=Graph[t.room_number][i];
                    int curr_pos=t.ring_pos;
                    if(Traps[roomTo].trap_mov_beh!=-1){
                        char c=Traps[roomTo].trap_type;
                        int power=Traps[roomTo].trap_mov_beh;
                        if(c=='+')
                            curr_pos+=power;
                        else if(c=='-')
                            curr_pos-=power;
                        else if(c=='*')
                            curr_pos*=power;
                        else if(c=='=')
                            curr_pos=power;
                        
                        if(curr_pos>12)
                            curr_pos%=12;
                        while(curr_pos<=0)
                        {
                            curr_pos+=12;
                        }
                        
                    }
                    int cur_dis_for_pos_and_room= final_array[roomTo][curr_pos];
                    if(t.total_distance+dis_bw<cur_dis_for_pos_and_room)
                    {
                        to_use_in_q t2;t2.ring_pos=curr_pos;t2.room_number=roomTo;t2.total_distance=t.total_distance+dis_bw;
                        Q.push(t2);
                        final_array[roomTo][curr_pos]=t.total_distance+dis_bw;
                    }
                }
            }
        }
        if(final_array[Arr[5]][Arr[6]]!=INT_MAX)
        {
            cout<<final_array[Arr[5]][Arr[6]]<<endl;
        }
        else{
            cout<<"Pray!"<<endl;
        }
    }
    return 0;
}
