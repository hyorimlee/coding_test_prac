#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,temp;
    cin>>n;
    temp = n;
    int coins=0,ans=1000000;
    pair<int,int> hurry;
    hurry=make_pair(temp/5,(temp%5)/2);
    if((temp%5)%2==0) {
        ans = hurry.first+hurry.second; 
        cout<<ans;
        return 0;
    }
    for(;hurry.first>=0;hurry.first--){
        temp = n;
        temp-=hurry.first*5;
        if(temp%2==0){
            hurry.second = temp/2;
            coins = hurry.first+hurry.second;
            if(coins<ans) ans = coins;
        }
    }
    if(ans==1000000) cout<<"-1";
    else cout<<ans;
    return 0;
}