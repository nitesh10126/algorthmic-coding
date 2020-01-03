#include <stdio.h>
int main(){
	int count=0;
	char c;
	int flag;
	while((c=getchar()) != EOF){								//	A=65 Z=90 a=97  z=122 \n=10 EOF= -1
		count=0;
		while(c != '\n'){
			
			while(!((c>64 && c<91)||(c>96 && c<123))){		//	skipping anything else than alphabates
				c=getchar();
				if(c==10 || c==-1) break;
			}
			
			flag=0;
			while((c>64 && c<91)||(c>96 && c<123)){			//	skipping letters of word found
				flag=1;
				c=getchar();
			}
			
			if(1==flag)count++;							// 	counting words in line
			}
		printf("%d\n",count);								
		}
return 0;
}