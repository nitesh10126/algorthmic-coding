#include <bits/stdc++.h>

using namespace std;

int saveThePrisoner(int n, int m, int s){
    int remainder = m%n;
    if(s+remainder-1 <= n)
        return s+remainder-1;
    else
        return s+remainder-1-n;
    // Complete this function
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int m;
        int s;
        cin >> n >> m >> s;
        int result = saveThePrisoner(n, m, s);
        cout << result << endl;
    }
    return 0;
}

