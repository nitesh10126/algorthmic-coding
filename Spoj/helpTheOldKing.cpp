/*
IITKWPCG - Help the old King
no tags 

     Once upon a time there lived a king in a far far country. In the country, there are n cities and m roads. He was severly attacked by his enemy. The enemy damaged all the cities of King's country. As the roads between the cities had been damaged, the King wanted to repair those. So he decided to launch a tender for this.

     As King's country is a well managed country. By well managed country, we mean that it is possible to go from each city to any other city. But now as the city has been destroyed by enemies, all the roads are broken, the king will like to rebuild the roads in such a way that it is still a well manged country.
    
    Cost of repairing the road in the country is really wierd, it is not addition of costs but it is instead multiplication of those. What it means that if the king decides that he should repair 5 roads, then total cost of repairing those roads will be multiplication of all the 5 costs.

     As the King's treasure has been damaged by the attack of foreign city, he would like to spend minimum amount of money and that the will want that his country still remains well managed country. Surprisingly the company that was given tender had a rule that all the costs will be in powers of two, as they were really love with binary numbers.

     As value of the total cost can be really large. We do not want to know the actual cost, instead output number of divisors of the number.
Input

T: number of test cases (T <= 5)
n and m (n <= 10^5 && m <= 2 * 10^5)

Next m lines will have a, b, c, which denotes that cities a and b are connected with road of cost c.

(c >= 2 && c <= 10^18 && c will always be power of 2) (1 <= a <= n) and (1 <= b <= n)
Output

For each test case, output a single line containing a number as stated in the problem..
*/

#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

struct e{
	int a;
	int b;
	int cost;
};
typedef struct e Edge;

struct sub{
	int parent;
	int rank;
};
typedef struct sub Subset;

Subset subs[100001];
Edge list[200001];

//int log2(long long pow){
//	int ans = -1;
//	while(pow){
//		pow>>=1;
//		ans++;
//	}
//	return ans;
//}

int find(int e){
	if(subs[e].parent!=e) subs[e].parent = find(subs[e].parent);
	return subs[e].parent;
}

int uni(int x, int y){
	int rx = find(x),ry = find(y);
	if(subs[rx].rank<subs[ry].rank){
		subs[rx].parent = ry;
	}
	else if(subs[ry].rank<subs[rx].rank)
		subs[ry].parent = rx;
	else{
		subs[ry].parent = rx;
		subs[rx].rank++;
	}
}

bool comp(Edge a, Edge b){
	return a.cost<b.cost;
}

int main(){
	int t,n,m,i,j;
	for(scanf("%d",&t);t--;){
		scanf("%d %d",&n,&m);
		for(i=1;i<=m;i++){
			long long temp;
			scanf("%d %d ",&(list[i].a),&(list[i].b));
			scanf("%lld",&temp);
			list[i].cost = log2(temp);
		}
		for(i=1;i<=n;i++){
			subs[i].parent = i;
			subs[i].rank = 0;
		}
		sort(list+1,list+m+1,comp);
		j=0;
		i=0;
		int cost = 0;
		while(j<n-1){
			Edge e = list[i++];
			int x = find(e.a),y = find(e.b);
			if(x!=y){
				j++;
				cost += e.cost;
				uni(x,y);
			}
		}
		printf("%d\n",cost+1);
	}
	return 0;
}