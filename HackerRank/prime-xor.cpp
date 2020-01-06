#include <bits/stdc++.h>

#include <string.h>

using namespace std;

int countEven(int n){
    return n/2;
}

bool isPrime(int n){
    int root = sqrt(n);
    for(int i=2; i <= root; i++){
        if(n % i == 0)return false;
    }
    return true;
}

// Complete the primeXor function below.
unsigned long long primeXor(vector<int> a) {

    int unique=0;

    vector <int> map;
    map.assign(1001,0);
    
    for(int i=0; i<a.size(); i++){
        if(map[a[i]-3500] == 0) unique++;
        map[a[i]-3500]++;
    }

    vector <bool> visited;
    visited.assign(1001, false);
    
    vector < vector <unsigned long long>> mem(2, vector <unsigned long long> (8192));
    for (int j=0; j<8192; j++)
            mem[0][j]=0;

    mem[0][0] = countEven(map[a[0]-3500]);
    mem[0][a[0]]  = map[a[0]-3500]%2==1?mem[0][0]+1:mem[0][0];

    visited[a[0]-3500] = true;
    int j=1;
    int i=1;
    int flag=1;
    while(i<unique){
        if(!visited[a[j]-3500]){
        	visited[a[j]-3500] = true;
        	int Zero= countEven(map[a[j]-3500]);
        	int Aj = map[a[j]-3500]%2==1?Zero+1:Zero;
        	mem[flag][0] = (mem[flag^1][0] + (mem[flag^1][0]*Zero) % 1000000007 + Zero + (mem[flag^1][a[j]]*Aj) %1000000007 )%1000000007;
        	for(int k=1; k<8192; k++){
		    if(k!=a[j])
        	    mem[flag][k] = (mem[flag^1][k] + (mem[flag^1][k]*Zero)%1000000007 + (mem[flag^1][k^a[j]]*Aj)%1000000007)%1000000007;
		    else
		    mem[flag][k] = (mem[flag^1][k] + (mem[flag^1][k]*Zero)%1000000007 + (mem[flag^1][0]*Aj)%1000000007 +Aj)%1000000007;
		    }
        	i++;    
            flag = flag^1;
        }
    	j++;
    }

    unsigned long long ret=0;
    for(int i=2; i<=8191; i++){
        if(isPrime(i)){
            ret = (ret + mem[(unique-1)%2][i]) % 1000000007;
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

