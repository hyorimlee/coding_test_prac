#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> p;

int main(){
    p sub;
    int t,n;
    cin>>t;
    vector<int> groups;
    for(int test=0;test<t;test++){
        cin>>n;
        vector<p> where(n,sub);
        vector<int> r(n);
        for(int i=0;i<n;i++){
            cin>>where[i].first>>where[i].second>>r[i];
        }
    }


    return 0;
}