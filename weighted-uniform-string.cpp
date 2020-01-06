#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    string s;
    cin >> s;
    int t;
    cin >> t;
    vector < int > mem(10000001,0);
    mem[s[0]-'a'+1]=1;
    int i = 1;
    while(s[i]!='\0'){
        int sum = s[i] - 'a' + 1;
        mem[sum] = 1;
        int check = 0;
        while(s[i]==s[i-1]){
            check=1;
            sum = sum + s[i] - 'a' + 1;
            mem[sum] = 1;
            i++;
        }
        mem[sum] = 1;
        if(check==0)i++;
    }
    while(t--){
        int n;
        cin >> n;
        if(mem[n]==1)cout << "Yes";
        else cout << "No";
        cout << endl;
    }
    return 0;
}

