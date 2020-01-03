#include <bits/stdc++.h>
using namespace std;
int s,n,m;
vector < int > keyboard,drive;

void swap(vector <int>& ar, int i, int j){
    int temp = ar[i];
    ar[i] = ar[j];
    ar[j] = temp;
}

int partition(vector < int >& ar, int i, int j){
    int pivot = ar[j];
    int pivot_rank = i-1;
    for(int k = i; k < j; k++){
        if(ar[k] <= pivot) {
            pivot_rank++;
            swap(ar,k,pivot_rank); 
        }
    }
    pivot_rank++;
    swap(ar,pivot_rank,j);
    return pivot_rank;
}

void quickSort(vector < int >& ar, int i,  int j ){
    //int pivot = keyboard[i];
    if(i < j){
    int pivot_rank = partition(ar,i,j);
    quickSort(ar,i,pivot_rank-1);
    quickSort(ar,pivot_rank+1, j);
    }
}

int binarySearch(vector < int >& ar, int n, int i, int j){
    while(i < j){
        int mid = i + (j-i+1)/2;
        if(ar[mid] <= n)
            i = mid;
        else
            j = mid - 1;
    }
    if(ar[i] > n) return -1;
    return ar[i];
}

int getResult(){
    quickSort(keyboard,0,n-1);
    quickSort(drive,0,m-1);
    int max = -1;
    
    int lo, hi;
    lo=0;
    hi=n-1;
    
    while(lo < hi){
        int mid = lo + (hi - lo + 1)/2;
        int bsResult = binarySearch(drive, s-keyboard[mid], 0, m-1);
        if(bsResult == -1){
            hi = mid - 1;
        }
        else
        {
            max < bsResult+keyboard[mid] ? max=bsResult+keyboard[mid] : max=max;
            lo = mid;
        }
    }
    return max;
}

int main(){
    
    cin >> s >> n >> m;
    
    keyboard.assign(n, 0);
    drive.assign(m, 0);
    for(int i=0; i<n; i++) cin >> keyboard[i];
    for(int i=0; i<m; i++) cin >> drive[i];
    int result = getResult();
    cout << result;
    return 0;
}

