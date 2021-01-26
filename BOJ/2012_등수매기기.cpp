#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,j;
    cin>>n;
    vector<int> winner(n+1);
    for(int i=1;i<n+1;i++){
        cin>>j;
        winner[i]=j;
    }
    sort(winner.begin(),winner.end());
    long long ans=0;
    for(int i=1;i<n+1;i++){
        ans+=abs(winner[i]-i);
    }
    cout<<ans;
    return 0;
}