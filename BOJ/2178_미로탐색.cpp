#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
int n,m;
pii operator+(const pii &x, const pii &y){
    return make_pair(x.first+y.first,x.second+y.second);
}
vector<pii> dir={{-1,0},{0,1},{1,0},{0,-1}};
void findLeast(int cnt,vector<vector<char>> &visited, const vector<vector<char>> &miro,queue<pii> &q){
    queue<pii> nxtq;
    pii now,nxt;
    while(q.size()>0){
        now = q.front();
        q.pop();
        if(now.first==n-1&&now.second==m-1){
            cout<<cnt;
            return;
        }
        for(int i=0;i<4;i++){
            nxt = now+dir[i];
            if(nxt.first==n&&now.second==m){
                cout<<cnt;
                return;
            }
            if(nxt.first<n&&nxt.first>=0&&nxt.second<m&&nxt.second>=0){
                if(miro[nxt.first][nxt.second]=='1'&&visited[nxt.first][nxt.second]=='1'){
                    nxtq.push(nxt);
                    visited[nxt.first][nxt.second]='0';
                }
            }
        }
    }
    findLeast(cnt+1,visited,miro,nxtq);
}

int main(){
    cin>>n>>m;
    vector<char> miro_temp(m,'1');
    vector<vector<char>> miro(n,miro_temp);
    queue<pii> q;
    q.emplace(0,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>miro[i][j];
    }
    vector<vector<char>> visited = miro;
    q.emplace(0,0);
    visited[0][0] = '0';
    findLeast(1,visited, miro, q);
    return 0;
}