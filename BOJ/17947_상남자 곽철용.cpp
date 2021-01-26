#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,m,k,a,b;
    cin>>n>>m>>k;
    vector<int> remains(k,(4*n)/k);
    vector<bool> points(k,false);
    for(int i=0;i<(4*n)%k;i++){
        remains[i]++;
    }
    for(int i=0;i<m+1;i++){
        cin>>a>>b;
        remains[a%k]--;
        remains[b%k]--;
    }
    int dragon = abs(a%k-b%k);
    int point,l;
    if(dragon == k-1) cout<<0;
    else{
        int count = 0;
        for(l=dragon+1;l<k;l++){
            for(int i=0;i<k;i++){
                if(remains[i]>0&&remains[l-i]>0){
                    count++; 
                    break;                   
                }
            }
        }
        cout<<count;
    }
    return 0;
}
