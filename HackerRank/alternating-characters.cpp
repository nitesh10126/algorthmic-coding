#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        int i = 1;
        int count = 0;
        while(s[i]!='\0'){
            int check = 1;
            while(s[i]==s[i-1]){
                check=0;
                count++;
                i++;
            }
            if(check) i++;
        }
        cout << count << endl;
    }
    return 0;
}

