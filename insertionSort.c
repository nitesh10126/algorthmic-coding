// Insertion Sorting : O(n^2) though best in Bubble, Selection and Insertion Sort algorithm

#include <stdio.h>

void insertionSort(int [],int,int);
void swap(int [],int,int);

int main(){
	int numbers[] = {115,22,8,6,19,12,65,77,13,54};
	int n=10;
	insertionSort(numbers,0,9);
	int i=0;
	for(;i<10;i++)printf("%d\t",numbers[i]);
	return 0;
	}
	
void insertionSort(int numbers[],int i,int j){
	int len = j-i+1, p=1,q,elementToBeInserted;
	for(;p<len;p++){
		elementToBeInserted = numbers[p];
		q=p-1;
		while(q>=0){
			if(numbers[q]>elementToBeInserted){
				swap(numbers,q,q+1);
				q--;
			}
			else{
				break;
			}
		}
		numbers[q+1]=elementToBeInserted;	
	}
}
	
void swap(int numbers[],int i,int j){
	int a = numbers[i];
	numbers[i] = numbers[j];
	numbers[j] = a;
}