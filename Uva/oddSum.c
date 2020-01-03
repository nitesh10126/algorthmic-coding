#include <stdio.h>
int main(){
	int t;
	int i,j;
	int m,n;
	scanf("%d",&t);
	int sn=1;
	while(t--){
		scanf("%d\n%d",&i,&j);
		m	=	i%2==0?i+1:i;
		n 	=	j%2==0?j-1:j;
		printf("Case %d: %d\n",sn++,(((n-m+2)/2)*(m+n))/2);
	}
return 0;	
}