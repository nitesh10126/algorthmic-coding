#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the missingNumbers function below.
vector<int> missingNumbers(vector<int> a, vector<int> b) {
    int na = a.size();
    int nb = b.size();
    vector<int>aNew,bNew;
    aNew.assign(101,0);
    bNew.assign(101,0);
    int bMin=INT_MAX;
    for(int i=0; i<nb; i++){
        bMin = bMin>b[i]?b[i]:bMin;
    }
    for(int i=0; i<na; i++){
        aNew[a[i]-bMin]++;
    }
    for(int i=0; i<nb; i++){
        bNew[b[i]-bMin]++;
    }
    vector <int> ret;
    for(int i=0; i<101; i++){
        if(!bNew[i])continue;
        if(bNew[i]==a[i])continue;
        if(bNew[i]>aNew[i])ret.push_back(i+bMin);
    }
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string brr_temp_temp;
    getline(cin, brr_temp_temp);

    vector<string> brr_temp = split_string(brr_temp_temp);

    vector<int> brr(m);

    for (int i = 0; i < m; i++) {
        int brr_item = stoi(brr_temp[i]);

        brr[i] = brr_item;
    }

    vector<int> result = missingNumbers(arr, brr);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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

