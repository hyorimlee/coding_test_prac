/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
const int MAX = 3002;
int win,lose,n,k;
int xcard[MAX],ycard[MAX],cache[MAX][MAX];
int Answer;

void fill_win(int i,int j){
    //select dummy X
    int su=0;
    for(int q=i+1;q<=n;q++){
        su+=xcard[q];
        if(su>k) break;
        cache[q][j]=1;
    }
    //select dummy Y
    su=0;
    for(int w=j+1;w<=n;w++){
        su+=ycard[w];
        if(su>k) break;
        cache[i][w]=1;
    }
}
int find_XY(int i,int j){
    if(cache[i][j]==1) return 1;
    lose++;
    cache[i][j]=0;
    fill_win(i,j);

    return 0;
}
void init_things(int n){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cache[i][j]=-1;
        }
    }
    cache[0][0]=1;
    lose = 0;
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
        
        cin>>n>>k;
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
        init_things(n);
		for(int i=1;i<=n;i++){
            cin>>xcard[i];
        }
        for(int i=1;i<=n;i++){
            cin>>ycard[i];
        }


        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                find_XY(i,j);
            }
        }
        win=(n+1)*(n+1)-lose;
        /*cout<<"--------------------"<<endl;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                cout<<cache[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"--------------------"<<endl;*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		//cout << Answer << endl;
        cout<< win<<" "<<lose<<endl;
	}

	return 0;//Your program should return 0 on normal termination.
}