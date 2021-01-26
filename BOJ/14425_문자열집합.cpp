#include <iostream>
#include <cstring>
using namespace std;
const int ALPHABETS = 26;

int toNumber(char ch) { return ch - 'a';}

class TrieNode {
    public:
    TrieNode * children[ALPHABETS];
    
    bool terminal;

    TrieNode() : terminal(false){
        memset(children,0,sizeof(children));
    }
    ~TrieNode() {
        for(int i=0;i<ALPHABETS;++i)
            if(children[i])
                delete children[i];
    }

    void insert(const char * key){
        //문자열이 끝나면
        if(*key=='\0')
            terminal = true;
        else{
            int next = toNumber(*key);
            if(children[next] == NULL)
                children[next] = new TrieNode();
            children[next]->insert(key+1);
        }
    }

    bool find(const char* key){
        if(*key == '\0') {return terminal;}
        int next = toNumber(*key);
        if(children[next]==NULL) return false;
        return children[next]->find(key+1);
    }
};

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    TrieNode trienode;
    char pr[501];
    for(int i=0;i<n;i++){
        cin>>pr;
        trienode.insert(pr);
    }
    int answer=0;
    for(int i=0;i<m;i++){
        char pr[501];
        cin>>pr;
        if(trienode.find(pr))
            answer++;
    }
    cout<<answer;
    
    return 0;
}