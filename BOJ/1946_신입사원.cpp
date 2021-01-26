#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int t,n,a,b;
    cin>>t;
    for(int test=0;test<t;test++){
        cin>>n;
        vector<pair<int,int>> fresh(n);
        for(int i=0;i<n;i++){
            cin>>a>>b;
            fresh[i]=make_pair(a,b);
        }
        sort(fresh.begin(),fresh.end());
        for(int i=0;i<fresh.size();i++){
            cout<<fresh[i].first<<" ";
        }
        cout<<endl;
        int count = n;
        for(int i=1;i<n;i++){
            if(fresh[i].first>fresh[0].first){
                if(fresh[i].second>fresh[0].second){
                    cout<<"MINUS AT "<<fresh[i].first<<endl;
                    count--;
                }
            }
        }
        cout<<count<<"\n";
    }

    return 0;
}