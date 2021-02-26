

#include <iostream>
using namespace std;
const int MAX = 100;
int cache[MAX]={0,};
int Answer;

int what_in_cache(int n){
    if(cache[n]>0) return cache[n];
    if(n%2==0) {
        cache[n] = what_in_cache(n/2)+1;
    }
    else {
        cache[n] = what_in_cache(n+1)+1;
    }
    return cache[n];
}

int cal_sum(int n,int m){
    int sol = 0;
    for(int i=n;i<=m;i++){
        sol+=what_in_cache(i);
    }
    return sol;
}

int main()
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
		/////////////////////////////////////////////////////////////////////////////////////////////
		int n,m;
		cin>>n>>m;
		Answer = cal_sum(n,m);
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}