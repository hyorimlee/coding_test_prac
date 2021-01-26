#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> vvi;
vvi idymatrix(int n){
    vector<int> tp(n,0);
    vvi matrix(n,tp);
    for(int i=0;i<n;i++){
        matrix[i][i] = 1;
    }
    return matrix;
}
vvi product(const vvi &a, const vvi &b){
    vector<int> tp(a.size(),0);
    vvi matrix(a.size(),tp);
    if(a.size()!=b.size()) cout<<"SOMETHING WRONG";
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a.size();j++){
            for(int k=0;k<a.size();k++){
                matrix[i][j] += a[i][k]*b[k][j];
            }
            matrix[i][j]%=1000;
        }
    }
    return matrix;
}
vvi pow(const vvi &matrix,long long b){
    if(b==0) return idymatrix(matrix.size());
    if(b%2==1) return product(pow(matrix,b-1),matrix);
    vector<int> tp(matrix.size());
    vvi halfmatrix(matrix.size(),tp);
    halfmatrix = pow(matrix, b/2);
    return product(halfmatrix,halfmatrix);
}
void printM(const vvi &matrix){
    int n=matrix.size();
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
}
int main(){
    long long n,b;
    cin>>n>>b;
    vector<int> tp(n);
    vvi matrix(n,tp),ans(n,tp);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
            matrix[i][j]%=1000;
        }
    }
    ans = pow(matrix, b);
    printM(ans);
    return 0;
}