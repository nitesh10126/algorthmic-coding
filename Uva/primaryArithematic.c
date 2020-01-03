// lesson learnt : int can accomodate all numbers of 9 digits but fails for all 10 difits numbers

#include <stdio.h>

int main(){
	long long int a,b;
	int num1[10],num2[10];
	int i,j,carry,carryCount;
	scanf("%lld",&a);
	scanf("%lld",&b);
	
	while(a!=0 || b!=0){
		if(0==a || 0==b){
			printf("No carry operation.\n");
		}
		else
		{
		i=0;
		while(i<10){
			num1[i]=0;
			num2[i]=0;
			i++;
		}
		
		i=0;
		while(a != 0){
				num1[i] = a%10;
				a=a/10;
				i++;
		}
		
		j=0;
		while(b != 0){
				num2[j] = b%10;
				b=b/10;
				j++;
		}
		
		i=0;
		carryCount=0;
		carry=0;
		
		while(i<10){
				carry = (num1[i] + num2[i] + carry)/10;
				if(1==carry) carryCount+=1;
				i++;
			}
			
		if(0==carryCount)
			printf("No carry operation.\n");
		else
		{
			printf("%d carry operation",carryCount);
			if(carryCount>1)printf("s.\n");
			else printf(".\n");
		}
		}
	scanf("%lld",&a);
	scanf("%lld",&b);
	}
return 0;
}