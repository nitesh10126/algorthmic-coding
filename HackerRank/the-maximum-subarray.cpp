#include <bits/stdc++.h>
#include <limits.h>>
using namespace std;

int maxSubarray(vector<int> a) {
    if(a.size()==1)return a[0];
    
    vector <int> mem;
    mem.assign(a.size(),-1);
    mem[0] = a[0];
    int ans = a[0];
    for(int i=1; i<a.size(); i++){
        mem[i] = max(mem[i-1]+a[i], a[i]);
        ans = max(mem[i],ans);
    }
    return ans;
}

int maxSubsequence(vector <int> a){
    int ans1 = 0;
    int ans2 = INT_MIN;
    for(int i=0; i<a.size(); i++){
        ans1 += a[i]>0?a[i]:0;
        ans2 = max(ans2, a[i]);
    }
    if(ans1)return ans1;
    else return ans2;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector < int > a;
        a.assign(n,0);
        for(int i=0;  i<n; i++){
            cin >> a[i];
        }
    cout << maxSubarray(a) << " ";
    cout << maxSubsequence(a) << endl;
    }
    return 0;
}

