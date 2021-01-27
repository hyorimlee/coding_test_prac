#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
void fun(long long &answer,long long left, long long right, const long long &n, const vector<int> &times){
    vector<long long> idx(times.size());
    answer=left+(right-left+1)/2;
    long long cnt =0;
    for(int i=0;i<idx.size();i++){
        idx[i] = answer/times[i];
        cnt+=idx[i];
    }
    if(cnt==n){
        long long real = 0;
        for(long long i=0;i<times.size();i++){
            if(real<=idx[i]*times[i]){
            real = idx[i]*times[i];
            }
        }
        
        answer = real;
        return;
    }
    else if(right-left ==1){
        return;
    }
    if(cnt<n){
        fun(answer, answer,right, n,times);
    }
    else fun(answer, left, answer, n,times);
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(),times.end());
    fun(answer,0,times[0]*n,n,times);
    return answer;
}