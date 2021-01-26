#include <iostream>
#include <vector>
using namespace std;

int n,k;
int bagdp(int c,int idx,const vector<int> &w,const vector<int> &v,vector<vector<int>> &value){
    int temp1,temp2;
    //cout<<"In "<<c<<","<<idx<<endl;
    if(c<=0) return 0;
    if(idx==n) return 0;
    int &ret=value[c][idx];
    if(ret!=-1) return ret;
    ret =bagdp(c,idx+1,w,v,value);
    if(c>=w[idx]){
        ret = max(ret,bagdp(c-w[idx],idx+1,w,v,value)+v[idx]);
    }
    return ret;
    
}

int main(){
    cin>>n>>k;
    vector<int> w(n),v(n);
    for(int i=0;i<n;i++){
        cin>>w[i]>>v[i];
    }
    vector<int> sub(n+1,-1);
    vector<vector<int>> value(k+1,sub);


    cout<<bagdp(k,0,w,v,value);
    return 0;
}