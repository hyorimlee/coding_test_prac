/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>
using namespace std;
const int MAX = 302;
int sadari[MAX][MAX], min_erase[MAX][MAX];
int n,k,m,cnt;
bool ALL_FILLED=false;
int Answer;
void init_things(){
    int lim=max(n,k);
    for(int i=0;i<lim;i++){
        for(int j=0;j<lim;j++){
            sadari[i][j]=-1;
            min_erase[i][j]=-1;
        }
    }
    cnt=0;
    ALL_FILLED=false;
}

int find_Goal(int line,int start){
    int idx;
    for(idx=line;idx<k;idx++){
        if(sadari[idx][start]>-1){
            //cout<<"LET'S GO TO "<<sadari[idx][start]<<endl;
            return find_Goal(idx+1,sadari[idx][start]);
        }
    }
    return start;
}
void fill_Goal(int how){
    int temp;
    for(int i=0;i<n;i++){
        temp = find_Goal(0,i);
        if(min_erase[i][temp]==-1){
            min_erase[i][temp]=how;
            cnt++;
            if(cnt==n*n) {
                ALL_FILLED=true;
                return;
            }
        }
    }
}
void DoThisTimes(int temp_sadari[MAX][MAX],int times,int now,int last,const vector<pair<int,int>> &tngs){
    if(now==last) return;
    if(ALL_FILLED==true) return;
    

    
    for(int i=now-1;i<n;i++){
        sadari[i][tngs[i].first]=-1;
        sadari[i][tngs[i].second]=-1;
        fill_Goal(now);
        DoThisUntil(now+1,last,tngs);
        sadari[i][tngs[i].first]=tngs[i].second;
        sadari[i][tngs[i].second]=tngs[i].first;
    }
}
int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        cin>>n>>k>>m;
        int s,g;
		Answer = 0;
        pair<int,int> te;
        vector<pair<int,int>> tngs(k,te);
		/////////////////////////////////////////////////////////////////////////////////////////////
		init_things();
        for(int i=0;i<k;i++){
            cin>>s>>g;
            s--;
            g--;
            sadari[i][s]=g;
            sadari[i][g]=s;
            tngs[i].first=s;
            tngs[i].second=g;
        }
        int temp;
        fill_Goal(0);
        DoThisUntil(1,k,tngs);
        /*cout<<"----------------"<<endl;
        for(int i=0;i<n;i++){
            cout<<"FIND GOAL FROM "<<i<<endl;
            cout<<find_Goal(0,i)<<endl;
        }*/
    

		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		//cout << Answer << endl;
        for(int i=0;i<m;i++){
            cin>>s>>g;
            s--;
            g--;
            cout<<min_erase[s][g]<<endl;
        }
        cout<<endl;
	}

	return 0;//Your program should return 0 on normal termination.
}