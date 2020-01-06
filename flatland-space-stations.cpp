#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    cin >> n >> m;
    vector < int > isStation(n,0);
    int x;
    
    for(int i=0; i<m; i++){
        cin >> x;
        isStation[x] = 1;
    }
    int lastStation, firstStation;
    for(int i=0; i< n; i++){
        if(isStation[i]==1){
            firstStation=i;
            break;
        }
    }
    for(int i=n-1; i>=0; i--){
        if(isStation[i]==1){
            lastStation=i;
            break;
        }
    }
    int maxDistance = 0;
    int prevStation = firstStation;
    for(int i=firstStation+1; i<=lastStation; i++){
        if(isStation[i] == 1){
            maxDistance = maxDistance<(i-prevStation)/2?(i-prevStation)/2:maxDistance;
            prevStation = i;
        }
    }
    if(firstStation != 0){
        maxDistance = maxDistance<firstStation?firstStation:maxDistance;
    }
    if(lastStation != n-1){
        maxDistance = maxDistance<n-lastStation-1?n-lastStation-1:maxDistance;
    }
    cout << maxDistance;
    return 0;
}

