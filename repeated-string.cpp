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
    long long int n;
    cin >> n;
    vector < int > count_a;
    count_a.assign(100,-1);
    int countTemp=0;
    for(int i=0; s[i]!='\0'; i++){
        if(s[i] == 'a') {
            countTemp++;
        }
        count_a[i]=countTemp;
    }
    long long int result = 0;
    int s_length = s.size();
    result = count_a[s_length-1]*(n/s_length);
    if(n % s_length != 0) result = result + count_a[(n % s_length)-1];
    cout << result;
    return 0;
}

