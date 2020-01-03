/*
EDIST - Edit distance
#dynamic-programming

 
You are given two strings, A and B. Answer, what is the smallest number of operations you need to transform A to B.
Operations are:
 1) Delete one letter from one of strings
 2) Insert one letter into one of strings
 3) Replace one of letters from one of strings with another letter 
Input
T - number of test cases
For each test case:
 String A
 String B
Both strings will contain only lowercase characters and they won't
be longer than 2000 characters. 
Output
For each test case, one line, minimum number of operations.
Example
Input:
1
FOOD
MONEY 
Output:
4

You are given two strings, A and B. Answer, what is the smallest number of operations you need to
transform A to B?

Operations are:

 1) Delete one letter from one of strings
 2) Insert one letter into one of strings
 3) Replace one of letters from one of strings with another letter 

Input

T - number of test cases

For each test case:

 String A
 String B

Both strings will contain only uppercase characters and they won't
be longer than 2000 characters. 

There will be 10 test cases in data set.

Output

For each test case, one line, minimum number of operations.
*/

#include <stdio.h>
#include <string.h>
char A[2001],B[2001];
int dp[2001][2001];

int getMin(int a,int b,int c){
	if(a>b){
		return b<c?b:c;
	}
	else
	{
		return a<c?a:c;
	}
}

int main(){
int t;
scanf("%d",&t);
while(t--){
	scanf("%s",A);
	scanf("%s",B);
	int A_length = strlen(A);
	int B_length = strlen(B);
	int i,j;
	for(i=0;i<=A_length;i++){
		dp[i][0]=i;
	}
	for(i=0;i<=B_length;i++){
		dp[0][i]=i;
	}
	for(i=1;i<=A_length;i++){
		for(j=1;j<=B_length;j++){
			int dist=1;
			if(A[i-1]==B[j-1])dist=0;
			dp[i][j]=getMin(1+dp[i][j-1],1+dp[i-1][j],dist+dp[i-1][j-1]);
		}
	}
	printf("%d\n",dp[A_length][B_length]);
}
}