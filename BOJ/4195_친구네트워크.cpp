#include <iostream>
#include <vector>
using namespace std;
class disjointset{
    public:
        vector<int> parent,rank;
        vector<string> whoami;
        void push(int n){
            parent.push_back(n);
            parent[parent.end()] = n;
            rank.push_back(n);
            rank[rank.end()] = n;
        }

}
int main(){
    return 0;
}