/*
HORRIBLE - Horrible Queries
#tree #binary-search

World is getting more evil and it's getting tougher to get into the Evil League of Evil. Since the legendary Bad Horse has retired, now you have to correctly answer the evil questions of Dr. Horrible, who has a PhD in horribleness (but not in Computer Science). You are given an array of N elements, which are initially all 0. After that you will be given C commands. They are -

* 0 p q v - you have to add v to all numbers in the range of p to q (inclusive), where p and q are two indexes of the array.

* 1 p q - output a line containing a single integer which is the sum of all the array elements between p and q (inclusive)

 
Input

In the first line you'll be given T, number of test cases.

Each test case will start with N (N<=100 000) and C (C<=100 000). After that you'll be given C commands in the format as mentioned above. 1 <= p,q <= N and 1 <= v <= 10^7.
Output

Print the answers of the queries.
*/

#include<string.h>
#include<iostream>
#include <stdio.h>
#include <math.h>
 
using namespace std;
int getMid(int s, int e)
{
    return s + (e - s) / 2;
}
 
long long int getSumUtil(long long int *lazy,long long int *st, int ss, int se, int qs, int qe, int index)
{
    int i=qs;
    int j=qe;
	if(i>se || j<ss)return 0;
    if(lazy[index] != 0){
        st[index] += (se-ss+1)*lazy[index];
        if(ss != se){
            lazy[index*2+1]+= lazy[index];
            lazy[index*2+2]+= lazy[index];
        }
        lazy[index]=0;
    }
 
    if (qs <= ss && qe >= se)
        return st[index];
	int mid = getMid(ss, se);
    return getSumUtil(lazy,st, ss, mid, qs, qe, 2 * index + 1) + getSumUtil(lazy,st, mid + 1, se, qs, qe, 2 * index + 2);
}
void updateValueUtil(long long int *lazy,long long int *st, int ss, int se, int i,int j, long long int value,int index)
{
	
	if(i>se||j<ss)return;
	if (ss == se ){
            st[index]+= value;
            if (lazy[index]!=0){
                st[index] += lazy[index];
                lazy[index]=0;
            }
            return;
        }
    if (i <=ss && j >= se){
            lazy[2*index+1] += value;
            lazy[2*index+2] += value;
            st[index] += (value*(se-ss+1));
            return ;
        }
    else if (i <= se && j >se)
            st[index ] += (value*(se-i+1));
    else if (ss <= j && i <ss)
            st[index] += (value*(j-ss+1));
    else if (i >= ss && j <= se)
			st[index] += (value*(j-i+1));
		int mid = getMid(ss,se);
        updateValueUtil(lazy,st,ss,mid,i,j,value,index*2+1);
        updateValueUtil(lazy,st,mid+1,se,i,j,value,index*2+2);
        return;
}
long long int constructSTUtil(int arr[], int ss, int se,long long int *st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) + constructSTUtil(arr, mid + 1, se, st, si*2+2);
    return st[si];
}
 
long long int *constructST(int arr[], int n)
{
    int x = (int)(ceil(log2(n))); 
    int max_size = 2 * (int)pow(2, x) - 1; 
    long long int *st = new long long int[max_size];
    constructSTUtil(arr, 0, n - 1, st, 0);
    return st;
}
 
int main() {
 
	int t;
	cin >> t;
	while(t--){
	int n;
	cin >> n;
	int arr[n];
	int i;
        for(i=0;i<n;i++){
            arr[i]=0;
        }
	long long int *st = constructST(arr, n);
	int x = (int)(ceil(log2(n))); 
    int max_size = 2 * (int)pow(2, x) - 1; 
    long long int *lazy = new long long int[max_size];
    memset(lazy, 0, sizeof lazy);
    int c,p,q;
	long long int v;
	cin >> c;
	while(c--){
		int c1;
		cin >> c1;
		if(c1 == 0){
			cin >> p;
			cin >> q;
			cin >> v;
			int i;
			updateValueUtil(lazy,st,0,n-1,p-1,q-1,v,0);
		}
		else if(c1 == 1){
			cin >> p;
			cin >> q;
			int i;
			cout<<getSumUtil(lazy,st, 0, n - 1, p-1, q-1, 0)<<"\n";
		}
	}
	}
}