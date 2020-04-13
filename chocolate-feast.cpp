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
        int n, c, m;
        cin >> n >> c >> m;
        int eaten = n/c;
        int wrappers = eaten;
        int chocs = wrappers/m;
        
        while(chocs != 0){
            eaten += chocs;
            wrappers = chocs + (wrappers % m); 
            chocs = wrappers/m;
        }
        cout << eaten << endl;
    }
    return 0;
}

