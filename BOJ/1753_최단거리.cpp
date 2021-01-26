#include <iostream>
#include <queue>
#include <vector>
using namespace std;
priority_queue<pair<int,int>> pq;
const int MAX = 300001;
typedef vector<pair<int,int>> vpi;

int v,e,start;
void dijstra(const vector<vpi> &grp){
    vector<int> dist(v,MAX);
    dist[start] = 0;
    pq.push(make_pair(0,start));
    int cost, from,to;
    while(pq.size()>0){
        cost = -pq.top().first;
        from = pq.top().second;
        pq.pop();
        if(dist[from]<cost) continue;
        for(int i=0;i<grp[from].size();i++){
            to = grp[from][i].first;
            int temp_cost = cost+grp[from][i].second;
            if(temp_cost<dist[to]){
                dist[to] = temp_cost;
                pq.push(make_pair(-dist[to],to));
            }
        }
    }
    for(int i=0;i<v;i++){
        if(dist[i]==MAX) cout<<"INF"<<"\n";
        else cout<<dist[i]<<"\n";
    }
}
int main(){
    cin>>v>>e>>start;
    start--;
    vector<vpi> grp(v);
    int a,b,c;
    for(int i=0;i<e;i++){
        cin>>a>>b>>c;
        grp[a-1].push_back(make_pair(b-1,c));
        //grp[b-1].push_back(make_pair(a-1,c)); //방향없는 그래프인 경우
    }
    dijstra(grp);
    return 0;
}