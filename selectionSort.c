// Selection Sorting : O(n^2)

#include <stdio.h>

void selectionSort(int [], int, int);
void swap(int [], int, int);

int main(){
	int numbers[] = {115,22,8,6,19,12,65,77,13,54};
	int n=10;
	selectionSort(numbers,0,9);
	int i=0;
	for(;i<10;i++)printf("%d\t",numbers[i]);
	return 0;
}

void selectionSort(int numbers[],int i,int j){		// selection sort select min out of right part of unsorted list and puta in place, reducing size of problem at each step by 1.
	int p,q,minAt;
	for(p=i;p<=j;p++){
		q=p;
		minAt=p;
		while(q<=j){
			minAt=numbers[minAt]>numbers[q]?q:minAt;
			q++;
		}
		swap(numbers,p,minAt);
	}
}

void swap(int numbers[],int i,int j){
	int a = numbers[i];
	numbers[i] = numbers[j];
	numbers[j] = a;
}