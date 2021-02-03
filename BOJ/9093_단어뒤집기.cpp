//단어뒤집기
//21.02.03
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
    int test;
    cin>>test;
    cin.ignore();//버퍼 지우기
    for(int i=0;i<test;i++){
        string str;
        getline(cin,str);
        str+=' ';
        stack<char> stk;
        for(int i=0;i<str.size();i++){
            if(str[i]==' '){
                while(stk.size()>0){
                    cout<<stk.top();
                    stk.pop();
                }
                cout<<" ";
            }
            else stk.push(str[i]);
        }
        cout<<endl;
    }
    return 0;
}