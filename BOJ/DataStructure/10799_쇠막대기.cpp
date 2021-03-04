#include <iostream>
#include <string>
using namespace std;
int main(){
    int ans = 0, cnt = 0;
    string str;
    cin>>str;
    bool raz = false;
    for(int i = 0;i<str.size();i++){
        if(str[i]=='('){
            cnt++;
            raz = true;
        }
        else if(str[i]==')'){
            cnt--;
            if(raz){
                raz = false;
                ans +=cnt;
            }
            else {
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}