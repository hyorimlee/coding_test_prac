#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef pair<int,int> p;

int dis(p a,p b){
    int sol = (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
    sol = sqrt(sol);
}
int main(){
    int t,distance;
    cin>>t;
    p a,b;
    int r,w;
    for(int test=0;test<t;test++){
        cin>>a.first>>a.second>>r;
        cin>>b.first>>b.second>>w;
        distance = dis(a,b);
        int rplus = r+w,rminus = abs(r-w);
        if(distance == 0&&r==w)   cout<<-1<<endl;
        else if(rplus<distance||rminus>distance) cout<<0<<endl;
        else if(rplus==distance||rminus==distance) cout<<1<<endl;
        else cout<<2<<endl;   

        
    }
    return 0;
}