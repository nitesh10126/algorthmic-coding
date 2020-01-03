#include <stdio.h>

unsigned long long int getReverse(unsigned long long int p){
	unsigned long long int q=0;
	int i;
	while(p!=0){
		i=p%10;
		q=q*10+i;
		p=p/10;
	}
return q;
}

int isPalindrome(unsigned long long int p){
	if(p==getReverse(p)) 
		return 1;
	else
		return 0;
}

int main(){
	int t,i;
	unsigned long long int p,q;
	scanf("%d",&t);
	while(t--){
		i=0;
		scanf("%llu",&p);
		while(!isPalindrome(p)){
				q	=	getReverse(p);
				p	=	p+q;
				i++;
			}
		printf("%d %llu\n",i,p);
	}
return 0;	
}