#include <stdio.h>
int main(){
	int b1,b2,b3,g1,g2,g3,c1,c2,c3;
	int result[6];																		// 0-BCG 1-BGC 2-CBG 3-CGB 4-GBC 5-GCB
	char* colors[] = {"BCG\0","BGC\0","CBG\0","CGB\0","GBC\0","GCB\0"};
	int i;
	int min_i;
		
	while(scanf("%d",&b1) != EOF){
		scanf("%d %d %d %d %d %d %d %d",&g1,&c1,&b2,&g2,&c2,&b3,&g3,&c3);
		min_i=0;
		result[0] = b2+b3+c1+c3+g1+g2;
		result[1] = b2+b3+g1+g3+c1+c2;
		result[2] = c2+c3+b1+b3+g1+g2;
		result[3] = c2+c3+g1+g3+b1+b2;
		result[4] = g2+g3+b1+b3+c1+c2;
		result[5] = g2+g3+c1+c3+b1+b2;
		for(i=0;i<6;i++){
				min_i = result[min_i]<=result[i] ? min_i : i;
			}
		printf("%s %d\n",colors[min_i],result[min_i]);
	}	
return 0;
}