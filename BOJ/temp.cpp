#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
pii operator+ (const pii &x, const pii &y){
    return make_pair(x.first+y.first, x.second+y.second);
}
pii operator* (const pii &x, long long &y){
    return make_pair(x.first*y,x.second*y);
}
int n,k;
vector<pii> where;
//vector<int> table[52][52];
class fire{
    public:
    bool alive;
    long long m,s;
    int d;
    fire(long long m_,long long s_, int d_){
        m = m_;
        s = s_;
        d = d_;
        alive = true;        
    }
};
vector<fire> fires;
pii dTodir(int d){
    if (d==0) return make_pair(-1,0);
    if (d==1) return make_pair(-1,1);
    if (d==2) return make_pair(0,1);
    if (d==3) return make_pair(1,1);
    if (d==4) return make_pair(1,0);
    if (d==5) return make_pair(1,-1);
    if (d==6) return make_pair(0,-1);
    return make_pair(-1,-1);
}
void fireMove(pll (&dup)[52][52],vector<int> (&table)[52][52]){
    for(int i=0;i<fires.size();i++){
        if(fires[i].alive){
            where[i] = where[i]+dTodir(fires[i].d)*fires[i].s;
            where[i].first=((where[i].first%n)+n)%n;
            where[i].second=((where[i].second%n)+n)%n;
            
            table[where[i].first][where[i].second].push_back(i);
            int dup_m = fires[i].m;
            int dup_s = fires[i].s;
            
            pll *now = &dup[where[i].first][where[i].second];
            if(table[where[i].first][where[i].second].size()==1){
                if(fires[i].d%2 == 1) dup_s *= -1;//¹æÇâÀÌ È¦¼ö¸é À½¼ö·Î µÎ°í
                now->first = dup_m;
                now->second = dup_s;
            }
            else{
                fires[i].alive = false;
                if(now->first>=0){//Áú·®ÀÌ ¾ç¼ö == ¹æÇâÀÇ Â¦È¦ÀÌ µ¿ÀÏÇÏ¸é
                    if(fires[i].d%2 == 1) dup_s *= -1;//¹æÇâÀÌ È¦¼ö¸é À½¼ö·Î µÎ°í
                    if(now->second*dup_s >= 0){//¼Ó·Â °öÀÌ Â¦¼ö : Â¦È¦ µ¿ÀÏ
                        now->second+=dup_s;
                        now->first+=dup_m;
                    }
                    else{//Â¦È¦ÀÌ ´Þ¶ó
                        dup_s = fires[i].s;
                        now->first *= -1;//Áú·®À» - :: Â¦È¦ ´Ù¸£´Ù°í Ç¥½Ã
                        now->first -= dup_m;
                        if(now->second<0) now->second*=-1;
                        now->second += dup_s;
                    }
                }
                else{
                    now->first -= dup_m;
                    now->second += dup_s;
                }
            }
        }
    }
}
void dup_show(pll (&dup)[52][52]){
    cout<<"***********dup*********"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"["<<dup[i][j].first<<","<<dup[i][j].second<<"]";
        }
        cout<<endl;
    }
    cout<<endl;
}

void table_show(vector<int> (&table)[52][52]){
    cout<<"--------------------------"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"[";
            for(int o=0;o<table[i][j].size();o++){
                cout<<table[i][j][o]<<",";
            }
            cout<<"] ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void Move(bool debug = false){
    pll dup[52][52];
    vector<int> table[52][52];
    fireMove(dup,table);
    if(debug) table_show(table);
    if(debug) dup_show(dup);
    long long m_,s_;
    int d_;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(table[i][j].size()>1){
                fires[table[i][j][0]].alive = false;
                m_ = dup[i][j].first/5;
                if(m_==0) continue;
                s_ = dup[i][j].second/table[i][j].size();
                if(m_<0){
                    for(int dir=1;dir<8;dir+=2){
                        fire a(-m_,s_,dir);
                        where.emplace_back(i,j);
                        fires.push_back(a);
                    }
                }
                else{
                    for(int dir=0;dir<7;dir+=2){
                        if(s_<0) s_ *=-1;
                        fire a(m_,s_,dir);
                        where.emplace_back(i,j);
                        fires.push_back(a);
                    }
                }
                
                

            }
        }
    }
}


int main(){
    int f;
    cin>>n>>f>>k;
    int x,y,d;
    long long m,s;
    for(int i=0;i<f;i++){
        cin>>x>>y>>m>>s>>d;
        where.emplace_back(x-1,y-1);
        fire a(m,s,d);
        fires.push_back(a);
    }
    for(int i=0;i<k;i++){
        Move();
    }
    long long ans = 0;
    for(int i=0;i<fires.size();i++){
        if(fires[i].alive){
            ans += fires[i].m;
        }
    }
    cout<<ans;
    return 0;
}