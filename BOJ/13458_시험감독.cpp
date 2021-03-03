#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    int n,b,c;
    cin>>n;
    vector<int> test(n);
    for(int i=0;i<n;i++){
        cin>>test[i];
    }
    long long ans = n;
    cin>>b>>c;
    for(int i=0;i<n;i++){
        test[i]-=b;
        if(test[i]>0){
            if(test[i]%c==0)
                ans += test[i]/c;
            else
            {
                ans+= test[i]/c+1;
            }
            
        }
    }
    cout<<ans;
    return 0;
}