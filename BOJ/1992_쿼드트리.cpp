#include <iostream>
#include <vector>
using namespace std;
void check(const vector<vector<char>> &map,int a, int b, int n){
    if(n==1) {
        cout<<map[a][b];
        return;
    }
    bool chk = true;
    char stnd = map[a][b];
    for(int i=a;i<a+n;i++){
        for(int j=b;j<b+n;j++){
            if(map[i][j]!=stnd){
                chk = false;
                break;
            }
        }
    }
    if(chk==false){
        cout<<"(";
        check(map,a,b,n/2);
        check(map,a,b+n/2,n/2);
        check(map,a+n/2,b,n/2);
        check(map,a+n/2,b+n/2,n/2);
        cout<<")";
    }
    else cout<<stnd;
}
int main(){
    int n;
    cin>>n;
    vector<char> tp(n);
    vector<vector<char>> map(n,tp);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    cout<<"---------------------------"<<endl;
    /*for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<map[i][j];
        }
        cout<<endl;
    }*/
    check(map,0,0,n);
    return 0;
}