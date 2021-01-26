#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>>  vvi;
typedef vector<int> vi;

int check(const vvi &paper,int x, int y,vi &ans){
    vi cnt(4,0);
    int st = paper[x][y];
    bool same = true;
    if(st==2) same ==false;
    for(int i=x;i<x+3;i++){
        for(int j=y;j<y+3;j++){
            cnt[paper[i][j]+1]++;
            if(same){
                if(st!=paper[i][j]) same = false;
            }
        }
    }
    if(same)
        return st;
    for(int i=0;i<3;i++){
        ans[i]+=cnt[i];
    }
    return 2;
}
vi threeDiv(const vvi &paper,vi &ans,int n){
    if(n==1) return ans;
    vector<int> t(n/3);
    vvi chk(n/3,t);
    for(int i=0;i<n/3;i++){
        for(int j=0;j<n/3;j++){
            chk[i][j] = check(paper,i*3,j*3,ans);
        }
    }
    
    return threeDiv(chk,ans,n/3);
}
int main(){
    int n;
    cin>>n;
    vector<int> t(n);
    vvi paper(n,t);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>paper[i][j];
        }
    }
    vector<int> ans(4,0);
    if(n==1){
        ans[paper[0][0]+1]++;
    }
    else{

        threeDiv(paper,ans,n);
    }
    cout<<ans[0]<<endl<<ans[1]<<endl<<ans[2];
    return 0;
}