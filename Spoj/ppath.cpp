/*
PRIME1 - Prime Generator
#number-theory

Peter wants to generate some prime numbers for his cryptosystem. Help him! Your task is to generate all prime numbers between two given numbers!
Input

The input begins with the number t of test cases in a single line (t<=10). In each of the next t lines there are two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000) separated by a space.
Output

For every test case print all prime numbers p such that m <= p <= n, one number per line, test cases separated by an empty line.
*/

#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
#define MAX 32000
#define LIM 180
typedef unsigned long long ull;


unsigned flag[MAX>>6]={0};
unsigned res[MAX],k=0;

#define ifc(n) (flag[n>>6]&(1<<((n>>1)&31)))         //LINE 1
#define isc(n) (flag[n>>6]|=(1<<((n>>1)&31)))        //LINE 2

void sieve() {
    unsigned i, j, k;
    for(i=3; i<LIM; i+=2)
        if(!ifc(i))
            for(j=i*i, k=i<<1; j<LIM*LIM; j+=k)
                isc(j);
}

inline bool process(unsigned long x) 
{ 
    unsigned int i, last = sqrt(x); 
    for (i = 1; i < k && res[i] <= last; i++) 
    { 
        if (!(x % res[i]))  
            return 0;  
    } 
    return 1; 
} 

int main(){
	sieve();
	unsigned i,j;
	int p[106]={0};
	for(i=0;i<=MAX>>6;i++){
		for(j=0;j<32;j++)
		if(!(flag[i]&(1<<j)))res[k++]=(i<<6)+(j<<1)+1;
	}
	int t;
		unsigned long fno,sno;
		fno=1000;sno=9999;
		if(fno==1)fno++;
		if(2==fno)printf("2\n");
		if(0==fno%2)fno++;
	int pi=0;
        while (fno <= sno)
        { 
		if (process(fno)) 
		{ 
			p[pi++]=fno; 
		} 
		fno+=2; 
        }
	//make adjlist of graph using array p
	int a,b;
	scanf("%d",&t);
	while(t--){
		cin >> a;
		cin >> b;
		printf("%d\n",bfs(a,b)); // implement bfs(a,b)
		}
	return 0;
}