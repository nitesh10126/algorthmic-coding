#include <bits/stdc++.h>

#include <string.h>

using namespace std;

int countEven(int n){
    return n/2;
}

bool isPrime(int n){
    
    int root = sqrt(n);
    if(n%2==0)return false;
    else{
    for(int i=3; i <= root; i+=2){
        if(n % i == 0)return false;
    }
    }
    return true;
}

// Complete the primeXor function below.
long long primeXor(vector<int> a) {

    int unique=0;

    vector <int> map;
    map.assign(1001,0);
    for(int i=0; i<a.size(); i++){
        if(map[a[i]-3500] == 0) unique++;
        map[a[i]-3500]++;
    }
    vector <bool> visited;
    visited.assign(1001, false);
    
    vector < vector <int>> mem(unique, vector <int> (8192));
    for(int i=0; i<8192; i++) mem[0][i]=0;
    mem[0][0] = countEven(map[a[0]-3500]);
    mem[0][a[0]]  = map[a[0]-3500]%2==1?mem[0][0]+1:mem[0][0];
    visited[a[0]-3500] = true;
    int j=1;
    int i=1;
    while(i<unique){
        if(!visited[a[j]-3500]){
        visited[a[j]-3500] = true;
        int Zero= countEven(map[a[j]-3500]);
        int Aj = Zero+1;
        mem[i][0] = (mem[i-1][0] + (mem[i-1][0]*Zero) % 1000000007 + Zero + (mem[i-1][a[j]]*Aj) %1000000007 )%1000000007;
        for(int k=1; k<8192; k++){
            mem[i][k] = (mem[i-1][k] + (mem[i-1][k]*Zero)%1000000007 + (mem[i-1][k^a[j]]*Aj)%1000000007)%1000000007;
        }
        i++;    
        }
    	j++;
    }
    for(int i=2; i<=8191; i++){
        long long ret=0;
        if(isPrime(i)){
            ret = (ret + mem[unique-1][i]) % 1000000007;
        }
    }
    return ret;
}

int main()
{
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        vector <int> a;
        a.assign(n, -1);

        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        cout << primeXor(a) << endl;
    }
    return 0;
}

