//greedy
//https://programmers.co.kr/learn/courses/30/lessons/42884
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool funcforsort(vector<int> &x, vector<int> &y){
    if(x[0]==y[0]) return x[1]<y[1];
    return x[0]<y[0];
}
bool secinc(vector<int> &x, vector<int> &y){
    return x[1]<y[1];
}
int solution(vector<vector<int>> routes) {
    int answer = 0;
    //30000
    int min=60000, max=0;
    sort(routes.begin(),routes.end(),secinc);
    vector<bool> meet(routes.size(), false);
    vector<int> camera;
    bool overlap = false;
    for(int i=0;i<routes.size();i++){
        overlap = false;
        for(int j=0;j<camera.size();j++){
            if(camera[j]<=routes[i][1]&&camera[j]>=routes[i][0]){
                overlap = true;
                break;
            }
        }
        if(overlap) continue;
        camera.push_back(routes[i][1]);
    }
    answer=camera.size();
    return answer;
}