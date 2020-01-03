#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	int f;
	unsigned long long int sum;
	unsigned long long int a,b,c;
	while(t--){
		scanf("%d",&f);
		sum=0;
		while(f--){
			scanf("%llu %llu %llu",&a,&b,&c);
			sum+=a*c;
		}
		printf("%llu\n",sum);
	}
return 0;	
}