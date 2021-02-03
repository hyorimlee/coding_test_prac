//21.02.03
//구슬탈출2
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
typedef struct { pii b; pii r;} st;
int n,m;
char board[11][11];
bool visited[11][11][11][11];//b,r
pii dir[4] = {{0,-1},{0,1},{-1,0},{1,0}};
pii operator*(const pii &x, const pii &y){
    return make_pair(x.first*y.first, x.second*y.second);
}
pii operator+(const pii &x, const pii &y){
    return make_pair(x.first+y.first, x.second+y.second);
}
int tilt(pii B,pii R, int d,queue<st> &marble){
    pii mar[2];
    char fir;
    //순서 정하기
    //(x,y)
    //왼쪽:y가 작은것, 오른쪽:y가 큰 것, 위:x가 작은 것, 아래:x가 큰것
    if((d<2&&dir[d].second*B.second>dir[d].second*R.second)
        ||(d>=2&&dir[d].first*B.first>dir[d].first*R.first)){
        fir = 'B';
        mar[0] = B;
        mar[1] = R;
    }
    else {
        fir = 'R';
        mar[0] = R;
        mar[1] = B;
    }

    bool found = false;
    for(int i=0;i<2;i++){
        while(mar[i].first>0&&mar[i].first<n-1
            &&mar[i].second>0&&mar[i].second<m-1){
            pii temp = mar[i]+dir[d];
            char what = board[temp.first][temp.second];
            if(what=='O'){
                if(i==0&&fir =='B'||i==1&&fir=='R') {
                    if(i==1)board[mar[0].first][mar[0].second] = '.';
                    return -1;//B가 빠지는 경우
                }
                found = true;
                break;
            }
            else if(what=='R'||what=='B'||what =='#') {
                if(i==0) board[mar[i].first][mar[i].second] = fir;
                break;
            }
            mar[i] = temp;
        }        
    }
    
    if(found) return 1;//R만 빠진 경우 1
    board[mar[0].first][mar[0].second] = '.';
    pii nxtR,nxtB;
    if (fir == 'R') {
        nxtR = mar[0];
        nxtB = mar[1];
    }
    else {
        nxtR = mar[1];
        nxtB = mar[0];
    }
    if(visited[nxtB.first][nxtB.second][nxtR.first][nxtR.second]) return 0;
    else {
        //cout<<"넣었어! "<<endl;
        visited[nxtB.first][nxtB.second][nxtR.first][nxtR.second] = true;
        marble.push({nxtB,nxtR});
    }
    return 0;
}

int game(int cnt,queue<st> marble){
    if(marble.size()==0) return -1;
    if(cnt>10) return -1;
    queue<st> nxt;
    while(marble.size()>0){
        //cout<<cnt<<" : "<<marble.front().b.first<<","<<marble.front().b.second<<" -- "<<marble.front().r.first<<","<<marble.front().r.second<<endl;
        pii B = marble.front().b;
        pii R = marble.front().r;
        marble.pop();
        int res;
        for(int i=0;i<4;i++){
            res = tilt(B,R,i,nxt);
            if(res == 1) return cnt;
        }
    }
    return game(cnt+1,nxt);
}

int main(){
    cin>>n>>m;
    queue<st> marble;
    pii b_,r_;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
            if(board[i][j]=='B'){
                b_= make_pair(i,j);
                board[i][j]='.';
            }
            else if(board[i][j]=='R'){
                r_ = make_pair(i,j);
                board[i][j]='.';
            }
        }
    }
    marble.push({b_,r_});
    cout<<game(1,marble);
    return 0;
}