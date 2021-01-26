#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 100002;
const long long INF = 1000000040;
typedef vector<pair<int,int>> vpi;
priority_queue<pair<int,int>> pqpi;

int n,m,start,goal;
void dijstra(const vector<vpi> &grp){
    vector<long long> dist(n,INF);
    dist[start] = 0;
    pqpi.push(make_pair(0,start));
    int from, to, temp_cost,cost;
    while(pqpi.size()>0){
        cost = -pqpi.top().first;
        from = pqpi.top().second;
        pqpi.pop();
        for(int i=0;i<grp[from].size();i++){
            to = grp[from][i].first;
            temp_cost = cost+grp[from][i].second;
            if(temp_cost<dist[to]){
                dist[to]=temp_cost;
                pqpi.push(make_pair(-dist[to],to));
            }
        }
    }
    cout<<dist[goal];
}

int main(){
    cin>>n>>m;
    vector<vpi> grp(n);
    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        grp[a-1].push_back(make_pair(b-1,c));
    }
    cin>>start>>goal;
    start--;
    goal--;
    dijstra(grp);

}