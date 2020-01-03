#include <stdio.h>
int power(int,int);

int main(){
	int a,n;
	scanf("%d%d",&a,&n);
	int res=power(a,n);
	printf("\n%d",res);
	return 0;
	}
	
int power(int a,int n){
	if(n==1)return a;
	int m = n/2;
	int i = n%2;
	int res1 = power(a,m);
	if(i==0) return res1*res1;
	return a*res1*res1;
	}
	
// Problem : calculate a^n.
// Design Approach : Divide & Conquer - recursive
