#include <iostream>
using namespace std;

int main(){
	int a,n;
	cin >> a;
	cin >> n;
	long long int c,b;
	int k;
	c=a;b=1;k=n;
	while(k != 0){
		if(k%2 == 0){
			c=c*c;
			k/=2;
		}
		else{
			b=b*c;
			k--;
		}
	}
	cout <<a<<" to the power "<<n<<" is :"<<b;
	return 0;
	}
// O(log n)