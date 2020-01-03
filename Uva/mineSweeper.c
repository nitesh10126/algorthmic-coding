#include <stdio.h>

//why %c scanf is not prompting !!

int main(){
	int m,n;
	scanf("%d",&m);
	scanf("%d",&n);
	int i,j,t=0;
	while(0!=m &&  0!=n){
		t+=1;
		char mines[m+2][n+2];
		
		for(i=0;i<m;i++)scanf("%s",&mines[i+1][1]);
		
		for(i=0;i<m+2;i++)	mines[i][n+1]=mines[i][0]='.';
		for(j=0;j<n+2;j++)		mines[m+1][j]=mines[0][j]='.';
		
		if(1==t)printf("Field #%d:\n",t);
		else printf("\nField #%d:\n",t);
		
		for(i=1;i<m+1;i++){
			for(j=1;j<n+1;j++){
				if('*' == mines[i][j])
					printf("*");
				else
				{
					int mineCount=0,ii,jj;
					for(ii=i-1;ii<=i+1;ii++)
						for(jj=j-1;jj<=j+1;jj++){
							if(mines[ii][jj]=='*')mineCount++;
						}
					printf("%d",mineCount);
				}
			}
			printf("\n");
		}
		//printf("\n");
		scanf("%d",&m);
		scanf("%d",&n);
	}
return 0;
}