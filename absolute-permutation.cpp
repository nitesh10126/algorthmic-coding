#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t, n, k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        if(k == 0){
            for(int i=1; i<=n; i++){
                cout << i << " ";
            }
            cout << endl;
            continue;
        }
        if(n%k != 0){
            cout << -1 << endl;
            continue;
        }
        if((n/k)%2 != 0){
            cout << -1 << endl;
            continue;
        }
        
        for(int i=1; i<=n; i=i+2*k){
            for(int j=0; j<k; j++)
                cout << i+k+j << " ";
            for(int j=0; j<k; j++)
                cout << i+j << " ";
        }
        cout << endl;
    }
    return 0;
}

