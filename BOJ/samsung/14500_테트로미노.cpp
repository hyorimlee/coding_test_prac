#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;
int n,m,ans=0;
//두칸씩 그룹화 시킴
//한 그룹의 주변에 있는 6칸 중 2개를 고르는 모든 경우의 수 고려
pair<int,int> first_directions[6] = {{0,-1},{-1,0},{1,0},{0,2},{1,1},{-1,1}};
pair<int,int> second_directions[] = {{1,0},{-1,0},{0,-1},{0,0},{0,1}};
pair<int,int> operator+ (const pair<int,int> &x, const pair<int,int> &y){
    return make_pair(x.first+y.first,x.second+y.second);
}
void ansChk(int newAns){
    if(ans<newAns){
        ans = newAns;
    }
}
bool isPossible(const int &i, const pair<int,int> &now, pair<int,int> &nxt,bool debug = false){
    nxt = now+first_directions[i];
    
    if(nxt.first<n&&nxt.first>=0&&nxt.second<m&&nxt.second>=0){
        //cout<<"["<<i<<","<<nxt.first<<","<<nxt.second<<"]";
        return true;
    }
    return false;
}
bool isPossibleToo(const int &i, const pair<int,int> &now,pair<int,int> &nxt){
    nxt = now +second_directions[i];
    if(nxt.first<n&&nxt.first>=0&&nxt.second<m&&nxt.second>=0){
        //cout<<"("<<nxt.first<<","<<nxt.second<<")";
        return true;
    }
    return false;
}
void doCombi(const vvi &paper,const pair<int,int> &now, int point){
    //cout<<endl<<now.first<<","<<now.second<<" : ";
    vector<bool> temp(m,true);
    vector<vector<bool>> visitable(n,temp);
    visitable[now.first][now.second] = false;
    visitable[now.first][now.second+1] = false;
    for(int i=0;i<6;i++){
        pair<int,int> a,b;
        if(isPossible(i,now,a)){
            if(i%3){
                if(isPossibleToo(i%2,a,b))ansChk(point+paper[a.first][a.second]+paper[b.first][b.second]);
                if(i%2==0){
                    if(isPossibleToo(i,a,b))ansChk(point+paper[a.first][a.second]+paper[b.first][b.second]);
                }
            }
            for(int j=i+1;j<6;j++){
                if(isPossible(j,now,b)){
                    if(ans<point+paper[a.first][a.second]+paper[b.first][b.second]){
                        ans = point+paper[a.first][a.second]+paper[b.first][b.second];
                        //cout<<i<<","<<j<<" "<<point+paper[a.first][a.second]+paper[b.first][b.second]<<endl;
                    }
                }
            }
        }
        
    }
}
void findAnswer(const vvi &paper){
    pair<int,int> temp;
    for(int i=0;i<n;i++){
        temp.first = i;
        for(int j=0;j<m-1;j++){
            temp.second = j;
            doCombi(paper,temp,paper[i][j]+paper[i][j+1]);//가로 두개
        }
    }
    //cout<<"ANS : "<<ans<<endl;
    int point = 0;
    //세로로 긴 친구들 검사용
    for(int i=3;i<n;i++){
        for(int j=0;j<m;j++){
            temp.first = i;
            temp.second = j;
            //cout<<temp.first<<" "<<temp.second<<" ";
            point = paper[temp.first][temp.second];
            //cout<<"point : "<<point;
            for(int k=0;k<3;k++){
                //cout<<"enter";
                temp = temp + first_directions[1];
                point += paper[temp.first][temp.second];
                //cout<<", "<< point;
            }
            //cout<<endl;
            if(ans<point){
                ans = point;
            }
        }
        
    }
}
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    vector<int> temp(m);
    vvi paper(n,temp);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>paper[i][j];
        }
    }
    findAnswer(paper);
    cout<<ans;
    return 0;
}