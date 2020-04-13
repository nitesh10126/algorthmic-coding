#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    int na = a.length();
    int nb = b.length();
    vector<int> mem1; mem1.assign(26,0);
    //vector<int> mem2; mem2.assign(26,0);
    for(int i=0; i< na; i++){
        mem1[a[i]-'a']++;
    }
    for(int i=0; i< nb; i++){
        mem1[b[i]-'a']--;
    }
    int ret=0;
    for(int i=0; i<26; i++){
        ret += abs(mem1[i]);
    }
return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
