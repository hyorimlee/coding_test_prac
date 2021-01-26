#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
vector<pii> virus;
vector<vector<int>> lab;
vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
pii operator+ (const pii &x, const pii &y){
    return make_pair(x.first+y.first,x.second+y.second);
}
const int ans_init = 30000;
int ans = ans_init;
int n,m,wall=0;
void initlab(vector<vector<int>> &test_lab){
    for(int i=0;i<virus.size();i++){
        test_lab[virus[i].first][virus[i].second] = 0;
    }
}
void pushNXT(list<pii> &q,const pii &now,vector<vector<int>> &test_chk){
    for(int i=0;i<dir.size();i++){
        pii nxt = now+dir[i];
        if(nxt.first>=0&&nxt.first<n&&nxt.second>=0&&nxt.second<n){//if under lab
            if(test_chk[nxt.first][nxt.second]==-1){//if not duplicated
                q.emplace_back(now+dir[i]);//will spread
                test_chk[nxt.first][nxt.second] = 0;
            }
        }
    }
}
int spreadVirus(int org,const list<pii> &selected,bool debug){
    if(debug) cout<<"spreading virus"<<endl;
    vector<int> t(n,-1);
    vector<vector<int>> test(n,t),test_chk(n,t);
    initlab(test);

    list<pii> q = selected;
    for(pii t :q){
        pushNXT(q,make_pair(0,0),test_chk);
    }
    int tim = 0,cnt =virus.size();
    for(;q.size()>0;tim++){
        if(tim>ans) return tim;
        int s = q.size();
        if(debug) cout<<endl<<"q.size = "<<s<<" ";
        for(int idx=0;idx<s;idx++){
            pii now = q.front();
            if(debug) cout<<"("<<now.first<<","<<now.second<<") ";
            if(lab[now.first][now.second]==0){
                if(test[now.first][now.second] == -1){//was not spread
                    if(debug) cout<<"!";
                    test[now.first][now.second] = tim;//spread
                    cnt++;//increase virus cnt
                    pushNXT(q,now,test_chk);
                }
            }
            q.pop_front(); 
        }       
    }
    if(debug){
        pii m = selected.front();
        cout<<endl<<tim<<" ----------------------"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==m.first**j==m.second)
                if(test[i][j] == -1) cout<<"- ";
                cout<<test[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"CNT : "<<cnt<<endl;
        cout<<"************************"<<endl;
    }
    if(cnt == n*n-wall) return tim;
    return -1;
}
void selectVirus(list<pii> &selected,vector<bool> &chk,int i,bool debug = false){
    for(;i<virus.size();i++){
        if(chk[i] == false){
            if(debug) cout<<i;
            chk[i] = true;
            selected.push_back(virus[i]);

            if(selected.size() == m){
                if(debug) cout<<"virus selected"<<endl;
                int tim = spreadVirus(ans,selected,debug);
                if(tim>-1&& tim<ans) ans = tim;
            }

            else{
                selectVirus(selected,chk,i+1,debug);
            }

            chk[i] = false;
            selected.pop_back();

        }
    }
}

int findMin(bool debug = false){
    list<pii> selected;
    vector<bool> chk(virus.size(),false);
    selectVirus(selected,chk,0,debug);
    if(debug) cout<<endl;
    return 0;

}

int main(){
    cin>>n>>m;
    vector<int> temp(n);
    for(int i=0;i<n;i++){ 
        for(int j=0;j<n;j++){
            cin>>temp[j];
            if(temp[j]==2) virus.emplace_back(i,j);
            if(temp[j]==1) wall++;
        }
        lab.push_back(temp);
    }
    findMin(true);
    if(ans==ans_init) cout<<-1;
    else cout<<ans;
    return 0;
}