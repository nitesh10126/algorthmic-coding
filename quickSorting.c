// Quick Sort
// lesson learned : Don't use wrongSwap function ever unless asked specifically.

#include <stdio.h>
void quickSort(int [],int ,int);
int quickPartition(int [],int,int);
void swap(int[],int,int);

int main(){
	int numbers[] = {115,22,8,6,19,12,65,77,13,54};
	int n=10;
	quickSort(numbers,0,9);
	int i=0;
	for(;i<10;i++)printf("%d\t",numbers[i]);
	return 0;
	}
	
void quickSort(int numbers[],int i,int j){	//Handle function : Recursively divide list into two parts and 
	if(1==j-i+1)return;
	if(i<0 || i>j )return;
	int m = quickPartition(numbers,i,j);
	quickSort(numbers,i,m-1);
	quickSort(numbers,m+1,j);
	return;
	}
	
int quickPartition(int numbers[],int i,int j){ // loc means LOC between smaller and larger elements
	int loc=i,pivot=numbers[i],a=i+1;
	while(a<=j){
		if(numbers[a]<=pivot){
			if(loc+1 < a)swap(numbers,++loc,a);
			else loc++;
		}
		a++;
	}
	swap(numbers,i,loc);
	return loc;
	}

void swap(int numbers[],int i,int j){
	int a = numbers[i];
	numbers[i] = numbers[j];
	numbers[j] = a;
}

/*
void wrongSwap(int numbers[],int i,int j){		// takes O(1)	// this approach of swapping integers have very critical flaw : fails when i and j indices equals.
	numbers[i]=numbers[i]+numbers[j];
	numbers[j]=numbers[i]-numbers[j];
	numbers[i]=numbers[i]-numbers[j];
	}
*/