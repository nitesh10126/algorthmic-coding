#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector < char > a,b;
    a.assign(101,'$');
    b.assign(101,'$');
    int a_length, b_length;
    int k;
    int i = 0;
    char c;
    while((c=getchar()) != '\n'){
        a[i++] = c;
    }
    a_length = i;
    i=0;
    while((c=getchar()) != '\n'){
        b[i++] = c;
    }
    b_length = i;
    cin >> k;
    int equal_index=-1;
    i=0;
    while(a[i]==b[i]){
        i++;
        equal_index++;
    }
    
    int min_operations = (a_length - equal_index - 1) + (b_length - equal_index - 1);
    if(min_operations == k) cout << "Yes";
    else
        if(min_operations > k) cout << "No";
    else{
        int diff = k - min_operations;
        if(diff % 2 == 0) cout << "Yes";
        else{
            if(diff > 2*(equal_index+1)) cout << "Yes";
            else cout << "No";
        }
    }
    
    return 0;
}

