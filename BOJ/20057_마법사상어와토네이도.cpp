#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
typedef pair<int,int> pii;
pii operator+ ( const pii &x, const pii &y){
    return make_pair(x.first+y.first, x.second+y.second);
}
int n,out = 0;
vector<vector<int>> A;
vector<float> ratio = {1,1,2,2,5,7,7,10,10};//{0.01,0.01,0.02,0.02,0.05,0.07,0.07,0.1,0.1};
vector<pii> blow[4]=
{{{-1,1},{1,+1},{-2,0},{2,0},{0,-2},{-1,0},{1,0},{-1,-1},{1,-1},{0,-1}},//2<-
{{-1,-1},{-1,1},{0,-2},{0,2},{2,0},{0,-1},{0,1},{1,-1},{1,1},{1,0}},//3 아래로
{{-1,-1},{1,-1},{-2,0},{2,0},{0,2},{-1,0},{1,0},{-1,1},{1,1},{0,1}},//0 ->
{{1,-1},{1,1},{0,-1},{0,2},{-2,0},{0,-1},{0,1},{-1,-1},{-1,1},{-1,0}}};//1 위로
void showA(){
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"**out**"<<out<<endl;
}
pii now;
void wind(int x, int y,int dir){
    now = now+make_pair(x,y);
    cout<<endl<<now.first<<","<<now.second<<endl;
    int sand = A[now.first][now.second],cnt=0;
    A[now.first][now.second] = 0;
    pii kan;
    for(int i=0;i<blow[dir].size();i++){
        kan = now+blow[dir][i];
        //cout<<floor(ratio[i]*sand)<<" ";
        int nxt_sand;
        if(i==blow[dir].size()-1) {
            nxt_sand = sand - cnt;
        }
        else{
            nxt_sand = (sand*ratio[i])/100;
            cnt+=nxt_sand;
        }
        if(kan.first<n&&kan.first>=0&&kan.second<n&&kan.second>=0){
            A[kan.first][kan.second]+=nxt_sand;
            
        }
        else{
            out+=nxt_sand;
        }
    }
    showA();
}
void windBlow(int x, int dir){
    for(int i=0;i<x;i++){
        if(dir==0) wind(0,-1,0);
        else if(dir==1) wind(1,0,1);
        else if(dir==2) wind(0,1,2);
        else if(dir==3) wind(-1,0,3);
    } 
}

void game(){
    for(int i=1;i<n;i++){
        cout<<"-----------------------"<<i<<endl;
        windBlow(i,0);
        windBlow(i,1);
        i++;
        windBlow(i,2);
        windBlow(i,3);
    }
    cout<<"--------------------------LAST--"<<endl;
    windBlow(n-1,0);
}

int main(){
    cin>>n;
    
    for(int i=0;i<n;i++){
        vector<int> temp;
        int sand;
        for(int j=0;j<n;j++){
            cin>>sand;
            temp.push_back(sand);
        }
        A.push_back(temp);
    }
    now = make_pair(n/2,n/2);
    game();
    cout<<out;
    return 0;
}