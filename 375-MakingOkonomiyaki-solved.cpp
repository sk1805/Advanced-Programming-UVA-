#include <iostream>
#include <queue>
#include <deque>
using namespace std;

struct step {
    int val_a, val_b, val_c, val_d, step_number;
};
struct step2 {
    int step_number;
    int case_number_requirement;
};
deque <step> bfs;
step2 visitedBoolArray[25][25][25][25] = {0,0};
int caseCount = 0;
#define INITIAL -1
bool check(step tmp) {
    if (visitedBoolArray[tmp.val_a][tmp.val_b][tmp.val_c][tmp.val_d].case_number_requirement == caseCount) {
        return false;
    }
    return true;
}

void fill_all(step tmp, int a, int b, int c, int d) {
    step x;
    step2 y;
    //fill A
    if (tmp.val_a != a) {
        x = tmp;
        x.val_a = a;
        x.step_number++;
        if (check(x)) {
            bfs.push_back(x);
            y.case_number_requirement = caseCount;
            y.step_number = x.step_number;
            visitedBoolArray[x.val_a][x.val_b][x.val_c][x.val_d] = y;
            //            visited.push_back(x);
        }
    }
    //fill B
    if (tmp.val_b != b) {
        x = tmp;
        x.val_b = b;
        x.step_number++;
        if (check(x)) {
            bfs.push_back(x);
            y.case_number_requirement = caseCount;
            y.step_number = x.step_number;
            visitedBoolArray[x.val_a][x.val_b][x.val_c][x.val_d] = y;
            //        visited.push_back(x);
        }
    }
    //fill C
    if (tmp.val_c != c) {
        x = tmp;
        x.val_c = c;
        x.step_number++;
        if (check(x)) {
            bfs.push_back(x);
            y.case_number_requirement = caseCount;
            y.step_number = x.step_number;
            visitedBoolArray[x.val_a][x.val_b][x.val_c][x.val_d] = y;
            //        visited.push_back(x);
        }
    }
    //fill D
    if (tmp.val_d != d) {
        x = tmp;
        x.val_d = d;
        x.step_number++;
        if (check(x)) {
            bfs.push_back(x);
            y.case_number_requirement = caseCount;
            y.step_number = x.step_number;
            visitedBoolArray[x.val_a][x.val_b][x.val_c][x.val_d] = y;
            //        visited.push_back(x);
        }
    }
}
void empty_all(step tmp) {
    step x;
    step2 y;
    
    //fill A
    if (tmp.val_a != 0) {
        x = tmp;
        x.val_a = 0;
        x.step_number++;
        if (check(x)) {
            bfs.push_back(x);
            y.case_number_requirement = caseCount;
            y.step_number = x.step_number;
            visitedBoolArray[x.val_a][x.val_b][x.val_c][x.val_d] = y;
            //        visited.push_back(x);
        }
    }
    //fill B
    if (tmp.val_b != 0) {
        x = tmp;
        x.val_b = 0;
        x.step_number++;
        if (check(x)) {
            bfs.push_back(x);
            y.case_number_requirement = caseCount;
            y.step_number = x.step_number;
            visitedBoolArray[x.val_a][x.val_b][x.val_c][x.val_d] = y;
            //        visited.push_back(x);
        }
    }
    //fill C
    if (tmp.val_c != 0) {
        x = tmp;
        x.val_c = 0;
        x.step_number++;
        if (check(x)) {
            bfs.push_back(x);
            y.case_number_requirement = caseCount;
            y.step_number = x.step_number;
            visitedBoolArray[x.val_a][x.val_b][x.val_c][x.val_d] = y;
            //        visited.push_back(x);
        }
    }
    //fill D
    if (tmp.val_d != 0) {
        x = tmp;
        x.val_d = 0;
        x.step_number++;
        if (check(x)) {
            bfs.push_back(x);
            y.case_number_requirement = caseCount;
            y.step_number = x.step_number;
            visitedBoolArray[x.val_a][x.val_b][x.val_c][x.val_d] = y;
            //        visited.push_back(x);
        }
    }
}
void transfer(step tmp, int a, int b, int c, int d) {
    step x;
    step2 y;
    //----------------A to others
    //A to B
    if (tmp.val_a != 0) {
        if (tmp.val_b != b) {
            x = tmp;
            if (x.val_a + x.val_b <= b) {
                x.val_b += x.val_a;
                x.val_a = 0;
            } else if (x.val_a + x.val_b > b) {
                x.val_a = x.val_a - (b - x.val_b);
                x.val_b = b;
            }
            x.step_number++;
            if (check(x)) {
                bfs.push_back(x);
                y.case_number_requirement = caseCount;
                y.step_number = x.step_number;
                visitedBoolArray[x.val_a][x.val_b][x.val_c][x.val_d] = y;
                //            visited.push_back(x);
            }
            
        }
        if (tmp.val_c != c) {
            //A to C
            x = tmp;
            if (x.val_a + x.val_c <= c) {
                x.val_c += x.val_a;
                x.val_a = 0;
            } else if (x.val_a + x.val_c > c) {
                x.val_a = x.val_a - (c - x.val_c);
                x.val_c = c;
            }
            x.step_number++;
            if (check(x)) {
                bfs.push_back(x);
                y.case_number_requirement = caseCount;
                y.step_number = x.step_number;
                visitedBoolArray[x.val_a][x.val_b][x.val_c][x.val_d] = y;
                //            visited.push_back(x);
            }
        }
        //A to D
        if (tmp.val_d != d) {
            x = tmp;
            if (x.val_a + x.val_d <= d) {
                x.val_d += x.val_a;
                x.val_a = 0;
            } else if (x.val_a + x.val_d > d) {
                x.val_a = x.val_a - (d - x.val_d);
                x.val_d = d;
            }
            x.step_number++;
            if (check(x)) {
                bfs.push_back(x);
                y.case_number_requirement = caseCount;
                y.step_number = x.step_number;
                visitedBoolArray[x.val_a][x.val_b][x.val_c][x.val_d] = y;
                //            visited.push_back(x);
            }
            
        }
        
    }
    //----------------B to others
    //B to A
    if (tmp.val_b != 0) {
        if (tmp.val_a != a) {
            x = tmp;
            if (x.val_b + x.val_a <= a) {
                x.val_a += x.val_b;
                x.val_b = 0;
            } else if (x.val_b + x.val_a > a) {
                x.val_b = x.val_b - (a - x.val_a);
                x.val_a = a;
            }
            x.step_number++;
            if (check(x)) {
                bfs.push_back(x);
                y.case_number_requirement = caseCount;
                y.step_number = x.step_number;
                visitedBoolArray[x.val_a][x.val_b][x.val_c][x.val_d] = y;
                //        visited.push_back(x);
            }
        }
        if (tmp.val_c != c) {
            
            //B to C
            x = tmp;
            if (x.val_b + x.val_c <= c) {
                x.val_c += x.val_b;
                x.val_b = 0;
            } else if (x.val_b + x.val_c > c) {
                x.val_b = x.val_b - (c - x.val_c);
                x.val_c = c;
            }
            x.step_number++;
            if (check(x)) {
                bfs.push_back(x);
                y.case_number_requirement = caseCount;
                y.step_number = x.step_number;
                visitedBoolArray[x.val_a][x.val_b][x.val_c][x.val_d] = y;
                //        visited.push_back(x);
            }
        }
        //B to D
        if (tmp.val_d != d) {
            x = tmp;
            if (x.val_b + x.val_d <= d) {
                x.val_d += x.val_b;
                x.val_b = 0;
            } else if (x.val_b + x.val_d > d) {
                x.val_b = x.val_b - (d - x.val_d);
                x.val_d = d;
            }
            x.step_number++;
            if (check(x)) {
                bfs.push_back(x);
                y.case_number_requirement = caseCount;
                y.step_number = x.step_number;
                visitedBoolArray[x.val_a][x.val_b][x.val_c][x.val_d] = y;
                //        visited.push_back(x);
            }
        }
        
    }
    //----------------C to others
    //C to A
    if (tmp.val_c != 0) {
        if(tmp.val_a!=a){
            x = tmp;
            if (x.val_c + x.val_a <= a) {
                x.val_a += x.val_c;
                x.val_c = 0;
            } else if (x.val_c + x.val_a > a) {
                x.val_c = x.val_c - (a - x.val_a);
                x.val_a = a;
            }
            x.step_number++;
            if (check(x)) {
                bfs.push_back(x);
                y.case_number_requirement = caseCount;
                y.step_number = x.step_number;
                visitedBoolArray[x.val_a][x.val_b][x.val_c][x.val_d] = y;
                //        visited.push_back(x);
            }
        }
        if(tmp.val_b!=b){
            //C to B
            x = tmp;
            if (x.val_c + x.val_b <= b) {
                x.val_b += x.val_c;
                x.val_c = 0;
            } else if (x.val_c + x.val_b > b) {
                x.val_c = x.val_c - (b - x.val_b);
                x.val_b = b;
            }
            x.step_number++;
            if (check(x)) {
                bfs.push_back(x);
                y.case_number_requirement = caseCount;
                y.step_number = x.step_number;
                visitedBoolArray[x.val_a][x.val_b][x.val_c][x.val_d] = y;
                //        visited.push_back(x);
            }
        }
        //C to D
        if(tmp.val_d!=d){
            x = tmp;
            if (x.val_c + x.val_d <= d) {
                x.val_d += x.val_c;
                x.val_c = 0;
            } else if (x.val_c + x.val_d > d) {
                x.val_c = x.val_c - (d - x.val_d);
                x.val_d = d;
            }
            x.step_number++;
            if (check(x)) {
                bfs.push_back(x);
                y.case_number_requirement = caseCount;
                y.step_number = x.step_number;
                visitedBoolArray[x.val_a][x.val_b][x.val_c][x.val_d] = y;
                //        visited.push_back(x);
            }
        }
    }
    //----------------D to others
    //D to A
    if (tmp.val_d != 0) {
        if(tmp.val_a!=a){
            x = tmp;
            if (x.val_d + x.val_a <= a) {
                x.val_a += x.val_d;
                x.val_d = 0;
            } else if (x.val_d + x.val_a > a) {
                x.val_d = x.val_d - (a - x.val_a);
                x.val_a = a;
            }
            x.step_number++;
            if (check(x)) {
                bfs.push_back(x);
                y.case_number_requirement = caseCount;
                y.step_number = x.step_number;
                visitedBoolArray[x.val_a][x.val_b][x.val_c][x.val_d] = y;
                //        visited.push_back(x);
            }
        }
        if(tmp.val_b!=b){
            //D to B
            x = tmp;
            if (x.val_d + x.val_b <= b) {
                x.val_b += x.val_d;
                x.val_d = 0;
            } else if (x.val_d + x.val_b > b) {
                x.val_d = x.val_d - (b - x.val_b);
                x.val_b = b;
            }
            x.step_number++;
            if (check(x)) {
                bfs.push_back(x);
                y.case_number_requirement = caseCount;
                y.step_number = x.step_number;
                visitedBoolArray[x.val_a][x.val_b][x.val_c][x.val_d] = y;
                //        visited.push_back(x);
            }
        }
        //D to C
        if(tmp.val_c!=c){
            x = tmp;
            if (x.val_d + x.val_c <= c) {
                x.val_c += x.val_d;
                x.val_d = 0;
            } else if (x.val_d + x.val_c > c) {
                x.val_d = x.val_d - (c - x.val_c);
                x.val_c = c;
            }
            x.step_number++;
            if (check(x)) {
                bfs.push_back(x);
                y.case_number_requirement = caseCount;
                y.step_number = x.step_number;
                visitedBoolArray[x.val_a][x.val_b][x.val_c][x.val_d] = y;
                //        visited.push_back(x);
            }
        }
    }
}

int main() {
    //        cout<<"start"<<endl;
    int a, b, c, d, T, answer;
    bool flag;
    while (cin >> a >> b >> c >> d >> T) {
        caseCount += 1;
        flag = false;
        answer = -1;
        if(T>a && T>b && T>c && T>d){
            cout<<-1<<endl;
        }
        else if(T==a||T==b||T==c||T==d){
            cout<<1<<endl;
        }
        else{
        step aa;
        aa.step_number = 0;
        aa.val_a = 0;
        aa.val_b = 0;
        aa.val_c = 0;
        aa.val_d = 0;
        bfs.push_back(aa);
        //        visited.push_back(aa);
        visitedBoolArray[0][0][0][0].case_number_requirement = caseCount;
        visitedBoolArray[0][0][0][0].step_number = 0;
        while (!bfs.empty()) {
            step temp = bfs.front();
            bfs.pop_front();
            if (temp.val_a == T || temp.val_b == T || temp.val_c == T || temp.val_d == T) {
                flag = true;
                answer = temp.step_number;
            }
            if (flag) {
                break;
            }
            fill_all(temp, a, b, c, d);
            empty_all(temp);
            transfer(temp, a, b, c, d);
            
        }
        cout << answer << endl;
        bfs.clear();
        }
    }
    return 0;
}
