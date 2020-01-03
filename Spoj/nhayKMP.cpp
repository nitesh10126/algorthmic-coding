// http://www.spoj.pl/problems/NHAY/
#include <vector>
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

void kmp_matcher(const string &needle, const string &haystack) {
	int m = needle.size();
	int n = haystack.size();
	vector<int> PI(m + 1);
  	PI[0] = -1;PI[1]=0;
	int k=0;
  	for (int q = 2; q <= m; ++q) {
		while(q>-1 && needle[k+1]!=needle[q])k=PI[k];
		if(needle[k+1]==needle[q])k=k+1;
		PI[q]=k;		
  	}
	int q=0;
	for(int i=1;i<n;i++){
		while(q>-1 && needle[k+1]!=haystack[i]) q=PI[q];
		if(needle[q+1]==haystack[i])q++;
		if(q==m){
		printf("%d\n", i - m + 1);
		q = PI[q];
		}	
	}  
}

int main(){
  int m;
  bool first = true;
  while (cin >> m) {
    if (!first) puts("");
    first = false;

    string needle; getline(cin, needle);
    getline(cin, needle);
    string haystack;
    getline(cin, haystack);
    kmp_matcher(needle, haystack);
  }
  return 0;
}
