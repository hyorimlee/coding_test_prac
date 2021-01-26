#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
pii operator+ (const pii &x, const pii &y){
    return make_pair(x.first+y.first,x.second+y.second);
}
bool operator==(const pii &x, const pii &y){
    if(x.first == y.first && x.second == y.second) return true;
    return false;
}

class fish{
    public:
    bool alive;
    pair<int,int> dir;
    int d;
    pair<int,int> where;
    int point;

    fish(int x, int y, int p, int d_){
        alive=true;
        d = d_;
        where.first = x;
        where.second = y;
        point = p;
        turndir(d);
    }
    void turndir(int d){
        if(d == 1){
            dir.first = -1;
            dir.second = 0;
        }
        else if(d ==2){
            dir.first = -1;
            dir.second = -1;
        }
        else if(d==3){
            dir.first = 0;
            dir.second = -1;
        }
        else if(d==4){
            dir.first = 1;
            dir.second = -1;
        }
        else if(d==5){
            dir.first = 1;
            dir.second= 0;
        }
        else if(d==6){
            dir.first = 1;
            dir.second = 1;
        }
        else if(d==7){
            dir.first = 1;
            dir.second = 0;
        }
        else if(d==8){
            dir.first = -1;
            dir.second = 1;
        }
    }
};
typedef vector<vector<fish*>> vvf;
vector<fish> fishes(16);
vector<fish*> s(4);
vvf sea(4,s);
int ans = 0;
bool chkDir(int i,fish f,const fish &shark){
    if(i==9) return false;
    pii now = f.where+f.dir;
    if(now.first>=4||now.first<0||now.second>4||now.second<0||now== shark.where){
        f.turndir(f.d+1);
        if(chkDir(i+1,f,shark)==false) return false;
    }
    return true;
    
}
void fishMove(const fish &shark){
    for(int i=0;i<16;i++){
        if(chkDir(0,fishes[i],shark)==false) continue;
        pii now = fishes[i].where;
        pii nxt = fishes[i].where+fishes[i].dir;
        sea[now.first][now.second] = sea[nxt.first][nxt.second];
        sea[nxt.first][nxt.second] = &fishes[i];  
    }
}
void findSharkNxt(const fish &shark,vector<pii> &candi){
    pii now = shark.where;
    while(1){
        now = now+shark.dir;
        if(now.first>=4||now.first<0||now.second>4||now.second<0) return;
        candi.push_back(now);
    }
}
void game(fish &shark,int ate, vvf sea){
    if(ate !=-1) fishMove(shark);
    else ate = 0;
    cout<<"ate : "<<ate<<endl;
    vector<pii> candi;
    findSharkNxt(shark,candi);
    pii now = shark.where;
    for(int i=0;i<candi.size();i++){
        shark = fishes[sea[candi[i].first][candi[i].second]->point];
        sea[candi[i].first][candi[i].second]->alive = false;
        ate += sea[shark.where.first][shark.where.second]->point;
        if(ate>ans) ans = ate;
        game(shark, ate,sea);
        ate -= sea[shark.where.first][shark.where.second]->point;
        sea[candi[i].first][candi[i].second]->alive = true;
    }

}

int main(){
    int a,b;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>a>>b;
            fish f1(i,j,a,b);
            fishes.push_back(f1);
        }
    }
    cout<<fishes[1].point<<endl;
    for(int i=0;i<=16;i++){
        fish f0(0,0,0,1);
        fishes.push_back(f0);
    }
    cout<<sea[0][0]->dir.first;

    fish shark = fishes[sea[0][0]->point];
    cout<<"d";
    sea[0][0]->alive = false;
    cout<<"r";
    game(shark,-1,sea);
    
    cout<<ans;
    return 0;
}