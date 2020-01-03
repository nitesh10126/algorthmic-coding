string Solution::longestPalindrome(string A) {
    int n = A.size();
    if(n==1)return A;
    if(n==2 && A[0]==A[1])return A;
    if(n==2 && A[0]!=A[1])return ""+A[0];
    vector<vector<int>> dp;
    dp.assign(n, vector<int>(n,-1));
    for(int i=0; i<n; i++)dp[i][i]=1;
    for(int stride=1; stride<n; stride++){
        for(int i=0; i+stride<n; i++){
            if(stride==1)
            {
                if(A[i]==A[i+stride])dp[i][i+stride]=2;
                else dp[i][i+stride]=1;
            }
            else
            {
                int j=i+stride;
                if(A[i]==A[j])dp[i][j]=dp[i+1][j-1]+2;
                else dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
            }
        }
    }
    vector<char> ret;
    int i=0; int j=n-1;
    while(i<=n-1 && j>=i){
        if(dp[i][j]==dp[i+1][j-1]+2){
            ret.push_back(A[j]);
            i+=1;
            j-=1;
        }
        if(dp[i][j]==1 && j==i+1){
            ret.push_back(A[j]);
            break;
        }
        if(dp[i][j]==2 && j==i+1){
            ret.push_back(A[j]);
            break;
        }
        if(dp[i][j]==dp[i][j-1]){
            j=j-1;
        }
        
        if(dp[i][j]==dp[i+1][j]){
            i+=1;
        }
    }
    string s="";
    for(int i=0; i<ret.size(); i++){
        s+=ret[i];
    }
    int x=1;
    if(dp[0][n-1]%2==0)x=0;
    for(int i=ret.size()-1-x; i>=0; i--)s+=ret[i];

    return s;
}

