#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t, n, a, b;
    cin >> t;
    while(t--){
        cin >> n >> a >> b;
        if(n==1){
            cout << 0 << endl;
            continue;
        }
        if(a == b){
            cout << a*(n-1) << endl;
            continue;
        }
        int min = a<b?a:b;
        int max = a>b?a:b;
        a=max;
        b=min;
        for(int i=0; i<= n-1; i++){
            cout << (n-i-1)*b + i*a << " ";
        }
        cout << endl;
    }
    return 0;
}

