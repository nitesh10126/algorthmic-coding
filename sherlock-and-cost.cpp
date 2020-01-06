#include <bits/stdc++.h>

using namespace std;


int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <int> b, lo, hi;
        b.assign(n, 0);
        lo.assign(n, 0);
        hi.assign(n,0);
        for(int i=0; i<n; i++){
            cin >> b[i];
        }
        lo[0]=0;
        hi[0]=0;
        for(int i=1; i<n; i++){
            lo[i] = max(lo[i-1],hi[i-1] + abs(b[i-1]-1));
            hi[i] = max(hi[i-1]+abs(b[i]-b[i-1]),lo[i-1]+abs(1-b[i]));
        }
        cout << max(lo[n-1],hi[n-1]) << endl;
    }
    return 0;
}
