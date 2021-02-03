//21.02.03

#include <iostream>
#include <list>
#include <string>
using namespace std;
int main(){
    list<char> editor;
    string temp;
    cin>>temp;
    for(int i=0;i<temp.size();i++){
        editor.push_back(temp[i]);
    }
    int test;
    cin>>test;
    char oper, what;
    list<char>::iterator iter = editor.end();
    while(test--){
        cin>>oper;
        if(oper=='P'){
            cin>>what;
            editor.insert(iter,what);
        }
        else if(oper=='L'){
            if(iter!=editor.begin()) iter--;
        }
        else if(oper=='D'){
            if(iter!=editor.end()) iter++;
        }
        else if(oper=='B'){
            if(iter==editor.begin()) continue;
            iter--;
            cout<<"erase "<<*iter<<endl;
            iter = editor.erase(iter);
        }

    }
    for(iter = editor.begin();iter!=editor.end();iter++){
        cout<<*iter;
    }
    return 0;
}