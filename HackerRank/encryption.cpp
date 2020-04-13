#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string message;
    cin >> message;
    int length = message.size();
    int lower = floor(sqrt(length));
    int upper = ceil(sqrt(length));
    if(lower*upper < length) lower++;
    vector < char > messageAppended(lower*upper+upper+1, '$');
    int i;
    for(i=0; i<length; i++){
        messageAppended[i]=message[i];
    }
    for(i=0; i<upper; i++){
        int j=i;
        while(messageAppended[j] != '$'){
            cout << messageAppended[j];
            j += upper;
        }
        cout << " ";
    }
    return 0;
}

