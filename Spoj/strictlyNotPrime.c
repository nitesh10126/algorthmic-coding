/*
MAIN111 - Strictly not a Prime
#math #number-theory

Tim defines an integer as "Strictly not a Prime", if no subsequence(considering the integer as a string of digits) of the integer is a prime. He needs your help in finding how many such integers are present between two given integers A and B(including A and B).
Input

First line contains an integer T(1 <= T <= 100000) which denotes the total number test cases. Each test case consists of two integers A and B (1 <= A, B <= 100000) on a single line.
Output

For each test case, print the total count of integers which are "Strictly not a prime" between A and B(including A and B) as per tim.
*/

    #include <stdio.h>
    #include <math.h>
    #define max 100005
    int prime[max];
    int res[max];
    int isStrictlyNotPrime[max];
     
    void primeSeive() //generate list of prime number using seive
		{
    		int i;
    		for(i=0;i<max;i++)prime[i]=1;
    		prime[1]=0;
    		prime[0]=0;
    		for(i=2;i*i<max;i++){
    			if(prime[i]){
    				int j =i; 
    				for(;j<max/i;j++)prime[i*j]=0;
    			}
    		}
    	}
     
    int check(int n) //check whether number n is "strictly not prime"
	{
    	if(prime[n])return 0;
    	int d,total,i,j;
    	d=(log10(n)+1);
    	total=1<<d;
    	int arr[d],arr_rev[d];
    	i=n;
    	j=-1;
    	while(i){
    		arr_rev[++j]=i%10;
    		i/=10;
    	}
    	while(i<d)	
		{
    		arr[d-i-1]=arr_rev[i];
    		i++;
    	}
    	for(i=1;i<total;i++)	//checking each substring i.e. subNumber ;)
		{
    		int x=0;
    		for(j=0;j<d;j++){
    			if(i&(1<<j))x=x*10+arr[j];
    			if(prime[x])return 0;
    		}
    	}
    return 1;	
    }
     
    void compute(){	//Precompute the array for Strictly not Prime numbers
    	int i,c;
    	res[0]=0;
    	isStrictlyNotPrime[0]=1;
    	res[1]=1;
    	isStrictlyNotPrime[1]=1;
    	for(i=2;i<max;i++){
    		int c = check(i);
            res[i]=res[i-1]+c;
            isStrictlyNotPrime[i]=c;
    		
    	}
    }
     
    int main(void) {
    	int t,i,j;
    	primeSeive();
    	compute();
    	scanf("%d",&t);
    	while(t--){
    		scanf("%d%d",&i,&j);
    		if(i>j){
    			i=i+j;
    			j=i-j;
    			i=i-j;
    		}
    		printf("%d\n",res[j]-res[i-1]);
    	}
    	return 0;
    }