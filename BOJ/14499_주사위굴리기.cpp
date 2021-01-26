#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void print(vector<vector<int>> dice, vector<vector<int>> map,int n,int m){

    cout<<"----------MAP-----------"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }    
    cout<<"----------DICE-----------"<<endl;
    cout<<" "<<dice[0][1]<<endl;
    cout<<dice[1][0]<<dice[1][1]<<dice[1][2]<<endl;
    for(int i=2;i<4;i++){
        cout<<" "<<dice[i][1]<<endl;
    }
}
int play(const int req, pair<int,int> &now,vector<vector<int>> &map,vector<vector<int>> &dice, pair<int,int> &down,const int m, const int n){
    pair<int,int> go= {0,0};
    cout<<req<<" : ";
    if(req==1) {
        if(now.second+1 >=m) { cout<<"1 FUCK"<<endl;return 0;}
        now.second=(now.second+1);
        down.second=(down.second+1)%3;
    }
    else if(req==2){
        if(now.second-1<0){ cout<<"2 FUCK"<<endl;return 0;}
        now.second=(now.second-1);
        down.second=(down.second+2)%3;
    }
    else if(req==3){
        if(now.first-1<0) { cout<<"3 FUCK"<<endl;return 0;}
        now.first=(now.first-1);
        down.first=(down.first+1)%3;
    }
    else if(req==4){
        if(now.first+1>=n) { cout<<"4 FUCK"<<endl;return 0;}
        now.first=(now.first+1);
        down.first=(down.first+2)%3;
    }

    if (map[now.first][now.second] == 0){
        map[now.first][now.second] = dice[down.first][down.second];
    }
    else{
        dice[down.first][down.second]=map[now.first][now.second];
        if(down.second==0||down.second==2){
            for(int i=0;i<4;i++){
                dice[i][down.second]=map[now.first][now.second];
            }
        }
        map[now.first][now.second]=0;
    }
    pair<int,int> up = down;
    down.first=(down.first+2)%3;
    down.second=(down.second+2)%3;
    //cout<<"======================THE ANSWER IS ================="<<endl;
    cout<<dice[down.first][down.second]<<endl;
    //print(dice,map,n,m);
    return 0;
    
}

int main(){
    int n,m,x,y,k;
    cin>>n>>m>>x>>y>>k;
    vector<int> sub_map(m);
    vector<vector<int>> map(n,sub_map);
    vector<int> sub_dice(3,0);
    vector<vector<int>> dice(4,sub_dice);
    queue<int> quest;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
        }
    }
    int temp;
    pair<int,int> now ={x,y},down = {3,1};
    for(int test=0;test<k;test++){
        cin>>temp;
        play(temp,now,map,dice,down,m,n);
    }   

    return 0;
}