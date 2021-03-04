#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<char> st;
int main(){
    string s;
    getline(cin,s);
    bool q = false;
    for(int i=0;i<s.size();i++){
        if(s[i]=='>'){
            q = false;
            cout<<">";
        }
        else if(q){
            cout<<s[i];
        }
        else if(s[i]=='<') {
            while(st.size()>0){
                cout<<st.top();
                st.pop();
            }
            q = true;
            cout<<"<";
        }
        else if(s[i] == ' ') {
            while(st.size()>0){
                cout<<st.top();
                st.pop();
            }
            cout<<" ";

        }
        else {
            st.push(s[i]);
        }
    }
    while(st.size()>0){
        cout<<st.top();
        st.pop();
    }
    return 0;
}