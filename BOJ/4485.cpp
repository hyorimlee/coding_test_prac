#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef vector<pair<int,int>> vpi;
const int MAX = 10,INF = 300000;
int temp[MAX][MAX];
priority_queue<pair<int,int>> pq;
int n,ini;
void dijstra(const vector<vpi> &grp){
    vector<int> dis(n*n,INF);
    dis[0] =0;
    int start = 0,cost, from, to, temp_cost;
    pq.push(make_pair(0,start));
    while(pq.size()>0){
        cost = -pq.top().first;
        from = pq.top().second;
        pq.pop();
        if(dis[from]<cost) continue;
        //cout<<"You are here"<<endl;
        for(int i=0;i<grp[from].size();i++){
            cout<<"**"<<pq.size()<<endl;
            to = grp[from][i].first;
            temp_cost = cost+grp[from][i].second;
            //cout<<"when to "<<to<<" ex cost was "<<cost<<"and new one : "<<grp[from][i].second<<" So, temp_cost = "<<temp_cost<<endl;
            if(temp_cost<dis[to]){
                dis[to] = temp_cost;
                pq.push(make_pair(-dis[to],to));
            }
        }
    }
    /*cout<<"--------------------"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dis[i*n+j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<dis[n*n-1]+ini<<endl;
}
int main(){
    n=1;
    while(n!=0){
        cin>>n;
        if(n==0) return 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>temp[i][j];
            }
        }
        ini =temp[0][0];
        temp[0][0]=0;
        vector<vpi> grp(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<=n-1;j++){
                if(j+1<n) grp[i*n+j].push_back(make_pair(i*n+j+1,temp[i][j+1]));
                if(j+1<n) grp[i*n+j+1].push_back(make_pair(i*n*j,temp[i][j]));

                if(i+1<n)grp[i*n+j].push_back(make_pair((i+1)*n+j,temp[i+1][j]));
                if(i+1<n) grp[(i+1)*n+j].push_back(make_pair(i*n+j,temp[i][j]));
            }   
        }
        //cout<<"Answer : ";
        dijstra(grp);
    }
    return 0;
}