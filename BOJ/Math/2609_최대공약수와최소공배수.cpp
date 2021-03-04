#include <iostream>
using namespace std;
int main(){
    int x,y;
    cin>>x>>y;
    int gcf= x*y;
    int lcm=1;
    for(;gcf>1;gcf--){
        if(x%gcf==0&&y%gcf==0) break;
    }
    cout<<gcf<<" ";
    for(;lcm<x*y;lcm++){
        if(lcm%x==0&&lcm%y==0) break;
    }
    cout<<lcm;
    return 0;
}