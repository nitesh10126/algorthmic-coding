#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k , x;
    cin >> n;
    cin >> k;
    cin >> x;
    vector<long> with_x, without_x;
    with_x.assign(n,0);
    without_x.assign(n,0);

    int t;
    if(1==x)
        t=1;
    else
        t=2;
    
    with_x[1]=t-1; // initialize with 1 if x==1 else initialize with 0
    without_x[1]=k-t;
    for(int i=2; i<n; i++){
        with_x[i] = without_x[i-1] % 1000000007;
        without_x[i] = ((with_x[i-1]*(k-1)) % 1000000007 + (without_x[i-1]*(k-2)) % 1000000007)
            % 1000000007;
    }
    cout << with_x[n-1];
    return 0;
}
