#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;
typedef vector<pair<int,int>> vp;

int l,r,n,ans=0;;
void chkBound(int i, int j, vvb &chk, vvi &country,vp &gro ){
    chk[i][j] = true;
    int bound[4][2] = {{i-1,j},{i,j+1},{i+1,j},{i,j-1}};
    int stand = country[i][j];
    for(int i=0;i<4;i++){
        if((bound[i][0]<n)&&(bound[i][1]<n)&&(bound[i][0]>=0&&(bound[i][1]>=0))){
            if(chk[bound[i][0]][bound[i][1]]==true) continue;
            int diff = abs(stand-country[bound[i][0]][bound[i][1]]);
            if(l<=diff&&diff<=r){
                //gro.push_back(make_pair(bound[i][0],bound[i][1]));
                gro.emplace_back(bound[i][0],bound[i][1]);
                chkBound(bound[i][0],bound[i][1],chk,country,gro);
            }            
        }
    }
}
void doMove(vvi &country,vector<vp> &change){
    ans++;
    for(int i=0;i<change.size();i++){
        vp t = change[i];
        int cnt = 0;
        for(int j=0;j<t.size();j++){
            cnt+=country[t[j].first][t[j].second];
        }
        int nxt = (int)cnt/t.size();
        for(int j=0;j<t.size();j++){
            country[t[j].first][t[j].second]=nxt;
        }
    }
}
int main(){
    int temp;
    cin>>n>>l>>r;
    vector<vector<int>> country(n);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>temp;
            country[i].push_back(temp);
        }
    }
    bool exit = false;
    while(exit == false){
        vector<vp> change;
        vector<bool> t(n,false);
        vector<vector<bool>> chk(n,t);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(chk[i][j]==false){
                    vp gro;
                    chk[i][j] = true;
                    gro.emplace_back(i,j);

                    chkBound(i,j,chk,country,gro);

                    if(gro.size()>1){
                        change.push_back(gro);
                    }
                }                
            }
        }
        if(change.size()==0) exit = true;
        else{
            doMove(country,change);
        }
    }
    cout<<ans;
    return 0;
}