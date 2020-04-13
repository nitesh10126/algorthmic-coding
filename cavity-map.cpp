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
    vector < vector < char > > map;
    map.assign(n, vector < char >(n,'$'));
    int c = getchar();
    for(int i=0; i<n-1; i++){
        char c;
        int j=0;
        while((c=getchar()) != '\n'){
            map[i][j++] = c;
        }
    }
    
    for(int j=0; j<n; j++){
        char c = getchar();
        map[n-1][j] = c;
    }
    for(int i=1; i<n-1; i++){
        for(int j=1; j<n-1; j++){
            if(map[i-1][j]<map[i][j] && map[i][j-1]<map[i][j] && map[i+1][j]<map[i][j] && map[i][j+1]<map[i][j]){
                map[i][j] = 'X';
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
                cout << map[i][j];
        }
        cout << endl;
    }
    return 0;
}

