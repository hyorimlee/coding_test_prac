#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,m,testcase;

void findAns(queue<pair<int,int>> q,vector<int> prio,int cnt){
    pair<int,int> now = q.front();
    bool notYet=false;
    q.pop();
    for(int i=9;i>now.second;i--){
        if(prio[i]>0){//가장 높지 않은 경우
            q.push(now);
            notYet=true;
            break;            
        }
    }
    if(!notYet){//가장 높으므로 pop할 것이다.
        if(now.first == m){
            cout<<cnt<<endl;
            return;
        } 
        prio[now.second]--;
        findAns(q,prio,cnt+1);       
    }
    else findAns(q,prio,cnt);
}
int main(){
    cin>>testcase;
    int temp;
    for(int i=0;i<testcase;i++){
        cin>>n>>m;
        queue<pair<int,int>> q;
        vector<int> prio(10,0);
        for(int j=0;j<n;j++){
            cin>>temp;
            q.emplace(j,temp);
            prio[temp]++;
        }
        findAns(q,prio,1);
       

    }
    return 0;
}