#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<char> gear_sub(8);
    vector<vector<char>> gear(4,gear_sub);
    for(int i=0;i<4;i++){
        for(int j=0;j<8;j++){
            cin>>gear[i][j];
        }
        
    }
    //[0][2]<->[1][6],[1][2]<->[2][6],[2][2]<->[3][6]
    vector<pair<int,int>> check(3,{2,6});
    vector<int> isMove(4,0);
    int k,score=0;
    cin>>k;
    
    for(int test=0;test<k;test++){
        int g,d;
        cin>>g>>d;
        g--;

        isMove[g]=d;
        for(int left=g-1;left>=0;left--){
            if(isMove[left+1]!=0&&gear[left][check[left].first]!=gear[left+1][check[left].second]){
                isMove[left]=-isMove[left+1];
                
            }
            else{
                isMove[left]=0;
            }
        }
        for(int right=g+1;right<4;right++){
            //cout<<"right :"<<right<<endl;
            if(isMove[right-1]!=0&&gear[right-1][check[right-1].first]!=gear[right][check[right-1].second]){
                isMove[right]=-isMove[right-1];
            }
            else{
                isMove[right]=0;
            }
        }

    
        for(int i=0;i<4;i++){
            if(isMove[i]==0) continue;
            if(i>0){
                check[i-1].second=(check[i-1].second-isMove[i]+8)%8;
                
            }
            if(i<3){
                check[i].first=(check[i].first-isMove[i]+8)%8;
            }
        }
    }
    
    int one,two,three,four;
    one = (check[0].first+6)%8;
    two = (check[1].first+6)%8;
    three = (check[2].first+6)%8;
    four = (check[2].second+2)%8;
    if(gear[0][one]=='1') score = 1;
    if(gear[1][two]=='1') score += 2;
    if(gear[2][three]=='1') score+= 4;
    if(gear[3][four]=='1') score+= 8;
    cout<<score;
    /*

    cout<<"-------------------------"<<endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<8;j++){
            cout<<gear[i][j]<<" ";
        }
        cout<<endl;
        
    }
*/
    return 0;
}