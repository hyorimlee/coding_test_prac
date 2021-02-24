#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
typedef vector<vector<int>> vvi;
int n,ans = 0;
void showNxt(const vvi &nxt){
    cout<<"-----------------------"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<nxt[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"-----------------------"<<endl;
}
bool tiltUp(const vvi &board,vvi &nxt){
    //cout<<"Up";
    bool changed = false;
    vector<bool> t(n,true);
    vector<vector<bool>> chk(n,t);
    int idx=0;
    for(int y=0;y<n;y++){
        bool first = true;
        idx = 0;
        for(int x=0;x<n;x++){
            if(board[x][y]>0){
                int point = board[x][y];
                if(first){
                    first = false;
                    nxt[idx++][y] = point;
                    if(!changed&&idx-1!=x) changed = true;
                }
                else{
                    if(point==nxt[idx-1][y]&&chk[idx-1][y]){
                        chk[idx-1][y] = false;
                        nxt[idx-1][y]*=2;
                        if(!changed) changed = true;
                        if(ans<nxt[idx-1][y]) ans = nxt[idx-1][y];
                    }
                    else{
                        nxt[idx++][y] = point;
                        if(!changed&&idx-1!=x) changed = true;
                    }
                }
            }
        }
        while(idx<n-1){
            nxt[idx++][y]=0;
        }
    }
    changed = true;
    return changed;
}

bool tiltDown(const vvi &board,vvi &nxt){
    //cout<<" Down";
    bool changed = false;
    vector<bool> t(n,true);
    vector<vector<bool>> chk(n,t);
    int idx=n-1;
    for(int y=0;y<n;y++){
        bool first = true;
        idx = n-1;
        for(int x=n-1;x>=0;x--){
            if(board[x][y]>0){
                int point = board[x][y];
                if(first){
                    first = false;
                    nxt[idx--][y] = point;
                    if(!changed&&idx+1!=x) changed = true;
                }
                else{
                    if(point==nxt[idx+1][y]&&chk[idx+1][y]){
                        chk[idx+1][y] = false;
                        nxt[idx+1][y]*=2;
                        if(!changed) changed = true;
                        if(ans<nxt[idx+1][y])ans = nxt[idx+1][y];
                    }
                    else  {
                        nxt[idx--][y] = point;
                        if(!changed&&idx+1!=x) changed = true;
                    }
                    
                }
            }
        }
        while(idx>0) nxt[idx--][y]=0;
    }
    changed = true;
    return changed;
}
bool tiltLeft(const vvi &board,vvi &nxt){
    //cout<<" Left";
    bool changed = false;
    vector<bool> t(n,true);
    vector<vector<bool>> chk(n,t);
    int idx=0;
    for(int x=0;x<n;x++){
        bool first = true;
        idx = 0;
        for(int y=0;y<n;y++){
            if(board[x][y]>0){
                int point = board[x][y];
                if(first){
                    first = false;
                    nxt[x][idx++] = point;
                    if(!changed&&idx-1!=y) changed = true;
                }
                else{
                    if(point==nxt[x][idx-1]&&chk[x][idx-1]){
                        chk[x][idx-1] = false;
                        nxt[x][idx-1]*=2;
                        if(!changed) changed = true;
                        if(ans<nxt[x][idx-1]) ans = nxt[x][idx-1];
                    }
                    else{
                        nxt[x][idx++] = point;
                        if(!changed&&idx-1!=y) changed = true;
                    }
                }
            }
        }
        while(idx<n-1){
            nxt[x][idx++]=0;
        }
    }
    changed = true;
    return changed;
}
bool tiltRight(const vvi &board,vvi &nxt){
    //cout<<" Right";
    bool changed = false;
    vector<bool> t(n,true);
    vector<vector<bool>> chk(n,t);
    int idx=n-1;
    for(int x=0;x<n;x++){
        bool first = true;
        idx = n-1;
        for(int y=n-1;y>=0;y--){
            if(board[x][y]>0){
                int point = board[x][y];
                if(first){
                    first = false;
                    nxt[x][idx--] = point;
                    if(!changed&&idx+1!=y) changed = true;
                }
                else{
                    if(point==nxt[x][idx-1]&&chk[x][idx-1]){
                        chk[x][idx-1] = false;
                        nxt[x][idx-1]*=2;
                        if(!changed) changed = true;
                        if(ans<nxt[x][idx-1]) ans = nxt[x][idx-1];
                    }
                    else  {
                        nxt[x][idx--] = point;
                        if(!changed&&idx+1!=y) changed = true;
                    }
                }
            }
        }
        while(idx>0) nxt[x][idx--]=0;
    }
    changed = true;
    return changed;
}
void initNxt(vvi &nxt){
    //cout<<"inti"<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            nxt[i][j] = 0;
        }
    }
}
void tiltAll(int num,const vector<vector<int>> &board){
    if(num>1) return;
    vector<int> t(n);
    vector<vector<int>> nxt(n,t);
    if(tiltUp(board, nxt)) tiltAll(num+1,nxt);
    showNxt(nxt);
    initNxt(nxt);
    if(tiltDown(board,nxt)) tiltAll(num+1,nxt);
    showNxt(nxt);
    initNxt(nxt);
    if(tiltLeft(board,nxt)) tiltAll(num+1,nxt);
    showNxt(nxt);
    initNxt(nxt);
    if(tiltRight(board,nxt)) tiltAll(num+1,nxt);
    showNxt(nxt);
    //cout<<num<<" : "<<ans<<endl;
}

int main(){
    cin>>n;
    vector<int> t(n);
    vector<vector<int>> board(n,t);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
            if(board[i][j]>ans) ans = board[i][j];
        }
    }

    tiltAll(1,board);
    cout<<ans;  

    return 0;
}