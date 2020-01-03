#include <stdio.h>

int main(){
	int  list[] = {1,2,3,4,5,6,13,72,564,3233,222,1111,3,2,1};
	int len = 15;
	int peakEntry = searchDAC(list,0,len-1);
	printf("%d\t",list[peakEntry]);
	return 0;
}

int searchDAC(int list[],int i,int j){
	int mid_1 = i + (j-i)/3;
	int mid_2 = i + 2*(j-i)/3;
	if(i == j)return i;
	if(i == j-1)return list[i]>list[j]?i:j;	// check absolute difference. In case of continuous function, difference = 0.001 is good.
	if(list[mid_1] < list[mid_2])
		return searchDAC(list,mid_1+1,j);
	if(list[mid_1] > list[mid_2])
		return searchDAC(list,i,mid_2-1);
	if(list[mid_1] == list[mid_2])
		return searchDAC(list,mid_1,mid_2);
}