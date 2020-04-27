#include<bits/stdc++.h>
using namespace std;

// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

// To simplify repetitions/loops, Note: define your loop style and stick with it!
#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define TRvi(c, it) \
for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for (msi::iterator it = (c).begin(); it != (c).end(); it++)

#define INF 2000000000 // 2 billion
// If you need to recall how to use memset:
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B
//memset(dist, MEMSET_INF, sizeof dist); // useful to initialize shortest path distances
//memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP memoization table
//memset(arr, 0, sizeof arr); // useful to clear array of integers

void swap(ll* a, int i, int j) {
    ll temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void qsort(ll* a, int l, int u){
    if(l >= u){
        /* atmost one element, do nothing.*/
        return;
    }
    // partition the array around a particular value (pivot), which is eventually placed at it's correct position.
    int random = rand()%(u-l+1) + l; // random index in l and u (including both)
    swap(a, l, random);
    ll p = a[l]; // pivot
    int pi = l;
    REP(i, l+1, u) {
        if (a[i] <= p) {
            swap(a, i, pi+1);
            pi++;
        }
    }
    swap(a, pi, l);
    qsort(a, l, pi-1);
    qsort(a, pi+1, u);
}

int main() {
    int n;
    cout << "Enter number of element in unsorted array:" << endl;
    cin >> n; 
    ll numbers[n];
    cout << "Enter the unsorted numbers:" << endl;
    int i = -1;
    while(++i != n) {
        cin >> numbers[i];
    }
    qsort(numbers, 0, n-1);
    cout << "Numbers in sorted order using Quick Sort:" << endl;
    REP(i, 0, n-1) cout << numbers[i] << " ";
}