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
// Complete the whatFlavors function below.
void whatFlavors(vector<int> cost, int money) {
    int n = cost.size();
    vector <int> costCopy(n);
    for(int i=0; i<n; i++){
        costCopy[i] = cost[i];
    }    
    quickSort(cost,0,n-1);
    int i=0, j=n-1;
    int sum=cost[i]+cost[j];
    while(sum!=money && i<j){
        if(sum < money)i++;
        if(sum > money)j--;
        sum = cost[i] + cost[j];
    }
    int x=-1,y=-1;
    for(int k=0; k<n; k++){
    if(costCopy[k]==cost[i] || costCopy[k]==cost[j]){
        y=x;
        x=k;
        }
    }
    int temp = max(x,y);
    x = min(x,y);
    cout << x+1 << " " << temp+1 << endl;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int money;
        cin >> money;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string cost_temp_temp;
        getline(cin, cost_temp_temp);

        vector<string> cost_temp = split_string(cost_temp_temp);

        vector<int> cost(n);

        for (int i = 0; i < n; i++) {
            int cost_item = stoi(cost_temp[i]);

            cost[i] = cost_item;
        }

        whatFlavors(cost, money);
    }

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

