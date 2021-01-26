#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class disjointset{
    public:
        vector<int> parent, rank;
        disjointset(int n) : parent(n),rank(n,1){
            for(int i=0;i<n;i++)
                parent[i] = i;
        }
        int find(int u){
            if(u==parent[u]) return u;
            return parent[u]=find(parent[u]);
        }
        void merge(int u,int v){
            u = find(u);
            v = find(v);
            if(u>v) swap(u,v);
            parent[u] = v;
            if(rank[u]==rank[v]) rank[v]++;
        }
};

int main(){
    int n,m;
    cin>>n>>m;
    disjointset set(n);
    int k,a,b,tr=0;
    cin>>k;
    if(k>0) {
        cin>>a;
        tr = --a;
    }
    else tr = -1;
    for(int i=1;i<k;i++){
        cin>>b;
        set.merge(a,--b);
        a = b;
    }
    vector<int> whichparty(m);
    for(int i=0;i<m;i++){
        int how;
        cin>>how;
        cin>>a;
        a--;
        whichparty[i]=a;
        for(int j=1;j<how;j++){
            cin>>b;
            b--;
            set.merge(a,b);
            a=b;
        }
    }
    int cnt = 0;
    if(tr>-1) tr = set.find(tr);
    for(int i=0;i<m;i++){
        
        if(tr==set.find(whichparty[i])) continue;
        else ++cnt;
    }
    cout<<cnt;

    return 0;
}