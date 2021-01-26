#include <iostream>
#include <vector>
using namespace std;
vector<bool> bo(6,false);
int ans = 0;
class board{
    public:
    vector<int> idx;
    vector<int> cnt;
    vector<vector<bool>> block;
    int stuck;
    bool blue;
    board(bool blue_){
        blue = blue_;
        vector<int> idx_(4,5);
        idx = idx_;
        vector<int> cnt_(6,0);
        cnt = cnt_;
        vector<vector<bool>> block_(6,bo);
        block = block_;
        stuck = -1;
    }
    void show(){
        int r=4,l=6;
        if(!blue){
            r = 6;
            l = 4;
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<l;j++){
                if(block[i][j]) cout<<1<<" ";
                else cout<<0<<" ";
            }
            cout<<endl;
        }
    }
};

void updateIdx(board &b){
    for(int i=0;i<4;i++){
        bool change = false;
        for(int j = 0;j<6;j++){
            if(b.blue==false&&b.block[j][i]==1){
                change = true;
                b.idx[i] = j-1;
                break;
            }
            else if(b.blue&&b.block[i][j]==1){
                change = true;
                b.idx[i] = j-1;
                break;
            }
        }
        if(change == false) {
            b.idx[i] = 5;
        }
    }
}

void oneBlock(const int &i, const int &j, board &blue, board &green){
    if(blue.stuck >-1){
        blue.block[i][blue.stuck] = true;
        blue.idx[i] = blue.stuck;
        //cout<<"blue "<<i<<"is stucked at "<<blue.stuck<<endl;
    }
    else{
        blue.block[i][blue.idx[i]] = true;
        blue.stuck = blue.idx[i];
        //cout<<"*************** "<<i<< " "<<blue.idx[i]<<endl;
    }
    blue.cnt[blue.idx[i]]++;
    blue.idx[i]--;
    
    if(green.stuck >-1){
        green.block[green.stuck][j] = true;
        green.idx[j] = green.stuck;
        //cout<<"green "<<j<<"is stucked at "<<blue.stuck<<endl;
    }
    else{
        green.block[green.idx[j]][j] = true;
        green.stuck = green.idx[j];
    }
    green.cnt[green.idx[j]]++;
    green.idx[j]--;
}

void newFriend(const int &t, const int &i, const int &j, board &blue,board &green){
    if(t==1) oneBlock(i,j,blue,green);
    if(t==2) {
        if(green.idx[j]<green.idx[j+1]){
            oneBlock(i,j,blue,green);
            blue.stuck = -1;
            oneBlock(i,j+1,blue,green);
        }
        else{//0,0
            oneBlock(i,j+1,blue,green);
            
            
            blue.stuck = -1;
            oneBlock(i,j,blue,green);
        }  
    }
    else if(t==3) {
        if(blue.idx[i]<blue.idx[i+1]){
            oneBlock(i,j,blue,green);
            green.stuck = -1;
            oneBlock(i+1,j,blue,green);
        }
        else{
            oneBlock(i+1,j,blue,green);
            green.stuck = -1;
            oneBlock(i,j,blue,green);
        }
    }
    blue.stuck = -1;
    green.stuck = -1;
}

void bingo(board &b, int idx){
    bool blue = b.blue;
    for(int i=0;i<4;i++){
        if(blue) b.block[i][idx] = false;
        else b.block[idx][i] = false;
    }
    for(int i=idx;i>1;i--){
        b.cnt[i] = b.cnt[i-1];
    }
    

}

void move(board &b,int IDX){   
    for(int i=IDX;i>0;i--){
        for(int j=0;j<4;j++){
            if(b.blue) b.block[j][i] = b.block[j][i-1];
            else b.block[i][j] = b.block[i-1][j];
        }
    }    
}

bool IsthereBingo(board &b){
    bool a = false;
    for(int i=5;i>1;i--){
        if(b.cnt[i]==4){
            bingo(b,i);
            move(b,i);
            
            i++;
            ans++;
            a = true;
        }
    }/*
    if(b.blue) {
        cout<<"---- ";
        for(int i=0;i<4;i++){
            cout<<b.idx[i]<<" ";
        }
        cout<<endl;
    }*/
    
    updateIdx(b);
    return a;
}

void IsOnSpecialSpace(board &b){
    for(int i=0;i<4;i++){
        while(b.idx[i]<1){
            bingo(b,5);
            move(b,5);
            updateIdx(b);        
        }
    }
}

int main(){
    board green(false);
    board blue(true);

    int n;
    
    cin>>n;
    for(int i=0;i<n;i++){
        int t,x,y;
        cin>>t>>x>>y;
        newFriend(t,x,y,blue, green);
        IsthereBingo(blue);
        IsthereBingo(green);
        IsOnSpecialSpace(blue);
        IsOnSpecialSpace(green);   
    }
    cout<<ans<<endl;
    int kan = 0;
    for(int i=2;i<6;i++){
        for(int j=0;j<4;j++){
            kan+=blue.block[j][i];
            kan+=green.block[i][j];
        }
    }
    cout<<kan;
    return 0;
}