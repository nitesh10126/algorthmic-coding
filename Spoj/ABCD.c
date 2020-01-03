/*
ABCD - Colours A, B, C, D
no tags 

Consider a table with 2 rows and 2N columns (a total of 4N cells). Each cell of the first row is coloured by one of the colours A, B, C, D such that there are no two adjacent cells of the same colour. You have to colour the second row using colours A, B, C, D such that:

o There are exactly N cells of each colour (A, B, C and D) in the table.

o There are no two adjacent cells of the same colour. (Adjacent cells share a vertical or a horizontal side.)

It is guaranteed that the solution, not necessarily unique, will always exist.
Input

[a natural number N <= 50000]

[a string of 2N letters from the set {A, B, C, D}, representing the first row of the table]
Output

[a string of 2N letters from the set {A, B, C, D}, representing the second row of the table]
*/
#include <stdio.h>

int main(){
		int n;
		scanf("%d",&n);
		int len = 2*n;
		char input[len];
		int i;
		scanf("%s",input);
		char full[2*len];
		for(i=0;i<2*len;i++){
			full[i]='A'+(i%4);
			}
		int j=0;
		i=0;
		while(i<2*len){
			if(full[i]==input[j]){
				full[i]='x';
			}
			if(full[i]==input[j+1]){
				full[i]='x';
			}
			i++;
			if(0==i%4)	j+=2;
		}
		int output[len];
		j=0;
		for(i=0;i<2*len;i++){
			if(full[i] != 'x')output[j++]=full[i];
			}
		char out[len+1];
		out[0]=output[0];
		out[1]=output[1];
		out[len]='\0';		
		for(i=2;i<len;i+=2){
			if(out[i-1]==output[i]){
				out[i]=output[i+1];
				out[i+1]=output[i];
			}else{
				out[i]=output[i];
				out[i+1]=output[i+1];
			}
			}
		printf("%s",out);
	return 0;
}
