#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    while(t--){
        long long int b,w;
        cin >> b >> w;
        long long int x,y,z;
        cin >> x >> y >> z;
        if(x+z < y)y=x+z;
        else
        if(y+z < x)x=y+z;
        long long int result = b*x+w*y;
        cout << result << endl;
    }
    return 0;
}

