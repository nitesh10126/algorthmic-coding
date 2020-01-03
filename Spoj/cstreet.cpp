/*
CSTREET - Cobbled streets
#mst

The municipal chronicals of an unbelievable lordly major town in a land far, far away tell the following story:
Once upon a time the new crowned king Günther decided to visit all towns in his kingdom. The people of the unbelievable lordly major town expected that king Günther would like to see some of the most famous buildings in their town. For the lordly citizens it seemed neccessary that all streets in the town that the king would have to use had to be cobbled with stone. Unfortunately the unbelievable lordly major town had not much money at that time as they used most of their savings to erect the highest cathedral the world had ever seen.
Roumours were afloat that the real reason for their thriftiness was not that the town treasury was empty but that many people believed that king Günther came to the throne by deceiving his father king Erwin and that in his youth he made a pact with the devil. But anyway, the citizens of the unbelievable lordly major town decided to pave only as much streets as were absolutely necessary to reach every major building.
Can you help the citizens of the unbelievable lordly major town to find out which streets should be paved?
It might be usefull to know that all major buildings are either at the end of a street or at an intersection. In addition to that you can assume that all buildings are connected by the given streets.
Input

t [number of testcases (1 <= t <= 100)]
p [price to pave one furlong of street (positive integer)]
n [number of main buildings in the town (1 <= n <= 1000)]
m [number of streets in the town (1 <= m <= 300000)]
a b c [street from building a to building b with length c (lengths are given in furlong and the buildings are numbered from 1 to n)]
Output

For each testcase output the price of the cheapest possibility to reach all main buildings in the city on paved streets. You can assume that the result will be smaller than 2^32.
*/

    // Kruskal's algortihm to find Minimum Spanning Tree of a given connected,
    // undirected and weighted graph
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
     
    // a structure to represent a weighted edge in graph
    struct Edge
    {
        int src, dest, weight;
    };
     
    // a structure to represent a connected, undirected and weighted graph
    struct Graph
    {
        // V-> Number of vertices, E-> Number of edges
        int V, E;
     
        // graph is represented as an array of edges. Since the graph is
        // undirected, the edge from src to dest is also edge from dest
        // to src. Both are counted as 1 edge here.
        struct Edge* edge;
    };
     
    // Creates a graph with V vertices and E edges
    struct Graph* createGraph(int V, int E)
    {
        struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
        graph->V = V;
        graph->E = E;
     
        graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
     
        return graph;
    }
     
    // A structure to represent a subset for union-find
    struct subset
    {
        int parent;
        int rank;
    };
     
    // A utility function to find set of an element i
    // (uses path compression technique)
    int find(struct subset subsets[], int i)
    {
        // find root and make root as parent of i (path compression)
        if (subsets[i].parent != i)
            subsets[i].parent = find(subsets, subsets[i].parent);
     
        return subsets[i].parent;
    }
     
    // A function that does union of two sets of x and y
    // (uses union by rank)
    void Union(struct subset subsets[], int x, int y)
    {
        int xroot = find(subsets, x);
        int yroot = find(subsets, y);
     
        // Attach smaller rank tree under root of high rank tree
        // (Union by Rank)
        if (subsets[xroot].rank < subsets[yroot].rank)
            subsets[xroot].parent = yroot;
        else if (subsets[xroot].rank > subsets[yroot].rank)
            subsets[yroot].parent = xroot;
     
        // If ranks are same, then make one as root and increment
        // its rank by one
        else
        {
            subsets[yroot].parent = xroot;
            subsets[xroot].rank++;
        }
    }
     
    // Compare two edges according to their weights.
    // Used in qsort() for sorting an array of edges
    int myComp(const void* a, const void* b)
    {
        struct Edge* a1 = (struct Edge*)a;
        struct Edge* b1 = (struct Edge*)b;
        return a1->weight > b1->weight;
    }
     
    // The main function to construct MST using Kruskal's algorithm
    int KruskalMST(struct Graph* graph)
    {
        int V = graph->V;
        struct Edge result[V];  // Tnis will store the resultant MST
        int e = 0;  // An index variable, used for result[]
        int i = 0;  // An index variable, used for sorted edges
     
        // Step 1:  Sort all the edges in non-decreasing order of their weight
        // If we are not allowed to change the given graph, we can create a copy of
        // array of edges
        qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
     
        // Allocate memory for creating V ssubsets
        struct subset *subsets =
            (struct subset*) malloc( V * sizeof(struct subset) );
     
        // Create V subsets with single elements
        int v;
        for ( v = 0; v < V; ++v)
        {
            subsets[v].parent = v;
            subsets[v].rank = 0;
        }
     
        // Number of edges to be taken is equal to V-1
        while (e < V - 1)
        {
            // Step 2: Pick the smallest edge. And increment the index
            // for next iteration
            struct Edge next_edge = graph->edge[i++];
     
            int x = find(subsets, next_edge.src);
            int y = find(subsets, next_edge.dest);
     
            // If including this edge does't cause cycle, include it
            // in result and increment the index of result for next edge
            if (x != y)
            {
                result[e++] = next_edge;
                Union(subsets, x, y);
            }
            // Else discard the next_edge
        }
     
        // print the contents of result[] to display the built MST
        //printf("Following are the edges in the constructed MST\n");
        int res=0;
    	for (i = 0; i < e; ++i)res+=result[i].weight;
     
        return res;
    }
     
    // Driver program to test above functions
    int main()
    {
    	int t;
    	scanf("%d",&t);
    	while(t--){
    		int p;
    		scanf("%d",&p);
    		int V ;  // Number of vertices in graph
    		int E ;  // Number of edges in graph
    		scanf("%d%d",&V,&E);
    		struct Graph* graph = createGraph(V, E);
    		int src,dest,wt,i=0;
    		while(i<E){
    			scanf("%d%d%d",&src,&dest,&wt);
    			graph->edge[i].src = src;
    			graph->edge[i].dest = dest;
    			graph->edge[i].weight = wt;
    			i++;
    		}
    	printf("%d\n",p*KruskalMST(graph));
    	}
     
        return 0;
    }