#include <stdio.h>
int noOfSwaps;

void swap(int numbers[],int i,int j){
	int a = numbers[i];
	numbers[i] = numbers[j];
	numbers[j] = a;
	noOfSwaps+=1;
}

void bubbleSort(int numbers[],int i,int j){	
	int p,q,countFlag;
	noOfSwaps=0;
	for(p=j-1;p>=0;p--){
		q = 0;
		countFlag = 0;
		while(q <= p){
			if(numbers[q]>numbers[q+1])swap(numbers,q,q+1);
			else countFlag++;
			q++;
			}
		if(countFlag==p+1)break;
	}
}

int main(){
	int t;
	scanf("%d",&t);
	int l,i;
	while(t--){
		scanf("%d",&l);
		int bogi[l];
		for(i=0;i<l;i++)scanf("%d",&bogi[i]);
		bubbleSort(bogi,0,l-1);
		printf("Optimal train swapping takes %d swaps.\n",noOfSwaps);
	}
return 0;
}