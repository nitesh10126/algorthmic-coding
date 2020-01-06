#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
    getline(cin, s);
    //cout << s;
    vector < int > count(26,-1);
    
    for(int i=0; s[i]!=0; i++){
            if(s[i]>='a' && s[i]<='z')count[s[i]-'a'] = 1;
            if(s[i]>='A' && s[i]<='Z')count[s[i]-'A'] = 1;
    }
    int check=1;
    for(int i=0; i<26; i++){
        if(count[i]==-1){
            check=0;
            break;
        }
    }
    if(check==1)
    cout << "pangram";
    else
        cout << "not pangram";
    return 0;
}

