#include <bits/stdc++.h>

using namespace std;

int minOps(int n){
        int ret=0;
        ret += n/5;
        n %= 5;
        ret += n/2;
        n %= 2;
        ret += n;
return ret;
}
// Complete the equal function below.
int equal(vector<int> arr, int min) {
    int n = arr.size();
    int ret= INT_MAX;
    
    for(int j=0; j<4; j++){
        int temp = 0;
    for(int i=0; i<n; i++){
        temp += minOps(arr[i]-min+j); 
    }
        ret = ret<temp?ret:temp;
    }
    return ret;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr;
        arr.assign(n,0);
        for(int i=0; i<n; i++)
            cin >> arr[i];
        int min=INT_MAX;
        for(int i=0; i<n; i++)
            min>arr[i]?min=arr[i]:1;
       
        cout << equal(arr, min) << endl;
    }
    return 0;
}
