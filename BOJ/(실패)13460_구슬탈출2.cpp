//2020.09.05
#include <iostream>
#include <vector>

using namespace std;
typedef vector<pair<int,int>> vpi;
const int MAX = 11;
char board[MAX][MAX];
int n,m;
bool found = false;
int BLUE = 0,RED=1;
void inclineBoard(int cnt, vpi pos);
bool moveMarble(int cnt,int x, int y,vpi &pos){
    int a[2],b[2],temp;
    bool change = false;
    for(int i=0;i<2;i++){
        a[i] = pos[i].first+x;
        b[i] = pos[i].second+y;
        while(board[a[i]][b[i]]=='.'){
            change = true;
            a[i]+=x;
            b[i]+=y;
        }
    }
    if(!change) return false;
    bool sameway = false;
    if(a[0]==a[1]&&b[0]==b[1]){
        sameway=true;
        if(x==-1){
            if(pos[BLUE].first<pos[RED].first){
                a[RED]++;
            }
            else a[BLUE]++;
        }
        else if(x==1){
            if(pos[BLUE].first<pos[RED].first){
                a[BLUE]--;
            }
            else a[RED]--;
        }
        else if(y==-1){
            if(pos[BLUE].second<pos[RED].second){
                b[RED]++;
            }
            else b[BLUE]++;
        }
        else if(y==1){
            if(pos[BLUE].second<pos[RED].second){
                b[BLUE]--;
            }
            else b[RED]--;
        }
    }
    for(int i=0;i<2;i++){
        if(board[a[i]][b[i]]=='O'){
            if(i==RED&&!sameway){
                if(!found){
                    found = true;
                    cout<<endl<<"-------------------------------"<<endl;
                    cout<<cnt;
                }
                return false;
            }
            return false;
        }
    }
    
    for(int k=0;k<2;k++){
        pos[k].first=a[k]-x;
        pos[k].second=b[k]-y;
    }
    cout<<"*********** x = "<<x<<" y = "<<y<<" (";
    cout<<pos[1].first<<","<<pos[1].second<<") "<<cnt<<endl;
    
    return true;
}
int xlist[4] = {-1,1,0,0};
int ylist[4] = {0,0,1,-1};
void inclineBoard(int cnt, vpi pos){
    vector<bool> check(4);
    if(cnt==10||found) return;
    vector<vpi> nxt(4,pos);
    int state;
    cnt++;
    for(int i=0;i<4;i++){
        check[i] = moveMarble(cnt,xlist[i],ylist[i],nxt[i]);
    }
    //cout<<"*******************************"<<nxt[0][1].first<<","<<nxt[0][1].second<<endl;
    for(int i=0;i<4;i++){
        if(check[i]) inclineBoard(cnt,nxt[i]);
    }
    return;
}
int main(){
    vector<pair<int,int>> pos(2);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
            if(board[i][j]=='B') pos[0]=make_pair(i,j); 
            else if(board[i][j]=='R') pos[1]=make_pair(i,j);
        }
    }
    for(int k=0;k<2;k++){
        board[pos[k].first][pos[k].second] ='.';
    }
    inclineBoard(0,pos);
    if(found==false) cout<<-1;

/*
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<board[i][j];
        }
        cout<<endl;
    }*/
    return 0;
}