#include <stdio.h>

unsigned long long int getExtra(unsigned long long int i){
		if(0==i%2)
			return (unsigned long long int) (i-2)*(i-2);
		else
			return (unsigned long long int) (i-3)*(i-1);
	}

int main(){
	int n;
	unsigned long long int len = 1000001;
	unsigned long long int a[len];
	a[3]=0;
	unsigned long long int i;
	for(i=4;i<len;i++){
			a[i] = a[i-1] + (getExtra(i)/4);
			}
	scanf("%d",&n);
	while(n>=3){			// while(1) was giving compile error @Uva.
		printf("%llu\n",a[n]);
		scanf("%d",&n);
		}
	return 0;
	}