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
    while (t--) {
    string s;
    cin >> s;
    int i = next_permutation(s.begin(),s.end());
    if (i==0) cout<< "no answer" << endl;
        else cout << s << endl;
    }
    return 0;
}

