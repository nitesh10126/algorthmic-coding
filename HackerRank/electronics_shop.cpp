#include <bits/stdc++.h>
using namespace std;
int s,n,m;
vector < int > keyboard,drive;

void swap(int i, int j){
    int temp = keyboard[i];
    keyboard[i] = keyboard[j];
    keyboard[j] = temp;
}

int partition(int i, int j){
    int pivot = keyboard[j];
    int pivot_rank = i-1;
    for(int k = i; k < j; k++){
        if(keyboard[k] <= pivot) {
            pivot_rank++;
            swap(k,pivot_rank); 
        }
    }
    pivot_rank++;
    swap(pivot_rank,j);
    return pivot_rank;
}

void quickSort( int i,  int j ){
    //int pivot = keyboard[i];
    if(i < j){
    int pivot_rank = partition(i,j);
    quickSort(i,pivot_rank-1);
    quickSort(pivot_rank+1, j);
    }
}

int binarySearch(int n, int i, int j){
    while(i < j){
        int mid = i + (j-i+1)/2;
        if(keyboard[mid] <= n)
            i = mid;
        else
            j = mid - 1;
    }
    if(keyboard[i] > n) return -1;
    return keyboard[i];
}

int getResult(){
    quickSort(0,n-1);
    vector < int > total;
    total.assign(m, 0);
    
    for(int i=0; i<m; i++){
        int bs_result = binarySearch(s-drive[i],0,n-1);
        if(bs_result == -1) total[i] = -1;
        else total[i] = drive[i] + bs_result;
    }
    int max = -2;
    for(int i=0; i<m; i++)max<total[i]?max=total[i]:max=max;
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
