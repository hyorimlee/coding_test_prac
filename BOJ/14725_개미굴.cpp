#include <iostream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
const int num = 10;

class Trie {
    Trie * children[num];
    bool terminal;

    Trie() : terminal(flase){
        memset(children,0,sizeof(children));
    }
    ~Trie() {
        for(int i=0;i<num;i++){
            if(children[i])
                delete children[i];
        }
    }

    void insert(int key){
        if(children[key]==NULL)
    }
}

int main(){
    int num,n;
    cin>>num;
    string str;
    while(num--){
        cin>>n;
        while(n--){
            cin>>str;
            insert_trie();
        }
    }
    return 0;
}