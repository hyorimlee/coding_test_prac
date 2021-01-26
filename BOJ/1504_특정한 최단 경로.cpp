#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef vector<pair<int,int>> vpi;
const int MAX = 105,INF = 880000;
int m,n;
char miro[MAX][MAX];
pair<int,int> operator + (pair<int,int> &first, pair<int,int> &second){
    int x = first.first + second.first;
    int y = first.second + second.second;
    return make_pair(x,y);
}
vector<pair<int,int>> letsgo{{0,1},{1,0},{-1,0},{0,-1}};
pair<int,int> spot(int k){
    return make_pair(k/m,k%m);
}
void dijstra(){
    priority_queue<pair<int,int>> pq;
    vector<int> dist (n*m,INF);
    dist[0] = 0;
    pq.push(make_pair(0,0));
    int cost,temp_cost,from,to;
    pair<int,int> fromP, toP;
    while(pq.size()>0){
        //cout<<"pqsize:"<<pq.size()<<endl;
        cost = -pq.top().first;
        from = pq.top().second;
        pq.pop();
        if(cost>dist[from]) continue;
        fromP = spot(from);
        for(int i=0;i<4;i++){
            toP = fromP+letsgo[i];
            to = toP.first*m+toP.second;
            //cout<<"I will update "<<to<<" and i "<<i<<"---> from "<<from<<endl;
            //cout<<"now : "<<toP.first<<" "<<toP.second<<endl;
            if(toP.first<0||toP.second<0||toP.first>=n||toP.second>=m) continue;
            
            if(miro[toP.first][toP.second] == '0') temp_cost = cost;
            if(miro[toP.first][toP.second] == '1') temp_cost = cost+1;
            if(temp_cost<dist[to]){
                dist[to] = temp_cost;
                pq.push(make_pair(-dist[to],to));
                //cout<<"UPDATE!! "<<to<<" : "<<dist[to]<<endl;
                //cout<<"---------------------------------"<<endl;
            }            
        }
    }
    /*
    for(int i=0;i<m*n;i++){
        cout<<dist[i]<<" ";
    }*/
    cout<<dist[m*n-1];
}
int main(){
    cin>>m>>n;
    /*
    for(int i=0;i<=m;i++){
        miro[0][i] = 'X';
        miro[n+1][i] = 'X';
    }
    for(int i=0;i<=n;i++){
        miro[i][0] = 'X';
        miro[i][m+1] = 'X';
    }*/

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>miro[i][j];
        }
    }
    dijstra();
    return 0;
}