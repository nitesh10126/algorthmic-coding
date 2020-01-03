#include<iostream>
#include<algorithm>
using namespace std;

int *a;
int n;
unsigned long long int MIN;

int computeGCD(int a, int b){
	if(b==0) return a;
	computeGCD(b,a%b);
	}

unsigned long long int computeLCM(int a, int b){
	unsigned long long int c;
	c=a*b;
	c=c/computeGCD(a,b);
	return c;
	}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		a=new int[n];
		int i;
		for(i=0;i<n;i++) cin >> a[i];
		sort(a,a+n);
		MIN = computeLCM(a[1],a[0]);
		for(i=1;i<n-1;i++){
			unsigned long long int l = computeLCM(a[i+1],a[i]);
			MIN = MIN>l ? l:MIN;
			}
		cout << MIN << "\n";
		}
	return 0;
	}