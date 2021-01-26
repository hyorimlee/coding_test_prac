#include <iostream>
#include <vector>
using namespace std;
class kan{
    public:
    int nxt;
    int nxt_b;
    bool color;//true == blue
    int point;
    bool fin;
    vector<int> mal;

    kan(int nxt_, int point_){
        nxt = nxt_;
        nxt_b = nxt;
        color = false;
        point = point_;
        
    }
    
};
vector<kan> pan;
vector<int> inp(10);
void initPan(){
    for(int i=0;i<=20;i++){
        kan a(i+1,i*2); 
        pan.push_back(a);
    }
    
    for(int i=0;i<12;i++){
        kan a(22+i,i);
        pan.push_back(a);
    }
    pan[5].color = true;
    pan[5].nxt_b = 21;
    pan[21].point = 13;
    pan[22].point = 16;
    pan[23].point = 19;
    pan[23].nxt = 29;

    pan[24].point = 22;
    pan[25].point = 24;
    pan[25].nxt = 29;

    pan[26].point = 28;
    pan[27].point = 27;
    pan[28].point = 26;
    pan[28].nxt = 29;

    pan[29].point = 25;
    pan[30].point = 30;
    pan[31].point = 35;
    pan[31].nxt = 20;

    pan[20].fin = true;

    pan[10].color = true;
    pan[10].nxt_b = 24;
    pan[15].color = true;
    pan[15].nxt_b = 26;
    pan[20].nxt = 32;
    pan[32].point = 0;
    pan[32].nxt = 32;

}

void permu_rep(int n,int k,vector<vector<int>> &group,vector<int> &box){
    //k = 10, n=4
    bool full = false;
    if(box.size()==k-1) full = true;

    for(int i=0;i<n;i++){
        box.push_back(i);
        if(full) group.push_back(box);
        else(permu_rep(n,k,group,box));
        box.pop_back(); 
    }
}

void move(int how, int &ans,bool &blue,vector<int> &mal,int idx){
    int nxt;
    int now = mal[idx];
    
    if(pan[now].color) blue = true;
    for(int j=0;j<how;j++){
        if(blue){
            nxt = pan[now].nxt_b;
            blue = false;
        }
        else{nxt = pan[now].nxt;}
        now = nxt;
    }
    for(int i=0;i<4;i++){
        if(i!=idx&&mal[i]==now&&now!=32){
            ans = -1;
            return;
        }
    }
    mal[idx] = now;
    ans+=pan[now].point;
}

int game(vector<int> group){
    vector<int> mal(4, 0);
    int ans = 0;
    int cnt = 0;
    int nxt, now = 0;
    bool blue = false;

    for(int i=0;i<10;i++){
        move(inp[i],ans, blue, mal,group[i]);
        if (ans==-1) break;
    }
    return ans;
}
int main(){
    initPan();
    vector<int> box;
    vector<vector<int>> group;
    permu_rep(4,10,group,box);


    for(int i=0;i<10;i++){
        cin>>inp[i];
    }

    int ans = 0,temp;
    for(int i=0;i<group.size();i++){
        temp = game(group[i]);
        if(temp>ans) {
            ans = temp;
        }
    }
    
    
    cout<<ans;
    return 0;
}