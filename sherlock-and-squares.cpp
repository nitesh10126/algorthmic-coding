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
    for(int i=0; i<t; i++){
        int a,b;
        int count = 0;
        cin >> a >> b;
        int j=a;
        double sqrt_j;
        for(; j<=b; j++){
            sqrt_j = sqrt(j);
            int sqrt_j_round = sqrt_j;
            if(sqrt_j_round == sqrt_j) {
                count++;
                break;
            }
        }
        sqrt_j = sqrt_j + 1;
        while(sqrt_j*sqrt_j <= b){
            count++;
            sqrt_j++;
        }
        cout << count << endl;
    }
    return 0;
}

