#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    //ios::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin>>t;
    for(int testcase=0;testcase<t;testcase++){
        int j,n,r,c,count=0,box;
        cin>>j>>n;
        vector<int> boxes(n);
        for(int i=0;i<n;i++){
            cin>>r>>c;
            box = r*c;
            boxes[i]=box;
        }
        sort(boxes.begin(),boxes.end());
        reverse(boxes.begin(),boxes.end());        
        for(int i=0;i<boxes.size()&&j>0;i++,count++){
            j-=boxes[i];
        }
        cout<<count<<"\n";
    }
    return 0;
}