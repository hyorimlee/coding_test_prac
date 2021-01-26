#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> vvi;

int n,m,k;

void spring(){

}
void summer(){

}
void fall(){

}
void winter(){

}

int main(){
    vector<int> t(n);
    vvi A(n,t),te(n);
    vector<vvi> tree(n,te);
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>A[i][j];
        }
    }
    int x,y,z;
    for(int i=0;i<m;i++){
        cin>>x>>y>>z;
        tree[x][y].push_back(z);
    }
    for(int i=0;i<k;i++){
        spring();
        summer();
        fall();
        winter();
    }
    return 0;
}