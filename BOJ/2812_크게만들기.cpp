#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){
    return (a.second < b.second);
}
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);
    int n,k,num;
    cin>>n>>k>>num;
    vector<pair<int,int>> sortedNumber(n);
    for(int i=1,idx=n-1;i<=n;i++,idx--){
        int temp = pow(10,i);
        sortedNumber[idx]=make_pair((num%temp)/(pow(10,i-1)),idx);
        num-=sortedNumber[idx].first;
    }
    /*
     for(int i=0;i<number.size();i++){
    }
    cout<<endl;
    */
    sort(sortedNumber.begin(),sortedNumber.end());
    sortedNumber.erase(sortedNumber.begin(),sortedNumber.begin()+k);

    sort(sortedNumber.begin(),sortedNumber.end(),sortbysec);
    reverse(sortedNumber.begin(),sortedNumber.end());
    int ans=0;
    for(int i=0;i<sortedNumber.size();i++){
        ans+=sortedNumber[i].first*(pow(10,i));
    }
    cout<<ans;
    /*for(int i=0;i<sortedNumber.size();i++){
        cout<<sortedNumber[i].first<<","<<sortedNumber[i].second<<" ";
    }*/


    return 0;
}