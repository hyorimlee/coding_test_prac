#include <iostream>
#include <list>
#include <string>
using namespace std;
class deque{
    public:
    list<int> dq;
    void push_front(int x){
        dq.push_front(x);
    }
    void push_back(int x){
        dq.push_back(x);
    }
    void pop_front(){
        if(dq.size()==0){
            cout<<"-1"<<endl;
            return;
        }
        cout<<dq.front()<<endl;
        dq.pop_front();
    }
    void pop_back(){
        if(dq.size()==0){
            cout<<"-1"<<endl;
            return;
        }
        cout<<dq.back()<<endl;
        dq.pop_back();
    }
    void size(){
        cout<<dq.size()<<endl;
    }
    void empty(){
        if(dq.size()==0) cout<<"1";
        else cout<<"0";
        cout<<endl;
    }
    void front(){
        if(dq.size() ==0){
            cout<<"-1"<<endl;
            return;
        }
        cout<<dq.front()<<endl;
    }
    void back(){
        if(dq.size()==0){
            cout<<"-1"<<endl;
            return;
        }
        cout<<dq.back()<<endl;
    }

};
int main(){
    string oper;
    int x,n;
    cin>>n;
    deque deq;
    for(int i=0;i<n;i++){
        cin>>oper;
        if(oper == "push_front"){
            cin>>x;
            deq.push_front(x);
        }
        else if(oper == "push_back"){
            cin>>x;
            deq.push_back(x);
        }
        else if(oper == "pop_front"){
            deq.pop_front();
        }
        else if(oper == "pop_back"){
            deq.pop_back();
        }
        else if(oper == "size"){
            deq.size();
        }
        else if(oper == "empty"){
            deq.empty();
        }
        else if(oper == "front"){
            deq.front();
        }
        else if(oper == "back"){
            deq.back();
        }
    }
    return 0;
}