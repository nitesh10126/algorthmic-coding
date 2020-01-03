/*
GCPC11J - Time to live
#shortest-path #dfs

As you might know, most computer networks are organized in a tree-like fashion, i.e. each computer is reachable by each other computer but only over one, unique path.

The so-called Time to live (TTL) specifies after how many hops a network packet is dropped if it has not reached its destination yet. The purpose of the TTL is to avoid situations in which a packet circulates through the network caused by errors in the routing tables.

The placement of a router that connects the network to another network is optimal when the maximal needed TTL for packets that are sent from this router to any other computer within the same network is minimal. Given a network as specified above, you should calculate the maximal needed TTL in this network if you can select the computer that should be used as router.
Input

The first line of the input consists of the number of test cases c that follow (1 <= c <= 100). Each test case starts with a line specifying N, the number of computers in this network (1 < N <= 105). Computers are numbered from 0 to N-1. Then follow N-1 lines, each specifying a network connection by two numbers a and b which means that computer a is connected to computer b and vice versa, of course (0 <= a,b < N).
Output

For each test case in the input, print one line containing the optimal TTL as specified above.
*/

    #include<iostream>
    #include<algorithm>
    #include<vector>
    #include<queue>
    #include<cstdio>
	#include<cmath>
    using namespace std;
    int dist[100005];
    int visited[100005];
    int n;
    struct node
    {
        int i,d;
    };
    typedef struct node node;
    vector<node> v[100005];
    void dfs(int temp){
        int i,j;
        visited[temp]=1;
        for(i=0;i<v[temp].size();i++){
        	if(visited[v[temp][i].i]==0){
        		dist[v[temp][i].i]+=dist[temp]+v[temp][i].d;
        		dfs(v[temp][i].i);
        	}
        }
    }
    int main()
    {
     int i,j,t,u1,v1,d;
     node temp;
     scanf("%d",&t);
     while(t--){
            scanf("%d",&n);
            for(i=1;i<=n;i++)
                v[i].clear();
        	for(i=0;i<=n;i++){
        	    visited[i]=0;
    		    dist[i]=0;
        	}
            for(i=1;i<=n-1;i++){
                    scanf("%d%d",&u1,&v1);
					u1++;
					v1++;
                    temp.i =  v1;
                    temp.d = 1;
                    v[u1].push_back(temp);
                    temp.i = u1;
                    v[v1].push_back(temp);
            }
           dfs(1);
           int start = int(max_element(dist+1,dist+n+1)-dist);
           for(i=0;i<=n;i++){
        	    visited[i]=0;
    		    dist[i]=0;
           }
           dfs(start);
           int res = int(max_element(dist+1,dist+n+1)-dist);
           printf("%d\n",(int)ceil((float)dist[res]/2));
           }
    }