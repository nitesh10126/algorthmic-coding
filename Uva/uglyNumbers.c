// Clever use of Dynamic Programming

#include <stdio.h>

int main(){
	int a[1500];
	int p1,p2,p3,last=0;
	a[0]=1;
	p1=p2=p3=0;

	while(last<1499){
		
		while(a[p1]*2 <= a[last]) p1++;
		while(a[p2]*3 <= a[last]) p2++;
		while(a[p3]*5 <= a[last]) p3++;
		
		if(a[p1]*2 < a[p2]*3 && a[p1]*2 < a[p3]*5)
			a[++last] = a[p1++]*2;
		else
			if(a[p2]*3 < a[p3]*5)
				a[++last] = a[p2++]*3;
			else
				a[++last] = a[p3++]*5;
	}
	printf("The 1500'th ugly number is %d.\n",a[last]);
return 0;	
}