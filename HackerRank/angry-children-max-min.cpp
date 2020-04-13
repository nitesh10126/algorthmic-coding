#include <bits/stdc++.h>

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
// Complete the maxMin function below.
int maxMin(int k, vector<int> a) {
    int n = a.size();
    quickSort(a,0, n-1);
    int diff;
    int ret=INT_MAX;
    for(int i=0; i<=n-k; i++){
        diff = a[i+k-1] - a[i];
        ret = ret>diff?diff:ret;
    }
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    int result = maxMin(k, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

