#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


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

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector < int > ar;
    ar.assign(n+1,-1);
    vector < int > arCount;
    arCount.assign(1001,0);
    for(int i=0; i<n; i++){
        cin >> ar[i];
        arCount[ar[i]]++;
    }
    quickSort(ar,0,n-1);
    int uniqueTotal=0;
    int unique = -1;
    for(int i=0;i<n;i++){
        if(unique != ar[i]){
            uniqueTotal++;
            unique = ar[i];
        }
    }
    vector < int > arUnique;
    arUnique.assign(uniqueTotal,-1);
    int j = 0;
    for(int i=0; i<n;i++){
        while(ar[i]==ar[i+1]){
            i++;
        }
        arUnique[j] = ar[i];
        j++;
    }
    int noOfSticks = n;
    j=0;
    while(noOfSticks != 0){
        cout << noOfSticks << endl;
        noOfSticks = noOfSticks - arCount[arUnique[j]];
        j++;
    }
    return 0;
}

