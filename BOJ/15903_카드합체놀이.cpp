#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    long long n,m;
    cin>>n>>m;
    long long a;
    vector<long long> cards(n);
    for(int i=0;i<n;i++){
        cin>>cards[i];
    }
    for(int i=0;i<m;i++){
        sort(cards.begin(),cards.end());
        a = cards[0]+cards[1];
        cards[0]=a;
        cards[1]=a;
    }
    long long ans = 0;
    for(int i=0;i<n;i++){
        ans+=cards[i];
    }
    cout<<ans;

    return 0;
}