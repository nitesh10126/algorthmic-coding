#include <stdio.h>
int* handleDAC(int [],int,int);
int main(){
	int price[] = {1,5022,30,12,15,44,34,2,23,45};
	int len = 10;
	int* res = handleDAC(price,0,len-1);
	printf("%d %d\t%d\n",res[1],res[2],res[0]);
	return 0;
}

int* handleDAC(int price[],int i,int j){
	int a[5];
	//int merge[5];
	if(i>j || i<0)return;
	if(i==j){
		a[0=0;a[1]=a[2]=a[3]=a[4]=i; //{0,i,i,i,i};
		return a;
	}
	if(j-i+1==2){
		int a[5];
		int profit;							//profit [0], profit_i [1], profit_j [2], minIndex [3], maxIndex  [4]
		profit = price[j]-price[i];
		a[0]=profit;
		a[1]=i;a[2]=j;
		if(price[i]<=price[j]){
			a[3]=i;
			a[4]=j;
		}else{
			a[3]=j;
			a[4]=i;
		}
		return a;
	}
	
	int mid = i + (j-i)/2;
	int* left = handleDAC(price,i,mid);
	int* right = handleDAC(price,mid+1,j);
	int merge[5];
	int profit,minIndex,maxIndex;
	
	minIndex = price[left[3]]<price[right[3]]?left[3]:right[3];
	maxIndex = price[left[4]]<price[right[4]]?right[4]:left[4];
	merge[3] = minIndex;
	merge[4] = maxIndex;
	profit = price[right[4]]-price[left[3]];
	if(profit<left[0]){
		merge[0] = left[0];
		merge[1] = left[1];
		merge[2] = left[2];
		
 	}else{
		merge[0]=profit;
		merge[1]=left[3];
		merge[2]=right[4];
	}
	
	if(merge[0]<right[0]){
		merge[0]=right[0];
		merge[1]=right[1];
		merge[2]=right[2];
	}
	return merge;
}