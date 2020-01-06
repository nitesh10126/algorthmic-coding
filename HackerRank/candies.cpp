#include <bits/stdc++.h>

using namespace std;
long long getCost(long n){
    return (n*(n+1))/2;
}

int getMax(int a, int b){
    return a>b?a:b;
}

int main()
{
    int n;
    cin >> n;
    vector <int> grades;
    grades.assign(n,0);
    for(int i=0; i<n; i++){
        cin >> grades[i];
    }
    if(n==1){
        cout << n;
        return 0;
    }
    int up=0, down=0, oldSlope=0, newSlope;
    long long candies=0;
    for(int i=1; i<n; i++){
        newSlope = grades[i]>grades[i-1]?1:(grades[i]<grades[i-1]?-1:0);
        if((oldSlope>0 && newSlope==0) || (oldSlope<0 && newSlope>=0)){
            candies += getCost(up) + getCost(down) + getMax(up,down);
            up=down=0;
        }
        if(newSlope<0)down++;
        if(newSlope>0)up++;
        if(newSlope==0)candies++;
        oldSlope=newSlope;
    }
    candies += getCost(up) + getCost(down) + getMax(up,down) + 1;
    cout << candies;
    return 0;
}

