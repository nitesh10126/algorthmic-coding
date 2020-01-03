/*
TDKPRIME - Finding the Kth Prime
no tags 

The problem statement is really simple. There are some queries. You are to give the answers.
Input

An integer stating the number of queries Q(equal to 50000), and Q lines follow, each containing one integer K between 1 and 5000000 inclusive.
Output

Q lines with the answer of each query: the Kth prime number. 
*/
#include <stdio.h>
#define MAX 100000000
#define LIM 10000
typedef unsigned long long ull;


unsigned flag[MAX>>6]={0};
unsigned res[MAX];

#define ifc(n) (flag[n>>6]&(1<<((n>>1)&31)))         //LINE 1
#define isc(n) (flag[n>>6]|=(1<<((n>>1)&31)))        //LINE 2

void sieve() {
    unsigned i, j, k;
    for(i=3; i<LIM; i+=2)
        if(!ifc(i))
            for(j=i*i, k=i<<1; j<LIM*LIM; j+=k)
                isc(j);
}

int main(){
	sieve();
	unsigned i,j,k=1;
	for(i=0;i<=MAX>>6;i++){
		for(j=0;j<32;j++)
		if(!(flag[i]&(1<<j)))res[k++]=(i<<6)+(j<<1)+1;
	}
	int t;
    scanf("%d",&t);
    while(t--){
    	ull n;
    	scanf("%llu",&n);
    	if(1==n)printf("2\n");
		else printf("%d\n",res[n]);	
    }
	return 0;
}