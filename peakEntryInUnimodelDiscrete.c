/*
Algorithm Design : chappter DaC : Exercise 1 :

Suppose you are given an array A with n entries, with each entry holding a
distinct number. You are told that the sequence of values A[1], A[2], . . . , A[n]
is unimodal: For some index p between 1 and n, the values in the array entries
increase up to position p in A and then decrease the remainder of the way
until position n. (So if you were to draw a plot with the array position j on the
x-axis and the value of the entry A[j] on the y-axis, the plotted points would
rise until x-value p, where they'd achieve their maximum, and then fall from
there on.)
You'd like to find the "peak entry" p without having to read the entire
array--in fact, by reading as few entries of A as possible. Show how to find
the entry p by reading at most O(log n) entries of A.

*/

#include <stdio.h>

int searchDAC(int [],int,int);

int main(){
	int  list[] = {1,2,3,4,5,6,13,72,564,32,22,11,3,2,1};
	int len = 15;
	int peakEntry = searchDAC(list,0,len-1);
	printf("%d\t",peakEntry);
	return 0;
}

int searchDAC(int list[],int i,int j){		// exploiting the fact that it is discreet unimodel function. Observe, it won't work in case of continuous unimodel function.
	int mid = i + (j-i)/2;
	if(list[mid-1]<list[mid] && list[mid]<list[mid+1])
		return searchDAC(list,mid+1,j);
	if(list[mid-1]>list[mid] && list[mid]>list[mid+1])
		return searchDAC(list,i,mid-1);
	if(list[mid-1]<list[mid] && list[mid]>list[mid+1])
		return mid;
}