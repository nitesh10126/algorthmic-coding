#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int bs(vector < int > ar, int element, int lo, int hi){
    while(lo < hi){
        int mid = lo + (hi-lo+1)/2;
        if(ar[mid] < element)
            lo = mid + 1;
        else if(ar[mid] > element)
            hi = mid - 1;
        else return mid;
    }
    if(ar[lo] == element) return lo;
    else    return -1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n,d;
    cin >> n >> d;
    vector < int > ar(n,0);
    for(int i=0; i<n; i++){
        cin >> ar[i];
    }
    int count = 0;
    for(int i=1; i<n-1; i++){
        int j=-1;
        int k=-1;
        if(ar[i]-d >= 0)j = bs(ar,ar[i]-d,0,i-1);
        if(ar[i]+d <= ar[n-1])k = bs(ar,ar[i]+d,i+1,n-1);
        //cout << j << " " << k;
        if(j != -1 && k != -1)
            count++;
    }
    cout << count;
    return 0;
}

