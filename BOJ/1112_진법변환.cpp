#include <iostream>
#include <vector>
using namespace std;
vector<int> ans,x_v;
int chang_m(int x, int b,bool minus,int size){
    if(size==0){
        return x;
    }
    if((size%2!=0&&x>0)||(size%2==0&&x<0)){
        ans.push_back(x_v[0]+1);
    }
    else{
        ans.push_back(1);
        size++;
    }


}

int main(){
    int x,b;
    vector<int> ans;
    cin>>x>>b;
    bool minus  = false;
    
    return 0;
}