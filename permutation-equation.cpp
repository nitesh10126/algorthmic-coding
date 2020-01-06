#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main() {
    int n;
    cin >> n;
    vector < int > p_inverse;
    p_inverse.assign(n+1,-1);
    int j;
    for(int i=1; i<=n; i++){
        cin >> j;
        p_inverse[j] = i;
    }
    for(int i=1; i<=n; i++){
        cout << p_inverse[p_inverse[i]] << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

