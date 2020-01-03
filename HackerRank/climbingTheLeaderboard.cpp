#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector < int > ar, int lo, int hi, int n ){
    while(lo < hi){
	//cout << "Hello!" << endl;
        int mid = lo + (hi - lo)/2;
        if(ar[mid] <= n)
            hi = mid;
        else
            lo = mid+1;
    }
    if(ar[lo] > n) return -1;
    
    
}
void mergeAndPrint(vector < int > s, vector < int > a, int uniqueTotal){
	//int s_size = s.size()-1;
	int s_size = uniqueTotal;
	int a_size = a.size();
	int j=0;
	int k=0;
	
	for(int i=0; i<s_size+a_size;){
		if(a[j]<s[k]){
				cout << uniqueTotal - k + 1 << endl;
				j++;
				i++;
			}
		else
		if(a[j] == s[k]){
				cout << uniqueTotal -k + 1 << endl;
				k++;j++;i++;
		}
		else{
				k++;
				i++;
		}
		
	}
}

int main() {
    int n;
    cin >> n;
    vector<int> scores(n+1);
    for(int scores_i = 0; scores_i < n; scores_i++){
       cin >> scores[scores_i];
    }
    scores[n]=-1;
    int m;
    cin >> m;
    vector<int> alice(m);
    for(int alice_i = 0; alice_i < m; alice_i++){
       cin >> alice[alice_i];
    }
    int uniqueTotal=0;
    int unique = -1;
    for(int i=0;i<n;i++){
        if(unique != scores[i]){
            uniqueTotal++;
            unique = scores[i];
        }
    }
    vector < int > scoresUnique;
    scoresUnique.assign(uniqueTotal,-1);
    int j = 0;
    for(int i=0; i<n;i++){
        while(scores[i]==scores[i+1]){
            i++;
        }
        scoresUnique[j] = scores[i];
        j++;
    }
	j=0;
	for(int i=uniqueTotal-1; i>=0; i--){
		scores[j] = scoresUnique[i];
		j++;
		
	}
	scores[uniqueTotal] = -1;
	mergeAndPrint(scores, alice, uniqueTotal);
    return 0;
}