/*
NAJPWG - Playing with GCD
no tags 

Tanmoy recently learn about euclid gcd algorithm.

This algorithm looks like:

gcd(a,b):

   if(b==0):return a

   return gcd(b,a%b)

Now he want to find out how many pair (x,y) can be possible in range N, which gcd is greater than 1. Here pair (x,y) and (y,x) consider as same pair. 1<=x,y<=N.

He can find out it small number easily but for a large number its realy hard to find out. Now he needs your help. Write a programme that find out number of such pair.

Input: 

Input start with an integer number T(<=10^5), which is number of test cases.

Each test case contain a integer N (1<=N<=10^5).

Output:

For each case, Print case Number and Desired answer
*/
#include <stdio.h>
int phi[100004];
void fill(){
	int i=0;
	for(;i<100005;i++)phi[i]=i;
	for(i=2;i<100005;i++){
		if(phi[i]==i){
			int j=i;
			for(;j<100005;j+=i)phi[j]=(phi[j]/i)*(i-1);
		}
	}
	for(i=1;i<100005;i++){
		phi[i]=(i-phi[i])+phi[i-1];
	}
	}
 
int main() {
	int t;
	scanf("%d",&t);
	fill();
	int i=0;
	while(t--){
		int n;
		i++;
		scanf("%d",&n);
		printf("Case %d: %d\n",i,phi[n]);
	}
}