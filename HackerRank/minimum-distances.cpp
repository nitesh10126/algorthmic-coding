#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector < int > ar(n, -1);
    for(int i=0; i<n; i++){
        cin >> ar[i];
    }
    vector < int > checkRank(100001,-1);
    int minDiff = INT_MAX;
    
    for(int i=0; i<n; i++){
        if(checkRank[ar[i]] != -1){
            minDiff = minDiff>i-checkRank[ar[i]]?i-checkRank[ar[i]]:minDiff;
            checkRank[ar[i]]=i;
        }else{
            checkRank[ar[i]]=i;
        }
    }
    if(minDiff == INT_MAX)
            cout << -1;    
    else
            cout << minDiff;
    return 0;
}

