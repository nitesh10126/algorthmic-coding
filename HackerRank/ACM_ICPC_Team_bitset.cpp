#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;


int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    const size_t l = 500;
    string topicMatrix[n];
    for(int i=0; i<n; i++){
            cin >> topicMatrix[i];
    }
    int max = -1;
    int maxCount = 0;
    for(int i=0; i<n-1; i++){
        string a_str = topicMatrix[i];
        for(int j=i+1; j<n; j++){
            string b_str = topicMatrix[j];
            bitset<l> a(a_str), b(b_str);
            bitset<l> c = a | b;
            int oneCount = c.count();
            if(max < oneCount){
                max = oneCount;
                maxCount = 1;
            }
            else
                if(max == oneCount){
                    maxCount++;
                }
        }
    }
    cout << max << endl << maxCount;
    return 0;
}

