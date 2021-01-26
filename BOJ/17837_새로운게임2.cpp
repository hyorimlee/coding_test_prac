#include <iostream>
#include <vector>
#include <list>
using namespace std;
//splice 써볼것
//vector<클래스*> 이용하기
typedef pair<int,int> pii;
int n,k;

pii operator+ (const pii &x, const pii &y){
    return make_pair(x.first+y.first, x.second+y.second);
}

pii operator*(int y, const pii &x){
    return make_pair(x.first*y,x.second*y);
}

class horse{
    public:
    pii dir;
    pii pos;
    int num;

    horse(){
        dir = make_pair(0,0);
        pos = make_pair(0,0);
        num = -1;
    }
    horse(int i,int x, int y, int d){
        num = i;
        pos = make_pair(x,y);
        if(d==1){
            dir = make_pair(0,1);
        }
        else if(d==2){
            dir = make_pair(0,-1);
        }
        else if(d==3){
            dir = make_pair(-1,0);
        }
        else{
            dir = make_pair(1,0);
        }
    }
};
vector<horse> horses;
void selectHorse(int idx, pii now, vector<vector<vector<int>>> &board, list<int> &container){
    int met = -1;
    for(int i=0;i<board[now.first][now.second].size();i++){
        if(met>0) container.push_back(board[now.first][now.second][i]);
        if(board[now.first][now.second][i] == idx){
            met = i;
        }
        
    }
    cout<<"container : "<<container.size()<<endl;
    for(int i=met;i<container.size();i++){
        board[now.first][now.second].pop_back();
    }
    
}
int moveH(vector<vector<vector<int>>> &board,pii nxt, const list<int> &c){
    cout<<"-Size : "<<board[nxt.first][nxt.second].size()<<", con.size : "<<c.size()<<endl;
    for(int i:c){
        board[nxt.first][nxt.second].push_back(i);
        horses[i].pos = nxt;
    }
    cout<<"Size : "<<board[nxt.first][nxt.second].size()<<endl;
    if(board[nxt.first][nxt.second].size() > 3) {
        //cout<<nxt.first<<","<<nxt.second<<endl;//debug
        return true;
    }
    return false;
}
int Game(vector<vector<vector<int>>> &board, const vector<vector<int>> &chess){
    int turn;
    for(int turn = 1;turn<=10000;turn++){
        cout<<turn<<"*****************"<<endl;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cout << board[i][j].size(); 
                cout << "("; 
                    for(auto it = board[i][j].begin(); it != board[i][j].end(); it++)
                        cout << (*it) << ", "; 
                    cout << ")" << "\t";
            }
            cout << endl; 
        }


        for(int i=0;i<horses.size();i++){
            
            horse* now = &horses[i];
            list<int> container = {i};

            selectHorse(i,now->pos,board,container);

            pii nxt = now->pos+now->dir;
            if(chess[nxt.first][nxt.second] == 2){
                now->dir = -1*now->dir;
                nxt = now->pos+now->dir;
            }
            int state = chess[nxt.first][nxt.second];
            if(state == 2) continue;
            else if(state == 1) container.reverse();
            if(moveH(board,nxt, container)){
                return turn;
            }
        }
    }
    return -1;
}


int main(){
    cin>>n>>k;
    vector<vector<int>> t(n+2);
    vector<int> te(n+2);
    vector<vector<vector<int>>> board(n+2,t);
    vector<vector<int>> chess(n+2,te);
    for(int i=0;i<=n+1;i++){
        chess[i][0] = 2;
        chess[0][i] = 2;
        chess[n+1][i] = 2;
        chess[i][n+1] = 2;
    }
    int tmp;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>chess[i][j];
        }
    }

    for(int i=0;i<n+2;i++){
        for(int j=0;j<n+2;j++){
            cout<<chess[i][j]<<" ";
        }
        cout<<endl;
    }
    int x, y, d;
    for(int i=1;i<=k;i++){
        cin>>x>>y>>d;
        horse h (i,x,y,d);
        horses.push_back(h);
        board[x][y].push_back(i);
    }

    int ans = Game(board,chess);
    cout<<ans;

    return 0;
}