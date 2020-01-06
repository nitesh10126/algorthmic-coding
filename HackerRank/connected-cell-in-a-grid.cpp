#include <bits/stdc++.h>

using namespace std;

int markRegion(vector<vector<int>>& a, int i, int j, int n, int m, int mark){
    if(i>=n || i<0 || j>=m || j<0)return 0;
    int total=0;
    if(a[i][j]!=mark && a[i][j]==1){
        a[i][j]=mark;
    total++;
    if(i-1>=0 && j-1>=0)total+=markRegion(a,i-1,j-1,n,m,mark);
    if(i-1>=0)total+=markRegion(a,i-1,j,n,m,mark);
    if(i-1>=0 && j+1<n)total+=markRegion(a,i-1,j+1,n,m,mark);
    if(j-1>=0)total+=markRegion(a,i,j-1,n,m,mark);
    if(j+1<m)total+=markRegion(a,i,j+1,n,m,mark);
    if(i+1<n && j-1>=0)total+=markRegion(a,i+1,j-1,n,m,mark);
    if(i+1<n)total+=markRegion(a,i+1,j,n,m,mark);
    if(i+1<n && j+1<m)total+=markRegion(a,i+1,j+1,n,m,mark);
    }
    return total;
}

// Complete the connectedCell function below.
int connectedCell(vector<vector<int>> a,int n, int m){
    int mark=2;
    int ret=-1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]==1){
                int tempRet = markRegion(a,i,j,n,m,mark);
                mark++;
                ret = ret>tempRet?ret:tempRet;
            }
        }
    }
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> matrix(n);
    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = connectedCell(matrix,n,m);

    fout << result << "\n";

    fout.close();

    return 0;
}

