#include <iostream>
#include <vector>
using namespace std;

class disjointset {
    public:
        vector<int> parent, rank;
        disjointset(int n) : parent(n),rank(n,1) {
            for(int i=0;i<n;i++)
                parent[i]=i;
        }
        int find(int u){
            if(u==parent[u]) return u;
            return parent[u] = find(parent[u]);
        }
        void merge(int u,int v){
            u = find(u);
            v = find(v);
            if(rank[u]>rank[v]) swap(u,v);
            parent[u] = v;
            if(rank[u]==rank[v]) ++rank[v]; 
        }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    n++;
    disjointset set(n+1);
    int prob,a,b;
    for(int i=0;i<m;i++){
        cin>>prob>>a>>b;
        if(prob==0){
            set.merge(a,b);
        }
        else{
            if(set.find(a)==set.find(b)) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}