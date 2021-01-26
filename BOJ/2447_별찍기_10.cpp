#include <iostream>
#include <vector>
using namespace std;
void draw(int i,int j, int n){
    if(i%3==1 && j%3==1) {
        cout<<" ";
        return;
    }
    if(n==1){
        cout<<"*";
        return;
    }
    draw(i/3,j/3,n/3);
    return;
}
int main(){
    int n;
    cin>>n;
    //vector<char> tp(n,' ');
    //vector<vector<char>> stars(n,tp);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            draw(i,j,n);
        }
        cout<<endl;
    }
    return 0;
}