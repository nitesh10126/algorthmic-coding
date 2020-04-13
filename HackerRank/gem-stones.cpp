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
    vector < vector < char > > rocks(n, vector <char>(100,'$'));
    char c;
    c=getchar();
    for(int i=0; i<n-1; i++){
        int j=0;
        while((c=getchar()) != '\n'){
            rocks[i][j++] = c;
        }
    }
    string s;
    cin >> s;
    for(int j=0; s[j]!='\0'; j++){
        rocks[n-1][j] = s[j];
    }
    vector < vector < int > > check(n, vector < int >(26,1));
    vector < int > sum(26,0);
    for(int i=0; i<n; i++){
        int j=0;
        while(rocks[i][j]!='$'){
            if(check[i][rocks[i][j] - 'a']){
                sum[rocks[i][j] - 'a']++;
                check[i][rocks[i][j] - 'a']=0;
            }
            j++;
        }
    }
    int result = 0;
    for(int i=0; i<26; i++){
        if(sum[i]==n){
            result++;
        }
    }
    cout << result;
    return 0;
}

