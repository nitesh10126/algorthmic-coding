#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

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

int binarySearch(vector<int> a, int i, int j, int n, int key){
    if(i<0 || j >= n || i>=n ||j<0) return 0;
    if(i==j && key == a[i])return 1;
    while(i<j){
        int mid = i + (j-i)/2;
        if(a[mid]>key)j=mid-1;
        else if(a[mid]<key)i=mid+1;
        else if(key == a[mid])return 1;
    }
    if(i==j && key == a[i])return 1;
    else return 0;
}

// Complete the pairs function below.
int pairs(int k, vector<int> a) {
    int n = a.size();
    quickSort(a,0,n-1);
    int ret=0;
    // linear search approach
    int i=0;
    int j=1;
    while(j<n){
        int diff = a[j]-a[i];
        if(diff==k){
            ret++;
            i++; j++;
        }
        else if(diff < k){
            j++;
        }
        else if(diff > k){
            i++;
        }
    }
    //below is binarySearch
    //if(a[0]+k <= a[n-1])ret += binarySearch(a, 1, n-1, n, a[0]+k);
    // for(int i=1; i<n-1; i++){
    //     if(a[i]-k >= 0)ret += binarySearch(a, 0, i-1, n, a[i]-k);
    //     if(a[i]+k <= a[n-1])ret += binarySearch(a, i+1, n-1, n, a[i]+k);
    // }
    // if(a[n-1]-k >= 0)ret += binarySearch(a, 0, n-2, n, a[n-1]-k);
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = pairs(k, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

