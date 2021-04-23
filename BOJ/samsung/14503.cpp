#include <iostream>
#include <vector>
using namespace std;
int cnt=0;
int n,m;
int place[52][52];
vector<pair<int,int>> direction = {{0,-1},{1,0},{0,1},{-1,0}};
void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<place[i][j]<<" ";
        }
        cout<<endl;
    }
}
pair<int,int> operator+ (pair<int,int> &l,pair<int,int> &r){
    return make_pair(l.first+r.first,l.second+r.second);
}
bool ChkPlace(pair<int,int> pos,bool onechk = false){
    if(onechk&&place[pos.first][pos.second]==2) return true;
    if(pos.first<0||pos.second<0||pos.first>n||pos.second>m) return false;
    if(place[pos.first][pos.second]==0) return true;
    return false;
}
void Clean(pair<int,int> now, int dir,bool back = false){
    if(back==false) cnt++;
    place[now.first][now.second] = 2;
    //cout<<cnt<<"---------------------------"<<now.first<<","<<now.second<<"--"<<dir<<endl;
    bool found = false;
    for(int i=0;i<4;i++){
        dir = (dir+1)%4;
        
        if(ChkPlace(now+direction[dir])){
            found = true;
            break;
        }
    }
    if(found) Clean(now+direction[dir],dir);
    else if(ChkPlace(now+direction[(dir+2)%4])) Clean(now+direction[(dir+2)%4],dir);
    else if(ChkPlace(now+direction[(dir+2)%4],true)) Clean(now+direction[(dir+2)%4],dir,true);
    else return;
}
int main(){
    cin>>n>>m;
    int dir,r,c;
    cin>>r>>c>>dir;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>place[i][j];
        }
    }
    Clean(make_pair(r,c),3-dir);
    cout<<cnt;
    return 0;
}