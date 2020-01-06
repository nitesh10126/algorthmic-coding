#include <bits/stdc++.h>

using namespace std;

// Complete the getWays function below.
long getWays(long n, vector<long> c) {
    int m = c.size();
    vector<long> table;
    table.assign(n+1,0);
    int i,j;
    table[0]=1;
    for(j=0; j<m; j++){
        int coin = c[j];
        if(coin<=n){
        table[coin]++;
        for(i=coin+1; i<=n; i++){
            table[i] += (table[i-coin]);
        }
        }
    }
    return table[n];
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector <long> c(m);
    for(int i = 0;i < m; i++){
        cin >> c[i];
    }
    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    long ways = getWays(n, c);
    cout << ways << endl ;
    return 0;
}

