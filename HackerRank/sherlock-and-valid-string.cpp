#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    int ns = s.length();
    vector<int> mem; mem.assign(26,0);
    for(int i=0; i<ns; i++)
    {
        //cout << s[i]-'a' << " "; 
        mem[int(s[i]-'a')]++;
    }
    //cout << endl;
    int min=INT_MAX;
    int max =-1;
    for(int i=0; i<26 ; i++){//&& mem[i]!=0
    //    cout << mem[i] << " ";
        if(0 != mem[i])
            min = mem[i]<min?mem[i]:min;
        max = mem[i]>max?mem[i]:max;
        
    }
    //cout << endl;
    //cout << min << " " << max;
    int distinct = 0;
    int minCount = 0, maxT=0;
    for(int i=0; i<26 && mem[i]!=0; i++){
        distinct++;
        if(min == mem[i])minCount++;
    }
    int check=1;
    if(min != 1){
    for(int i=0; i<26 && mem[i]!=0; i++){
        if(min == mem[i]) continue;
        if(min+1 < mem[i]) return "NO";
        if(min+1 == mem[i] && check){
            check = 0;
        }else{
            return "NO";
        }
    }
    return "YES";
    }else{
        if(minCount > 1){
            return "NO";
        }else{
            //check=0;
            for(int i=0; i<26 && mem[i]!=0; i++){
                if(1 != mem[i] && max != mem[i]) return "NO";
            }  
        return "YES";    
        } 
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);
    cout << s << endl;
    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
