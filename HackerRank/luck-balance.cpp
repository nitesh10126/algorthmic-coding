#include<bits/stdc++.h>
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
int main(){
    int n,k;
    cin >> n >> k;
    vector<int> imp_contest;
    int ret =0;
    for(int i=0; i<n; i++){
        int a,check;
        cin >> a;
        cin >> check;
        if(!check)ret+=a;
        else imp_contest.push_back(a);
    }
    quickSort(imp_contest,0,imp_contest.size()-1);
    for(int i=0; i<imp_contest.size(); i++){
        
        if(i<imp_contest.size()-k && imp_contest.size()>k)ret -= imp_contest[i];
        else ret += imp_contest[i];
    }
    cout << ret;
}
