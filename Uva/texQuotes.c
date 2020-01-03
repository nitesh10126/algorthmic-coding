#include <stdio.h>
int main(){
	char c;
	int i=0;
	while((c=getchar()) != EOF){
		if(c!='"')
			printf("%c",c);
		else{
			if(0==i){
				printf("``");
				i=(i+1)%2;
			}
			else{
				printf("'");printf("'");
				i=(i+1)%2;
			}
		}
	}
return 0;	
}