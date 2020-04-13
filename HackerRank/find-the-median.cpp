#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr.begin(), arr.end());
    int result = arr[n/2];
    cout << result << "\n";
    return 0;
}

