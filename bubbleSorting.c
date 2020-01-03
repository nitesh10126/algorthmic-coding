// Bubble Sorting : O(n^2)

#include <stdio.h>

void swap(int [], int, int);
void bubbleSort(int [],int , int);

int main(){
	int numbers[] = {115,22,8,6,19,12,65,77,13,54};	//{1,2,3,4,5,6,7,8,9,10};//
	int n=10;
	bubbleSort(numbers,0,9);
	int i=0;
	for(;i<10;i++)printf("%d\t",numbers[i]);
	return 0;
}

void bubbleSort(int numbers[],int i,int j){	
	int p,q,countFlag;
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

void swap(int numbers[],int i,int j){
	int a = numbers[i];
	numbers[i] = numbers[j];
	numbers[j] = a;
}