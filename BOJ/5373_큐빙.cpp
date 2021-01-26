#include <iostream>
#include <vector>
using namespace std;
class Cube{
    public:
    Cube()
        vector<char> u(3,'w'),r(3,'b'),l(3,'g'),f(3,'r'),d(3,'y'),b(3,'o');
        vector<vector<char>> U(3,u),R(3,r),L(3,l),F(3,f),D(3,d),B(3,b);
}
//90도 돌려야함
void frontBack(bool front, char way){
    vector<int> w(4);
    if(front) w = {0,2,0,2};
    else w = {2,0,2,0};
    if((front&&way=='+')||(!front&&way=='-')){
        char temp = L[0][w[0]];
        for(int i=0;i<3;i++){
            L[i][w[0]] = D[w[3]][i];
        }
        for(int i=0;i<3;i++){
            D[w[3]][i] = R[i][w[2]];
        }
        for(int i=0;i<3;i++){
            R[i][w[2]] = U[w[1]][i];
        }
        for(int i=0;i<3;i++){
            U[w[1]][i] = temp;
        }        
    }
    else{
        char temp = L[0][w[0]];
        for(int i=0;i<3;i++){
            L[i][w[0]] = U[w[1]][i];
        }
        for(int i=0;i<3;i++){
            U[w[1]][i] = R[i][w[2]];
        }
        for(int i=0;i<3;i++){
            R[i][w[2]] = D[w[3]][i];
        }
        for(int i=0;i<3;i++){
            D[w[3]][i] = temp;
        } 
    }
}
void downUp(bool down, char way){
    int w;
    if (down) w = 2;
    else w =0;
    if((down&&way=='+')||(!down&&way=='-')){
        char temp = B[w][0];
        for(int i=0;i<3;i++){
            B[w][i] = R[w][i];
        }
        for(int i=0;i<3;i++){
            R[w][i] = F[w][i];
        }
        for(int i=0;i<3;i++){
            F[w][i] = L[i][w];
        }        
        for(int i=0;i<3;i++){
            L[w][i] = temp;
        }        
    }
    else{
        char temp = L[w][0];
        for(int i=0;i<3;i++){
            L[w][i] = F[i][w];
        }
        for(int i=0;i<3;i++){
            F[w][i] = R[w][i];
        }
        for(int i=0;i<3;i++){
            R[w][i] = B[w][i];
        }
        for(int i=0;i<3;i++){
            B[w][i] = temp;
        }  
    }
}
void leftRight(bool left, char way){
    int w;
    if(left) w = 0;
    else w = 2;
    if((left&&way=='+')||(!left&&way=='-')){
        char temp = B[0][w];
        for(int i=0;i<3;i++){
            B[i][w] = D[i][w];
        }
        for(int i=0;i<3;i++){
            D[i][w] = F[i][w];
        }
        for(int i=0;i<3;i++){
            F[i][w] = U[i][w];
        }        
        for(int i=0;i<3;i++){
            U[i][w] = temp;
        }        
    }
    else{
        char temp = U[0][w];
        for(int i=0;i<3;i++){
            U[i][w] = F[i][w];
        }
        for(int i=0;i<3;i++){
            F[i][w] = D[i][w];
        }
        for(int i=0;i<3;i++){
            D[i][w] = B[i][w];
        }
        for(int i=0;i<3;i++){
            B[i][w] = temp;
        }  
    }
}
int main(){
    int testcase,times;
    char which,how;
    cin>>testcase;
    for(int i=0;i<testcase;i++){
        cin>>times;
        for(int j=0;j<times;j++){
            cin>>which>>how;
            if(which=='L') leftRight(true,how);
            else if(which=='R') leftRight(false,how);
            else if(which=='D') downUp(true,how);
            else if(which=='U')downUp(false,how);
            else if(which=='F')frontBack(true,how);
            else if(which=='B')frontBack(false,how);
            else cout<<"Something wrong.."<<endl;
        }
        for(int k=0;k<3;k++){
            for(int l=0;l<3;l++){
                cout<<U[k][l];
            }
            cout<<endl;
        }
        cout<<"-------------------"<<endl;
    }
    return 0;
}