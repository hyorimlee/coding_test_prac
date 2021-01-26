#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(),phone_book.end());
    for(int i=0;i<phone_book.size()-1;i++){
        bool same = true;
        for(int j=0;j<phone_book[i].size();j++){
            if(phone_book[i][j]!=phone_book[i+1][j]){
                same = false;
                break;
            }
        }
        if(same) {
            answer = true;
            break;
        }
    }
    answer = false;
    return answer;
}
int main(){
    vector<string> da= {"123", "456", "789"};
    cout<<solution(da);
    return 0;
}