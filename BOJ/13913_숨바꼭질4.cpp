#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
queue<pair<int,int>> q;
vector<int> parent(100001,-1);
int n,k,last;
int chkThis(int x, int prt){
    if(x==k){
        last = prt;
        return 1;
    } 
    if(x>=0 && x<=100000 &&parent[x]==-1){
        parent[x] = prt;
        q.emplace(x,prt);
    }
    
    return 0;
}
void restorePath(){
    int x = last;
    stack<int> path;
    while(1){
        path.push(x);
        if(parent[x]==x) break;
        else   x = parent[x];
    }
    cout<<path.size()<<endl;
    while(path.size()>0) {
        cout<<path.top()<<" ";
        path.pop();
    }
    cout<<k;
}
int main(){
    cin>>n>>k;
    if(n==k){
        cout<<0<<endl<<n;
        return 0;
    }
    q.emplace(n,n);
    parent[n] = n;
    pair<int,int> now;
    while(q.size()>0){
        now = q.front();
        q.pop();
        if(chkThis(now.first-1,now.first)) break;
        if(chkThis(now.first+1,now.first)) break;
        if(chkThis(now.first*2,now.first)) break;
    }
    restorePath();
    return 0;
}