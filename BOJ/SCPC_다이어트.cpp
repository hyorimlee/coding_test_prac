/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int Answer;
const long long MAX = 200000;

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

		Answer = 0;
		int n,k;
		cin>>n>>k;
        vector<long long> Amenu(n),Bmenu(n);
        //long long Amenu[MAX],Bmenu[MAX];
		for(int i=0;i<n;i++){
		    cin>>Amenu[i];
		}
		for(int i=0;i<n;i++){
		    cin>>Bmenu[i];
		}
        sort(Amenu.begin(),Amenu.end());
        Amenu.erase(Amenu.begin()+n,Amenu.end());
        sort(Bmenu.begin(),Bmenu.end());
        Bmenu.erase(Bmenu.begin()+n,Bmenu.end());

        vector<long long> sum(k);
        for(int i=0;i<k;i++){
            sum[i] = Amenu[i]+Bmenu[k-i-1];
        }
        long long sol = sum[0];
        for(int i=1;i<k;i++){
            sol = max(sol,sum[i]);
        }
        Answer = sol;
        
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}