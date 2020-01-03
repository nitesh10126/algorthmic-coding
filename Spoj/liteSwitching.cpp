/*
LITE - Light Switching
#tree


Farmer John tries to keep the cows sharp by letting them play with intellectual toys. One of the larger toys is the lights in the barn.  Each of the N (2 <= N <= 100,000) cow stalls conveniently numbered 1..N has a colorful light above it.

At the beginning of the evening, all the lights are off. The cows control the lights with a set of N pushbutton switches that toggle the lights; pushing switch i changes the state of light i from off to on or from on to off.

The cows read and execute a list of M (1 <= M <= 100,000) operations expressed as one of two integers (0 <= operation <= 1).

The first kind of operation (denoted by a 0 command) includes two subsequent integers S_i and E_i (1 <= S_i <= E_i <= N) that indicate a starting switch and ending switch. They execute the operation by pushing each pushbutton from S_i through E_i inclusive exactly once.

The second kind of operation (denoted by a 1 command) asks the cows to count how many lights are on in the range given by two integers S_i and E_i (1 <= S_i <= E_i <= N) which specify the inclusive range in which the cows should count the number of lights that are on.

Help FJ ensure the cows are getting the correct answer by processing the list and producing the proper counts.
Input


Line 1: Two space-separated integers: N and M
Lines 2..M+1: Each line represents an operation with three space-separated integers: operation, S_i, and E_i
Output

Lines 1..number of queries: For each output query, print the count as an integer by itself on a single line.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int k,*lp,*tp;
 
   	int range_query(int index,int ss,int se,int l,int r){
   		if(l>se || r<ss || se<ss)return 0;
   		if(lp[index]){
   			tp[index]=(se-ss+1)-tp[index];
   			lp[index]=0;
            if(ss<se){
            lp[index*2]= !lp[index*2];
    		lp[index*2+1]= !lp[index*2+1];
            }
   		}
   		if(ss>=l && se<=r)return tp[index];
   		int mid = ss+((se-ss)>>1);
   		return range_query(index*2,ss,mid,l,r)+range_query(index*2+1,mid+1,se,l,r);
   	}
    void updateTree(int index,int ss,int se,int l,int r){
 
    	if(lp[index]){
   			tp[index]=(se-ss+1)-tp[index];
   			lp[index]=0;
            if(ss<se){
            	lp[index*2]=!lp[index*2];
    			lp[index*2+1]=!lp[index*2+1];
            }
        }
        if(l>se || r<ss || se<ss)return;
    	if(l<=ss && r>=se){
    		tp[index]=(se-ss+1)-tp[index];
    		if(ss<se){
    			lp[index*2]= !lp[index*2];
    			lp[index*2+1]= !lp[index*2+1];
    		}
    		return;
    	}
		int mid = ss+((se-ss)>>1);
        updateTree(index*2,ss,mid,l,r);
        updateTree(index*2+1,mid+1,se,l,r);
        if(ss<se)tp[index]=tp[2*index]+tp[2*index+1];
    }
 
int main() {
	int n,m,c,l,r;
	scanf("%d %d",&n,&m);
	k = ceil(log(n)/log(2));
    int pos=1<<k;
    int tree_size = pos<<1;
    int tree[tree_size];
    int lazy[tree_size];//int c;
    for(c=0;c<tree_size;c++){
    	tree[c]=lazy[c]=0;
    }
    tp=tree;lp=lazy;
    while(m--){
    	scanf("%d%d%d",&c,&l,&r);
    	if(c==0)updateTree(1,1,pos,l,r);
    	else if(c==1) printf("%d\n",range_query(1,1,pos,l,r));
    }
 return 0;
}