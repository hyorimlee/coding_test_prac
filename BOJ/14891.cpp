#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<char> gear_sub(8);
    vector<vector<char>> gear(4,gear_sub);
    for(int i=0;i<4;i++){
        for(int j=0;j<8;j++){
            cin>>gear[i][j];
        }
        
    }
    //[0][2]<->[1][6],[1][2]<->[2][6],[2][2]<->[3][6]
    vector<pair<int,int>> check(3,{2,6});
    int k,score=0;
    int g,d;
    cin>>k;
    for(int test=0;test<k;test++){
        cin>>g>>d;
        --g;
            //g-1(>=0)과 g, g와 g+1(<=3)의 관계 확인 후 회전
        if(g-1>=0 && gear[g-1][check[g-1].first]!=gear[g][check[g-1].second]){
            //g-1회전
            check[g-1].first = (check[g-1].first+d+8)%8;
            if(g-2>=0){
                check[g-2].second = (check[g-2].second+d+8)%8;
            }
        }
       
        if(g+1<4 && gear[g][check[g].first]!=gear[g+1][check[g].second]){
            //g+1회전
            check[g].second = (check[g].second+d+8)%8;
            check[g+1].first = (check[g+1].first+d+8)%8;
        }
        //g회전
        if(g>=1)
            check[g-1].second=(check[g-1].second-d+8)%8;
        check[g].first = (check[g].first-d+8)%8;
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