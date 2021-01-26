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
        s = s_%n;
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
bool isodd(int x){
    if(x%2==1) return true;
    return false;
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
                int dup_m=0,dup_s=0,odd=0;
                bool same=true;
                for(int idx : table[i][j]){
                    fires[idx].alive = false;
                    dup_m+=fires[idx].m;
                    dup_s+=fires[idx].s;
                    if(odd==0){
                        if(isodd(fires[idx].d)) odd = 1;
                        else odd = -1;
                    }
                    else{
                        if(same){
                            if(odd*isodd(fires[idx].d<0)) same = false;
                        }
                    }
                }
                dup_m/=5;
                if(dup_m==0) continue;
                dup_s/=table[i][j].size();
                int k=0;
                if(!same) k=1;
                for(;k<4;k+=2){
                    fire fire_t(dup_m,dup_s,k);
                    fires.push_back(fire_t);
                    where.emplace_back(i,j);
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