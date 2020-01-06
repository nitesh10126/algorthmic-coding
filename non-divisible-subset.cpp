#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,k;
    cin >> n >> k;
    vector < int > ar;
    ar.assign(n,-1);
    vector < int > rem;
    rem.assign(k,0);
    for (int i = 0; i < n; i++){
        cin >> ar[i];
        rem[ar[i]%k]++;
    }
    
    int count=0;
    int max=0;
    for(int i=1; i <= k/2; i++){
        max = rem[i]>rem[k-i]?rem[i]:rem[k-i];
        count+=max;
    }
    if(rem[0] > 0)count++;
    if(k%2==0){
        if(rem[k/2] > 0){
            count = count - rem[k/2];
            count++;
        }
    }
    cout << count;
    return 0;
}

