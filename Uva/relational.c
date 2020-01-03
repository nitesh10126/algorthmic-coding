#include <stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long long i,j;
		scanf("%lld %lld",&i,&j);
		if(i==j)
			printf("=\n");
		else
			printf("%c\n",i>j?'>':'<');
	}
return 0;
}