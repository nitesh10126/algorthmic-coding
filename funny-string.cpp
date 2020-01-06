#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        string s_reverse(s);
        reverse(s_reverse.begin(),s_reverse.end());
        int check=1;
        for(int i = 1; s[i]!='\0'; i++){
            if(abs(s[i]-s[i-1]) != abs(s_reverse[i]-s_reverse[i-1])) {
                check = 0;
                break;
            }
        }
        if(check)cout << "Funny";
        else cout << "Not Funny";
        cout << endl;
    }
    return 0;
}

