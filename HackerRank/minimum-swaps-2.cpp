#include <bits/stdc++.h>

using namespace std;

// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> a) {
    int n = a.size();
    int i=0;
    int sum=0;
    while(i < n){
        if(a[i] != -1){
                int count=0;
                
                int tempi=a[i]-1;
                a[i]=-1;
                i = tempi;
                while(a[i] != -1){
                    count++;
                    tempi=a[i]-1;
                    a[i]=-1;
                    i = tempi;
                }
                sum += count;
            }
        i++;
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a; a.assign(n,-1);
    for(int i=0; i<n; i++) {cin >> a[i];}
    //for(int i=0; i<n; i++) cout << a[i] << " ";
    cout << minimumSwaps(a);
    return 0;
}


