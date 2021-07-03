#include <iostream>
#include <queue>
#include <vector>
using namespace std;
queue<pair<int,int>> q;
vector<int> visited(100001,-1);
int n,k;
int chkThis(int x, int cnt){
    if(x==k){
        cout<<cnt;
        return 1;
    } 
    if(x>=0 && x<=100000 &&visited[x]==-1){
        visited[x] = cnt;
        q.emplace(x,cnt);
    }
    return 0;
}
int main(){
    cin>>n>>k;
    if(n==k){
        cout<<0;
        return 0;
    }
    q.emplace(n,0);
    pair<int,int> now;
    while(q.size()>0){
        now = q.front();
        q.pop();
        if(chkThis(now.first-1,now.second+1)) break;
        if(chkThis(now.first+1,now.second+1)) break;
        if(chkThis(now.first*2,now.second+1)) break;
    }
    return 0;
}