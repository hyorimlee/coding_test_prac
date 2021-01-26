#include <iostream>
#include <vector>
using namespace std;

class disjointset{
    public:
        vector<int> parent,rank;
        disjointset(int n) : parent(n),rank(n,1){
            for(int i=0;i<n;i++){
                parent[i] = i;
            }
        }
        int find(int u){
            if(u==parent[u]) return u;
            return parent[u] = find(parent[u]);
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
    int temp;
    int cnt = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>temp;
            if(temp == 1){
                set.merge(i,j);
            }
        }
    }
    int a,b;
    cin>>a;
    a--;
    for(int i=1;i<m;i++){
        cin>>b;
        b--;
        if(set.find(a)!=set.find(b)){
            cout<<"NO\n";
            return 0;
        }
        a=b;
    }
    cout<<"YES\n";
    
    return 0;
}