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
vector<int> dice = {0,0,0,0,0,0};
int n,m,k,x,y;
pair<int,int> whatDo[5] = {{0,0},{0,1},{0,-1},{-1,0},{1,0}}, now;
bool turnDice(int what){
    //cout<<"do "<<what<<" ";
    //dice 위치 이동
    pair<int,int> nxt = now+whatDo[what];
    if(nxt.first<0||nxt.first>=n||nxt.second<0||nxt.second>=m) return false;
    now = nxt;
    //모양 변경
    int temp = dice[0];
    if(what == 1){//right
        dice[0] = dice[3];
        dice[3] = dice[5];
        dice[5] = dice[2];
        dice[2] = temp;
    }
    else if(what == 2){
        //left
        dice[0] = dice[2];
        dice[2] = dice[5];
        dice[5] = dice[3];
        dice[3] = temp;
    }
    else if (what == 3){
        //up
        dice[0] = dice[4];
        dice[4] = dice[5];
        dice[5] = dice[1];
        dice[1] = temp;
    
    }
    else if (what == 4){
        //down
        dice[0] = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[4];
        dice[4] = temp;
       
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
                board[now.first][now.second] = dice[5];
            }
            else {
                dice[5] = board[now.first][now.second];
                board[now.first][now.second] = 0;
            }
            //dice.print();
            cout<<dice[0]<<endl;
        }
    }
    return 0;
}