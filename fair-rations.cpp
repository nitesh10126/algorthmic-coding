#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int getResult(vector < int > bread, int n){
    int sum = 0;
    for(int i=0; i<=n-2; i++){
        if(bread[i]%2 != 0){
            sum += 2;
            bread[i+1]++;
        }
    }
    if(bread[n-1]%2 == 0){
        return sum;
    }else{
        return -1;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n ;
    cin >> n ;
    vector < int > bread(n,-1);
    for(int i=0; i<n; i++){
        cin >> bread[i];
    }
    int result = getResult(bread,n);
    if(result == -1)
        cout << "NO";
    else
        cout << result;
    return 0;
}

