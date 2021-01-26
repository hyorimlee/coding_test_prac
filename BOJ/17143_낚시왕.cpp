#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
pii operator +(const pii &x, const pii &y){
    return make_pair(x.first+y.first, x.second+y.second);
}

pii operator *(const int i,const pii &x){
    return make_pair(x.first*i,x.second*i);
}
int r,c,m;
class Shark{
    public:
        bool alive;
        pair<int,int> pos;
        int s;
        int z;
        int dir;
        pair<int,int> d;

        void show(){
            cout<<"pos : "<<pos.first<<","<<pos.second;
            cout<<" 속력 : "<<s<<" 크기 : "<<z<<" ("<<d.first<<","<<d.second<<")"<<endl;
        }

        Shark(int x,int y, int _s, int _d, int _z){
            alive = true;
            pos = make_pair(x,y);
            s = _s;
            dir = _d;
            if(_d == 1) {
                d = make_pair(-1,0);
                s%=2*(r-1);
            }
            else if(_d == 2) {
                d = make_pair(1,0);
                s%=2*(r-1);
            }
            else if(_d == 3) {
                d = make_pair(0,1);
                s%=2*(c-1);
            }
            else {
                d = make_pair(0,-1);
                s%=2*(c-1);
            }
            z = _z;
        }

};


vector<Shark> sharks;

int fishing(int fisher,bool debug = false){
    if(debug) cout<<"Fisher Move! and sharks are.."<<endl;
    int ans =0, fish_idx = m, fish_level = r+1;
    for(int i=0;i<(int)sharks.size();i++){
        Shark now = sharks[i];
        if(now.pos.second == fisher){//같은 열의 상어라면
            if(debug) cout<<"gotcha~"<<now.pos.first<<","<<now.pos.second;
            if(now.pos.first<fish_level){//가장 얕은 상어를 찾자
                fish_level = now.pos.first;
                fish_idx = i;
                ans = now.z;
            }
        }
    }
    if(ans>0){
        sharks.erase(sharks.begin()+fish_idx);
        if(debug) cout<<" got "<<fish_idx<<endl;
    }
    return ans;
}
void sharkMove(bool debug = false){
    vector<int> t(c+1,-1);
    vector<vector<int>> sea(r+1,t);//1로 초기화된 rxc 배열

    for(int i=0;i<(int)sharks.size();i++){
        Shark *now = &sharks[i];
        if(debug) cout<<sharks[i].z<<" is ";
        for(int j=0;j<now->s;j++){
            now->pos = now->pos+now->d;//상어 이동시킴
            if(debug) cout<<"("<<now->pos.first<<","<<now->pos.second<<") ";
            if(now->dir==1 && now->pos.first==1) now->dir=2;
            else if(now->dir==2 && now->pos.first == r) now->dir==1;
            else if(now->dir==3 && now->pos.second == c) now->dir=4;
            else if(now->dir==4 && now->pos.second == 1) now->dir=3;
            else continue;
            if(debug) cout<<"쿵 ";
            now->d =-1*now->d;//방향을 반대로 설정
        }
        int org = sea[now->pos.first][now->pos.second];
        if(org==-1){//이동한 자리에 아무 상어도 없으면
            sea[now->pos.first][now->pos.second] = i;
            if(debug) cout<<"moved "<<endl;
        }

        else{
            if(sharks[org].z<now->z){
                sharks.erase(sharks.begin()+org);
                sea[now->pos.first][now->pos.second] = i;
                if(debug) cout<<"eating "<<endl;
            }
            else{
                if(debug) cout<<"eaten "<<endl;
                sharks.erase(sharks.begin()+i);
            }
            i--;
        }
    }

}

int main(){
    cin>>r>>c>>m;
    int r_,c_,s,d,z;
    for(int i=0;i<m;i++){//상어 입력
        cin>>r_>>c_>>s>>d>>z;
        sharks.push_back(Shark(r_,c_,s,d,z));
    }
    int ans = 0;
    for(int i=1;i<=c;i++){//낚시왕 오른쪽으로 이동
        if(sharks.size()==0) break;
        ans += fishing(i,true);//상어 있으면 상어 잡기
        sharkMove(true);//상어들 이동
    }
    cout<<ans;

    return 0;
}