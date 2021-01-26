#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);
    int n,m;
    long long ans=0,temp=0,weight=0,candy;
    int i,j;
    vector<long long> five;
    vector<long long> three;
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>candy;
        if(candy==3){
            cin>>candy;
            three.push_back(candy);
        }
        else{
            cin>>candy;
            five.push_back(candy);
        }
    }
    if(three.size()>0) sort(three.begin(),three.end());
    if(five.size()>0) sort(five.begin(),five.end());
    stack<long long> FiveQ;
    if(five.size()==0){
        for(i=0;i<three.size()&&weight<m-2;i++){
            weight+=three[three.size()-1-i];
        }
        cout<<weight;
        return 0;
    }
    ans=0;weight=0;
    for(i=0;weight+4<m;i++){
        ans += five[five.size()-1-i];
        weight += 5;
        FiveQ.push(five[five.size()-1-i]);
        if(five.size()-1-i == 0) break;
    }
    int top;
    if(three.size()==0){
        cout<<ans;
        return 0;
    }
    
    int threeIdx=three.size()-1;
    for(;weight+2<m&&threeIdx>=0;threeIdx--){

        ans+=three[threeIdx];
        weight+=3;
    }   

    temp = ans;
    for(i=0;FiveQ.size()>0;i++){
        top = FiveQ.top();
        FiveQ.pop();
        weight -= 5;
        temp -= top;

        for(;weight+2<m&&threeIdx>=0;threeIdx--){
            temp+=three[threeIdx];
            weight +=3;
        }
        if(ans<temp) ans = temp;
    }
    cout<<ans;
    return 0;
}