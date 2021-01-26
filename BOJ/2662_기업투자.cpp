#include <iostream>
#include <vector>
using namespace std;
const int Max = 310;
int n,m;
int i=0;
vector<long long> sub_n(Max,-1),where(Max);
vector<vector<long long>> cache(Max,sub_n),value(Max,sub_n);
int findBest(int cap,int idx){
    if(cap<=0) return 0;
    if(idx>m) return 0;
    if(idx==m) return value[cap][m];
    long long &ret = cache[cap][idx];
    if(ret!=-1) return ret;
    ret = findBest(cap,idx+1);
    for(int i=1;i<cap+1;i++){
        ret = max(ret,value[i][idx]+findBest(cap-i,idx+1));
    }
    return ret;
}
int findWhere(int cap,int idx){
    if( idx > m) return 0;
    if(idx == m) {
        where[idx]=cap;
        return 0;
    }
    for(int i=0;i<cap+1;i++){
        if(findBest(cap,idx)==findBest(cap-i,idx+1)+value[i][idx]){
            where[idx]=i;
            findWhere(cap-i,idx+1);
            break;
        }
    }
    return 0;
}
int main(){
    cin>>n>>m;
    int temp; 
      
    for(int i=1;i<=n;i++){
        cin>>temp;
        for(int j=0;j<m;j++){
            cin>>value[temp][j+1];
        }
    }
    for(int i=0;i<m+1;i++){
        value[0][i]=0;
    }
    cout<<findBest(n,0)<<endl;
    findWhere(n,0);
    if(m==1) cout<<n;
    else{
        for(int i=1;i<m+1;i++){
            cout<<where[i]<<" ";
        }
    }
    return 0;
}