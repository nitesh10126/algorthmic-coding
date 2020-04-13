#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int p,q;
    cin >> p >> q;
    int check = 0;
    for(long long int i=p; i<=q; i++){
        
        long long int square = i*i;
        long long int r,l;
        long long int d = pow(10 , floor(log10(i)) + 1);
        //cout << d << " ";
        r = square%d;
        l = square/d;
        if(l+r == i) {
            cout << i << " ";
            check = 1;
        }
    }
    if(check == 0) cout << "INVALID RANGE";
    return 0;
}

