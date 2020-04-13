#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void swap(vector < long long int >& ar, int i, int j){
    long long int temp = ar[i];
    ar[i] = ar[j];
    ar[j] = temp;
}

int partition(vector < long long int >& ar, int i, int j){
    long long int pivot = ar[j];
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

void quickSort(vector < long long int >& ar, int i,  int j ){
    //int pivot = keyboard[i];
    if(i < j){
    int pivot_rank = partition(ar,i,j);
    quickSort(ar,i,pivot_rank-1);
    quickSort(ar,pivot_rank+1, j);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        vector < vector < long long int > > matrix(n, vector < long long int >(n,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> matrix[i][j];
            }
        }
        vector < long long int > ballsInContainer(n,0);
        vector < long long int > balls(n,0);
        long long int rowSum;
        long long int colSum;
        for(int i=0; i<n; i++){
            rowSum=0;
            colSum=0;
            for(int j=0; j<n; j++){
                rowSum += matrix[i][j];
                colSum += matrix[j][i];
            }
            ballsInContainer[i] = rowSum;
            balls[i] = colSum;
        }
        quickSort(balls,0,n-1);
        quickSort(ballsInContainer,0,n-1);
        int check = 1;
        for(int i=0; i<n; i++){
            if(balls[i] != ballsInContainer[i]){
                check = 0;
                break;
            }
        }
        if(check == 1)cout << "Possible" << endl;
        else cout << "Impossible" << endl;
    }
    return 0;
}

