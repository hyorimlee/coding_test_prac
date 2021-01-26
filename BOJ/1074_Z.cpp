#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int cnt = 0;
pair<int,int> operator + (pair<int,int> &first, pair<int,int> &second){
    int x = first.first + second.first;
    int y = first.second + second.second;
    return make_pair(x,y);
}
pair<int,int> operator - (pair<int,int> &first, pair<int,int> &second){
    int x = first.first - second.first;
    int y = first.second - second.second;
    return make_pair(x,y);
}
bool operator == (pair<int,int> &first, pair<int,int> &second){
    if(first.first == second.first){
        if(first.second==second.second){
            return true;
        }
    }
    return false;
}
int CalFirstSpot(pair<int,int> &ans){
    int plus = 0;
    if(ans.first %2 == 1){
        plus +=1;
        ans.first-=1;
    }
    if(ans.second %2 == 1){
        plus +=2;
        ans.second-=1;
    }
    return plus;
}

void CalCnt(const pair<int,int> &ans,pair<int,int> &start,int n){
    if(ans == start) {
        cout<<cnt;
        return;
    }
    if(n/2 == 1){
        cnt+=4;
        return;
    }
    pair<int,int> add = make_pair(n/2,0),temp;
    CalCnt(ans,start,n/2);
    temp = start+add;
    CalCnt(ans,temp,n/2);
    add.first =0;
    add.second = n/2;
    temp = start +add;
    CalCnt(ans,temp,n/2);
    add.first = n/2;
    temp = start + add;
    CalCnt(ans,temp,n/2);
}
int main() {
    int n,r,c;
    cin>>n>>c>>r;
    n = pow(2,n);
    pair<int,int> ans = make_pair(r,c),start = make_pair(0,0);
    cnt+= CalFirstSpot(ans);
    CalCnt(ans,start,n);  
    
}