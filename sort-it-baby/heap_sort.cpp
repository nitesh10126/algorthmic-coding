#include<bits/stdc++.h>
using namespace std;

// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

// To simplify repetitions/loops, Note: define your loop style and stick with it!
#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define TRvi(c, it) \
for (vi::iterator it = (c).begin(); it != (c).end(); it++)

void swap(ll* a, int i, int j) {
    ll temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

/*
Assumes given array 'a' as invalid maxheap and element at index 'i' is violating the maxheap property.
This method makes such array 'a' a valid maxheap.
Runs in O(log(n)) time.
*/
void max_heapify(ll* a, int i, int n) {
        int curr = i;
        int l = 2 * curr + 1;
        int r = 2* curr + 2;
        while (((l < n) && (a[curr] < a[l])) | ((r < n) && (a[curr] < a[r]))) {
            if ((r < n) && (a[r] >= a[l])) {
                swap(a, r, curr);
                curr = r;
            }
            swap(a, l, curr);
            curr = l;
            l = 2 * curr + 1;
            r = 2* curr + 2;
        }

}

/*
Assumes, 'a' as a valid maxheap.
sorts elements of 'a' in ascending order.
runs in O(n*log(n)) time.
*/
void heap_sort(ll* a, int n) {
    for (int i=n-1; i>-1; i--) {
        swap(a, 0, i);
        max_heapify(a, 0, i);
    }
}

/*
Builds MaxHeap of given n numbers. Runs in O(n) time.
*/
void build_maxheap(ll* a, int n) {
    for (int i=n/2; i>-1; i--) {
        max_heapify(a, i, n);
    }
}

/*
Handle function for Heap Sort.
*/
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
    build_maxheap(numbers, n);
    cout << "Max Heap of Numbers:" << endl;
    REP(i, 0, n-1) cout << numbers[i] << " ";
    heap_sort(numbers, n);
    cout << "Numbers in sorted order using Heap Sort:" << endl;
    REP(i, 0, n-1) cout << numbers[i] << " ";
}
