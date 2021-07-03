#include <iostream>
#include <queue>
#include <vector>
using namespace std;
queue<pair<int,int>> q;
int s;
vector<int> t(10000,-1);
vector<vector<int>> visited(10000,t);
void pushIt(int x, int y,int cnt){
    if(x<0||y<0||visited[x][y]>-1) return;
    visited[x][y] = cnt;
    q.emplace(x,y);
}
int main(){
    q.emplace(1,0);
    cin>>s;
    pair<int,int> now;
    int cnt = 0;
    visited[1][0] = 0;
    while(q.size()>0){
        now = q.front();
        q.pop();
        cnt = visited[now.first][now.second]+1;
        pushIt(now.first,now.first,cnt);
        if(now.first+now.second == s) break;
        pushIt(now.first+now.second,now.second,cnt);
        pushIt(now.first-1,now.second,cnt);

    }
    cout<<cnt;
    return 0;
}