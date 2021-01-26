#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> p;

int ccs(p a, p b, p c){
    return a.first*b.second+b.first*c.second+c.first*a.second - (b.first*a.second+c.first*b.second+a.first*c.second);
}
int main(){

    p sub;
    vector<p> points(3,sub);
    for(int i=0;i<3;i++){
        cin>>points[i].first>>points[i].second;
    }
    int sol = ccs(points[0],points[1],points[2]);
    if(sol!=0){
        sol /=abs(sol);
    } 
    cout<<sol;
    return 0;
}
