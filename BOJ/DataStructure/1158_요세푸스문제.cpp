#include <iostream>
#include <queue>
using namespace std;

int main(){
    int k,n;
    cin>>n>>k;
    queue<int> yo[2];
    for(int i=0;i<n;i++){
        yo[0].push(i+1);
    }
    cout<<"<";
    int from=0,to=1;
    while(yo[0].size()+yo[1].size()>1){
        int cnt = 0,temp;
        for(cnt = 1;cnt<k;cnt++){
            yo[to].push(yo[from].front()); 
            yo[from].pop();
            if(yo[from].size()==0){
                from = to;
                to = (to+1)%2;
            }
        }
        cout<<yo[from].front()<<", ";
        yo[from].pop();
        if(yo[from].size()==0){
            from = to;
            to = (to+1)%2;
        }
    }
    cout<<yo[from].front()<<">";


    return 0;
}