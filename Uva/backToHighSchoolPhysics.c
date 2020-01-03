#include<stdio.h>

int main(){
	int v,t;
	while(scanf("%d %d",&v,&t) != EOF){
		if(t==0 && v==0) 
			printf("0\n");
		else
			printf("%d\n",2*v*t);
	}
return 0;	
}