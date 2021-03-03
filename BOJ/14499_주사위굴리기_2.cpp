//2021.03.03
#include <iostream>
#include <vector>
#include <list>
using namespace std;
pair<int,int> operator+ (const pair<int,int> &x, const pair<int,int> &y){
    return make_pair(x.first+y.first,x.second+y.second);
}
bool operator== (const pair<int,int> &x, const pair<int,int> &y){
    if(x.first==y.first&&x.second==y.second) return true;
    return false;
}
class d{
    public:
    int down = 5;
    int up = 0;
    vector<int> point = {0,0,0,0,0,0};
    list<int> lr = {5,3,0,2};
    list<int> ud = {5,4,0,1};
    void print(){
        list<int>::iterator iter = lr.begin();
        cout<<"up : "<<up<<" down : "<<down;
        cout<<" lr : "<<*iter++<<*iter++<<*iter++<<*iter;
        iter = ud.begin();
        cout<<" ud : "<<*iter++<<*iter++<<*iter++<<*iter;
        cout<<" ";
    }
};
int n,m,k,x,y;
pair<int,int> whatDo[5] = {{0,0},{0,1},{0,-1},{-1,0},{1,0}}, now;
d dice;
bool turnDice(int what){
    //cout<<"do "<<what<<" ";
    //dice 위치 이동
    pair<int,int> nxt = now+whatDo[what];
    if(nxt.first<0||nxt.first>=n||nxt.second<0||nxt.second>=m) return false;
    now = nxt;
    //모양 변경
    list<int>::iterator iter_lr = dice.lr.begin();
    list<int>::iterator iter_ud = dice.ud.begin();
    if(what == 1){//right
        dice.down = dice.lr.back();
        iter_lr++;
        dice.up = *(iter_lr);
        int temp = dice.lr.back();
        dice.lr.pop_back();
        dice.lr.push_front(temp);
        *(iter_ud) = dice.down;
        iter_ud++;
        iter_ud++;
        *(iter_ud) = dice.up;
    }
    else if(what == 2){
        //left
        //update up,down
        iter_lr++;
        dice.down = *(iter_lr);
        dice.up = dice.lr.back();
        //chanage lr
        int temp = dice.lr.front();
        dice.lr.pop_front();
        dice.lr.push_back(temp);
        //chagne ud
        *(iter_ud) = dice.down;
        iter_ud++;
        iter_ud++;
        *(iter_ud) = dice.up;
    }
    else if (what == 3){
        //up
        dice.down = dice.ud.back();
        iter_ud++;
        dice.up = *(iter_ud);

        int temp = dice.ud.back();
        dice.ud.pop_back();
        dice.ud.push_front(temp);

        *(iter_lr) = dice.down;
        iter_lr++;
        iter_lr++;
        *(iter_lr) = dice.up;
    }
    else if (what == 4){
        //down
        iter_ud++;
        dice.down = *(iter_ud);
        dice.up = dice.ud.back();

        int temp = dice.ud.front();
        dice.ud.pop_front();
        dice.ud.push_back(temp);

        *(iter_lr) = dice.down;
        iter_lr++;
        iter_lr++;
        *(iter_lr) = dice.up;
    }
    return true;
}

int main(){
    cin>>n>>m>>now.first>>now.second>>k;
    vector<int> te(m);
    vector<vector<int>> board(n,te);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }
    int what;
    for(int i=0;i<k;i++){
        cin>>what;
        if(turnDice(what)){
            if(board[now.first][now.second] == 0){
                board[now.first][now.second] = dice.point[dice.down];
            }
            else {
                dice.point[dice.down] = board[now.first][now.second];
                board[now.first][now.second] = 0;
            }
            //dice.print();
            cout<<dice.point[dice.up]<<endl;
        }
    }
    return 0;
}