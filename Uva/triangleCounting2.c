#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define N 1000001
unsigned long long int dp[N];
//Returns sum between integers 1 to n inclusive
unsigned long long int sum(int n)
{
    return  (unsigned long long int)n*(n+1)/2;
}
int main()
{
    int i,n;
    for(i=0;i<N;i++)
        dp[i]=0;
    dp[4]=1;
    for(i=5;i<N;i++)
    {
        n = i/2 -1;
        dp[i]=dp[i-1]+2*sum(n)-((!(i&1))*n);
        //((!(i&1))*n) if i is even this evaluates as n else it evaluates as 0
    }
    scanf("%d",&n);
    while(n>=3)
    {
        printf("%llu\n",dp[n]);
        scanf("%d",&n);
    }
    return 0;
}