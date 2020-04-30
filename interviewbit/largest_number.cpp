int iGreaterThanJ(int i, int j){
    int i_digits=10;
    int x = i;
    while (x/10){
        x=x/10;
        i_digits*=10;
    }
    int j_digits=10;
    x = j;
    while (x/10){
        x=x/10;
        j_digits*=10;
    }
    long long int ij = i * 1LL * (j_digits) + j;
    long long int ji = j * 1LL *  (i_digits) + i;
    return ij > ji;
}
string Solution::largestNumber(const vector<int> &B) {
    if (B.size()==0) return "";
    vector<int> A(B);
    sort(A.begin(), A.end(), iGreaterThanJ);
    string result;
    bool any = false;
    for (int i=0; i<A.size(); i++){
        if (A[i] != 0){
            any = true;
        }
        result.append(to_string(A[i]));
    }
    if (!any) return "0";
    else return result;
}

