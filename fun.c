#include <stdio.h>
int main(){
	double d = 10.0;
	int i = 1;
	
	for(;d>1;d=d/2.0)printf("%d\t",i++);
	
	printf("\nTermination Checkpoint !!");
	return 0;
	}
	
// Theoritically this model must go in infinite loop but due to language boundation, it terminates.