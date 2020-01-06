#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        int count = 0;
        int n_clone = n;
        while(n != 0){
            if(n%10 != 0){
            if(n_clone % (n%10) == 0)
                count++;
            }
            n=n/10;
        }
        cout << count << endl;
    }
    return 0;
}

