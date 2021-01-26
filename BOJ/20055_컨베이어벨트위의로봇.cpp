#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int up, down,b;
vector<int> durability,robot;
vector<bool> belt;
int robotMove(int n,int k,vector<int> &idx,bool debug = false){//idx:=위치 넣으면 로봇의 순서가 나옴
    int turn = 1;
    up = 0;
    down = n/2-1;
    int cnt = 0;
    for(;;turn++){
        //cout<<turn<<" ";
        //1. 벨트 회전
        up=(up+n-1)%n;
        down=(down+n-1)%n;
        if(debug){
            cout<<endl<<"****벨트돌아감******"<<turn<<endl<<"ROBOT"<<endl;
            for(int i=0;i<robot.size();i++){
                cout<<robot[i]<<", ";
            }
            cout<<endl;
            cout<<"dura"<<endl;
            for(int i=0;i<durability.size();i++){
                cout<<durability[i]<<" ";
            }
            cout<<endl;
            cout<<"down : "<<down<<" ";
            cout<<endl<<"idx"<<endl;
            for(int i=0;i<idx.size();i++){
                cout<<idx[i]<<" ";
            }
            cout<<endl;
        }

       //내려가는 위치에 로롯이 있으면 내려가
        
        if(idx[down]>-1){
            robot[idx[down]]=-1;
            if(durability[down]>0) belt[down] = true;
            idx[down] = -1;
        }
        //2. 로봇 이동
        if(debug) cout<<"로봇 이동 ";
        for(int i=0;i<robot.size();i++){
            if(robot[i]<0) continue; 
            if(belt[(robot[i]+1)%n]){//이동가능하면
                //원래자리 내구도 확인하고 올라갈 수 있는 지 체크해둠
                if(durability[robot[i]]>0) belt[robot[i]] = true;
                idx[robot[i]] = -1;//이전 위치 삭제
                robot[i]=(robot[i]+1)%n;//새위치                
                durability[robot[i]]--;//내구도 하락
                if(durability[robot[i]]==0) cnt++;//내구도 0 여부 확인
                if(debug)cout<<robot[i]<<"의 내구도 하락->"<<durability[robot[i]]<<" ";
                if(cnt>=k) return turn;//종료 여부 확인
                if(robot[i]==down){//내려가야하는 위치라면
                    robot[i]=-1;//로봇내려감
                    if(durability[down]>0) belt[down] = true;
                    //idx[robot[i]] = -1;//위치 삭제
                }
                else {
                    belt[robot[i]] = false;//  
                    idx[robot[i]] = i;//새 위치 업데이트      
                }
            }
        }

        //3. 로봇 올리기
        if(belt[up]){//올라가는 위치에 내구도가 괜찮으면
            if(debug)cout<<up<<"에 로봇 올리기"<<endl;
            belt[up] = false;
            robot.push_back(up);
            idx[up] = robot.size()-1;
            durability[up]--;
            if(durability[up]==0) cnt++;
        }
        //4. 종료여부 확인
        if(cnt>=k) return turn;
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    int n,k,a;
    cin>>n>>k;
    vector<int> idx;
    for(int i=0;i<2*n;i++){
        cin>>a;
        durability.push_back(a);
        belt.push_back(true);
        idx.push_back(-1);
    }
    
    int ans = robotMove(2*n,k,idx);
    cout<<ans;
    return 0;
}