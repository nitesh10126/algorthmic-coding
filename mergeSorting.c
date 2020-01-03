// yes, it works without header. Just give warning. why?
int mergeSort(int [],int ,int);
void merge(int [],int,int,int);
void swap(int [],int,int);

int main(){
	int numbers[] = {115,22,8,6,19,12,65,77,13,54};
	int n=10;
	mergeSort(numbers,0,9);
	int i=0;
	for(;i<9;i++)printf("%d\t",numbers[i]);
	return 0;
}

int mergeSort(int numbers[],int i,int j){ 	// Handle Function : Recursively divide the list into half and merges them once sorted. Takes O(n*logn) time
	if(1==j-i+1)return;
	if(2==j-i+1){
		if(numbers[i]>numbers[j])swap(numbers,i,j);
		return;
	}
		
	int m = i+(j-i)/2;
	mergeSort(numbers,i,m);
	mergeSort(numbers,m+1,j);
	merge(numbers,i,m,j);
	return 0;
}

void merge(int numbers[],int i,int m,int j){	// Critical Step :  merge two sorted arrays of size n/2 and make single sorted array in O(n) time
	int len = j-i+1;
	int temp[len];
	int s1,k1,s2,k2,t=0;
	s1=i,s2=m+1,k1=m+1,k2=j+1;
	while((s1<k1)&&(s2<k2)){
		if(numbers[s1]<numbers[s2])temp[t++]=numbers[s1++];
		else temp[t++]=numbers[s2++];
	}
	if(s1==k1)for(;s2<k2;s2++)temp[t++]=numbers[s2];
	if(s2==k2)for(;s1<k1;s1++)temp[t++]=numbers[s1];
	s1=i;
	for(t=0;t<len;t++)numbers[s1++]=temp[t];
}

void swap(int numbers[],int i,int j){
	int a = numbers[i];
	numbers[i] = numbers[j];
	numbers[j] = a;
}
