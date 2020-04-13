#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    int total=0;
    int seed=5;
    //int prev_seed;
    for(int i=0; i<n; i++){
        total += seed/2;
        seed = 3*(seed/2);
    }
    cout << total;    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

