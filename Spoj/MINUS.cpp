#include <iostream>
using namespace std;

int *a;
int *sign;
int n,m;
int MAX;
int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		cin >> m;
		a = new int[n];
		sign = new int[n];
		sign[0]=0;sign[1]=1;
		int i;
		for(i=0;i<n;i++) cin >> a[i];
		int MAX = (2*n-4)*100 + 1;		//	MAX >= Number which can be produced us MINUS operation on n elements
		int Offset = (n-2)*100;
		int j;
		int dp[n+1][MAX];
		
		for(i=2;i<=n;i++){
			for(j=-1*Offset;j<=Offset;j++){
				if(2==i){
					if(j==a[0]-a[1])dp[i][j+Offset]=1;
					else dp[i][j+Offset]=0;
				}
				else {
					if(dp[i-1][j+Offset+a[i-1]]){
						dp[i][j+Offset]=1;
					}
					if(dp[i-1][j+Offset-a[i-1]]){
						dp[i][j+Offset]=1;
					}
					if(dp[i-1][j-a[i-1]+Offset]==0 && dp[i-1][j+a[i-1]+Offset]==0)dp[i][j+Offset]=0;
				}
			}
		}
		
		i=n;
		j=m;
		while(i>2){
			if(dp[i-1][j-a[i-1]+Offset]){
				sign[i-1]=0;
				j=j-a[i-1];
				}
			else if(dp[i-1][j+a[i-1]]+Offset){
				sign[i-1]=1;
				j=j+a[i-1];
			}
			i--;
			}
		int c =0;	
		j=0;
		for(i=2;i<n;i++){
			if(0==sign[i]){
				c = i-j;
				cout << c << "\n";
				j++;
			}
		}
		c=1;
		for(i=1;i<n-j;i++) cout << c << "\n";
		cout << "\n";
	}
	return 0;
}