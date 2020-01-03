#include <stdio.h>
int main(){
	int n;
	while(scanf("%d",&n) != EOF){
		int a[n],flag[n];
		int i,j;
		for(i=0;i<n;i++)scanf("%d",&a[i]);
		for(i=0;i<n;i++)flag[i]=0;
		for(i=0;i<n-1;i++){
			j=a[i]>a[i+1]?a[i]-a[i+1]:a[i+1]-a[i];
			if(j<n){
				flag[j]=1;
			}
		}
		i=1;
		while((i<n) && flag[i])i++;
		if(i==n)
			printf("Jolly\n");
		else
			printf("Not jolly\n");
	}
return 0;	
}