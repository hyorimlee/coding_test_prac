#include <iostream>
#include <vector>
using namespace std;
int n,m,ans=1400,c,h;
vector<int> temp(ans,-1);
vector<vector<int>> dis(ans,temp);
vector<pair<int,int>> house,chicken;
int calChicken(const vector<bool> &chk){
    int val=0;
    for(int j=0;j<h;j++){
        int min = 1400;
        for(int i=0;i<c;i++){
            if(chk[i]==true){
                if(dis[i][j]==-1){
                    dis[i][j] = abs(chicken[i].first - house[j].first)+abs(chicken[i].second-house[j].second);
                }
                if(min>dis[i][j]) min = dis[i][j];
            }
        }
        //cout<<j<<" min : "<<min<<endl;
        val+=min;
    }
    //cout<<"val : "<<val<<endl;
    return val;
}

void selectM(int i,int cnt, vector<bool> &chk){
    cnt++;
    //cout<<"cnt "<<cnt<<"---------------------------"<<endl;
    for(;i<c;i++){
        if(chk[i]==false){
            chk[i]=true;
            if(cnt<m){
                selectM(i+1,cnt,chk);
            }
            else{
                int chick_dis = calChicken(chk);
                if(chick_dis<ans) ans = chick_dis;
            } 
        }
        chk[i]=false;
    }
    cnt--;
}
void findBest(const vector<vector<int>> &town){
    int cnt=0;
    vector<bool> chk(c,false);
    selectM(0,0,chk);
}
int main(){
    cin>>n>>m;
    vector<int> tem(n);
   
    vector<vector<int>> town(n,tem);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>town[i][j];
            if(town[i][j]==1){
                house.push_back(make_pair(i,j));
            }
            else if(town[i][j]==2){
                chicken.push_back(make_pair(i,j));
            }
        }
    }
    c = chicken.size();
    h = house.size();
    int i,j;
    findBest(town);
    cout<<ans;
    return 0;
}