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
        int n; cin >> n;
        vector < int > ar(n,-1);
        for(int i=0; i<n; i++){
            cin >> ar[i];
        }
        int count = 0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(ar[i] > ar[j])count++;
            }
        }
        if(count%2 == 0)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}

