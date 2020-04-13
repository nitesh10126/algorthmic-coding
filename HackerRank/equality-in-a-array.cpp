#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector < int > ar;
    ar.assign(n,-1);
    
    vector < int > countAr;
    countAr.assign(101,0);
    for(int i=0; i<n; i++){
        cin >> ar[i];
        countAr[ar[i]]++;
    }
    
    int max=0;
    for(int i=1; i<=100; i++){
        max = max>countAr[i]?max:countAr[i];
    }
    cout << n - max;
    return 0;
}

