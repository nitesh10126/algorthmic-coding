#include<bits/stdc++.h>
using namespace std;

// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<long> vl;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!

/*
This function merges two sorted vectors x and y in O(x.size() + y.size()) time.
*/
vll merge(vll &x, vll &y){
    vll result;
    size_t i=0, j=0;
    while((i < x.size()) && (j < y.size())) {
        if (x[i] <= y[j]) {
            result.push_back(x[i]);
            i++;
        } else {
            result.push_back(y[j]);
            j++;
        }
    }
    while(i < x.size()) {
        result.push_back(x[i]);
        i++;
    }
    while(j < y.size()) {
        result.push_back(y[j]);
        j++;
    }
    return result;
}

vll merge_sort(vll &a, int l, int u){
    if (u <= l){
        /* atmost one element, return the vector containing just this element.*/
        vll temp{a[l]};
        return temp;
    }
    int m = l + (u-l)/2;
    vll x = merge_sort(a, l , m);
    vll y = merge_sort(a, m+1, u);
    return merge(x, y);
}

int main() {
    vll number{4, 1, 6, 8, 123, 13, 1121, 24, 123};
    number = merge_sort(number, 0, 8);
    REP(i, 0, 8) cout << number[i] << " ";
}