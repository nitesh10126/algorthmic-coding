/*
FREQUENT - Frequent values
no tags 

You are given a sequence of n integers a1 , a2 , ... , an in non-decreasing order. In addition to that, you are given several queries consisting of indices i and j (1 <= i <= j <= n). For each query, determine the most frequent value among the integers ai , ... , aj.
Input Specification

The input consists of several test cases. Each test case starts with a line containing two integers n and q (1 <= n, q <= 100000). The next line contains n integers a1 , ... , an (-100000 <= ai <= 100000, for each i ? {1, ..., n}) separated by spaces. You can assume that for each i ? {1, ..., n-1}: ai <= ai+1. The following q lines contain one query each, consisting of two integers i and j (1 <= i <= j <= n), which indicate the boundary indices for the query.

The last test case is followed by a line containing a single 0.
Output Specification

For each query, print one line with one integer: The number of occurrences of the most frequent value within the given range. 
*/

#include <iostream>
    #include <bits/stdc++.h>
    using namespace std;
    #define INT -1000000;
    int k;
    int max(int i,int j){
    	return i>j?i:j;
    	}
    struct node
    {
    	int result,l,lc,r,rc; //l=left,r=right,lc=leftcount,rc=rightcount
    	void merge(node a, node b)
    	{
    		if(((a.r==-1000000) && (a.l==-1000000)) || ((b.r==-1000000) && (b.l==-1000000))){
                if((a.r==-1000000) && (a.l==-1000000)){
                    l=b.l;
                    r=b.r;
                    lc=b.lc;
                    rc=b.rc;
                    result=b.result;
                }
           		else if((b.r==-1000000) && (b.l==-1000000)){
                	l=a.l;
                	r=a.r;
                	lc=a.lc;
                	rc=a.rc;
                	result=a.result;
                }
            }else{
                if(a.r==b.l){
    			    int temp;
    			    temp = a.rc+b.lc;
    			    l=a.l;
    			    if(a.l==a.r){
    				    lc=temp;
    			    }else{
    				    lc=a.lc;
    			    }
    			    r=b.r;
    			    if(b.l==b.r){
    				    rc=temp;
    			    }else{
    				    rc=b.rc;
    			    }
    			result = max(temp,max(a.result,b.result));
    		    }
                else
                {
    			result = a.result>b.result?a.result:b.result;
    			l=a.l;
    			lc=a.lc;
    			r=b.r;
    			rc=b.rc;
    		    }
		}
    	}
    	node()
    	{
    		l=r=INT;
            result=lc=rc=0;
    	}
    	node(int temp)
    	{
    		l=r=temp;
    		result=lc=rc=1;
    	}
 
    } *tp;
    
    void update(int pos)
    {
        pos>>=1;
        while(pos!=0)
        {
            tp[pos].merge(tp[pos*2],tp[pos*2 + 1]);
            pos>>=1;
        }
    }
 
    node range_query(int root , int left_most , int right_most , int l ,int r)
    {
        if( l <= left_most && r >= right_most )
            return tp[root];
 
        int l_child = (root<<1) , r_child = l_child + 1 , mid = (left_most + right_most )>>1 ;
 
        node l_node = node() , r_node = node();
 
        if(l <= mid)
            l_node = range_query(l_child , left_most , mid , l , r);
        if(r > mid)
            r_node = range_query(r_child , mid + 1 , right_most, l , r);
        node temp = node();
        temp.merge(l_node,r_node);
 
        return temp;
    }
 
    int main() {
    	while(1){
    		int n,temp,l,r,q;
    		scanf("%d",&n);
    		if(n==0)break;
    		scanf("%d",&q);
    		//printf("%d\n",q);
            k = ceil(log(n)/log(2));
    		int pos=1<<k;
    		int tree_size = pos<<1;
    		node tree[tree_size];
    		tp=tree;
    		for(int i=0;i<n;i++){
    			scanf("%d",&temp);
    			tree[pos+i]=node(temp);
    			update(pos+i);
    		}
    		while(q--){
    			scanf("%d",&l);
    			scanf("%d",&r);
    			printf("%d\n",(range_query(1,1,pos,l,r)).result);	
    		}
    	}
    	return 0;
    }