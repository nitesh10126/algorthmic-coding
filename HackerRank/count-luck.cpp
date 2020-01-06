#include <bits/stdc++.h>

using namespace std;
// Complete the countLuck function below.
int countLuck(vector<vector<char>>& a, int i, int j, int n, int m, int k, bool &finished) {
    //v[i][j]=true;
    if(a[i][j]=='*'){
        finished = true;
        return k;
    }
    a[i][j]='X';
    int moveCount=0;
    bool canMoveUp = ((i-1)>-1)  && a[i-1][j]!='X';
    bool canMoveRight = ((j+1)<m)  && a[i][j+1]!='X';
    bool canMoveLeft = ((j-1)>-1)  && a[i][j-1]!='X';
    bool canMoveDown = ((i+1)<n) && a[i+1][j]!='X';
    if(canMoveUp)moveCount++;
    if(canMoveDown)moveCount++;
    if(canMoveLeft)moveCount++;
    if(canMoveRight)moveCount++;
    if(moveCount > 1)k++;
    int ans=0;
    if(canMoveUp && !finished ){
        
        ans = countLuck(a,i-1, j, n, m, k, finished);
    }
    if(canMoveDown && !finished ){
        
        ans = countLuck(a,i+1, j, n, m, k, finished);
    }
    if(canMoveLeft && !finished ){
        
        ans = countLuck(a,i, j-1, n, m, k, finished);
    }
    if(canMoveRight && !finished ){
        
        ans = countLuck(a,i, j+1, n, m, k, finished);
    }
return ans;    
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n;
        cin >> m;
        int startI,startJ;
        vector<vector<char>> a(n);
        //vector<vector<bool>> v(n);
        
        for(int i=0; i<n; i++){
            a[i].assign(m,'s');
            //v[i].assign(m,false);
        }
        for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
            if(a[i][j] == 'M'){
                startI=i;
                startJ=j;
            }
          }
       }
        int k;
        cin >> k;
        bool finished = false;
        int res = countLuck(a,startI, startJ, n, m, 0, finished);
        //cout << res << " ";
        string result;
        if(res == k)
            result = "Impressed";
        else
            result = "Oops!";

        cout << result << "\n";
    }


    return 0;
}
