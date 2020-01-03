    /*	BENEFACT - The Benefactor
    
	Another chapter of the municipal chronicles of a well known unbelievable lordly major town (if this town is not well known to you, you might want to solve problem CSTREET first) tells us the following story:
Once upon a time the citizens of the unbelievable lordly major town decided to elect a major. At that time this was a very new idea and election campaigns were completely unknown. But of course several citizens wanted to become major and it didn't took long for them to find out, that promising nice things that never will become real tends to be useful in such a situation. One candidate to be elected as a major was Ivo sometimes called the benefactor because of his valuable gifts to the unbelievably lordly major towns citizens.
One day before the election day Ivo the benefactor made a promise to the citizens of the town. In case of his victory in the elections he would ensure that on one of the paved streets of the town street lamps would be erected and that he would pay that with his own money. As thrifty as the citizens of the unbelievable lordly major town were, they elected him and one day after the elections they presented him their decision which street should have street lamps. Of course they chose not only the longest of all streets but renamed several streets so that a very long street in the town existed.
Can you find how long this street was? To be more specific, the situation is as follows. You are presented a list of all paved streets in the unbelievable lordly major town. As you might remember from problem CSTREET in the town the streets are paved in a way that between every two points of interest in the town exactly one paved connection exists. Your task is to find the longest distance that exists between any two places of interest in the city.

Input :
The first line of input contains the number of testcases t.
The first line of each testcase contains the number of places (2 <=n<=50000) in the town. Each street is given at one line by two places (1<=a,b<=n) and the length of the street (0<=l<20000).

Output :
For each testcase output one line which contains the maximum length of the longest street in the city.
    */
    #include<iostream>
    #include<algorithm>
    #include<vector>
    #include<queue>
    #include<cstdio>
    using namespace std;
    int opt[50001];
	int one[50001];
    int visited[50001];
    int n;
    struct node
    {
        int i,d;
    };
    typedef struct node node;
    vector<node> v[50001];
    int setMax(int a,int b){
    	return a>b?a:b;
    }
    void dfs(int temp){
        int i,j,D=0;
        visited[temp]=1;
		
		if(v[temp].size()==1 && visited[v[temp][0].i]==1){
			opt[temp]=v[temp][0].d;
			one[temp]=v[temp][0].d;
			return;
		}
		for(i=0;i<v[temp].size();i++){
        	if(visited[v[temp][i].i]==0){
				dfs(v[temp][i].i);
        	}else{
				D=v[temp][i].d;
				visited[v[temp][i].i]=0;
			}
        }
		//set opt and one values for non-leave node here
		int max_opt=0,check=0;
		int one_max_first=0,one_max_second=0;
		for(i=0;i<v[temp].size();i++){
			if(visited[v[temp][i].i]){
			int index = v[temp][i].i;
			max_opt=max_opt>opt[index]?max_opt:opt[index];
			if(one_max_first<=one[index]){
				if(check)one_max_second=one_max_first;
				check=1;
				one_max_first=one[index];
			}else{
				one_max_second=one_max_second<one[index]?one[index]:one_max_second;
			}
			}else{
			visited[v[temp][i].i]=1;
			}
		}
		opt[temp]=setMax(max_opt,one_max_second+one_max_first);
		one[temp]=one_max_first+D;
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
    		    opt[i]=0;
    		    one[i]=0;
        	}
            for(i=1;i<=n-1;i++){
                    scanf("%d%d%d",&u1,&v1,&d);
                    temp.i =  v1;
                    temp.d = d;
                    v[u1].push_back(temp);
                    temp.i = u1;
                    v[v1].push_back(temp);
            }
           dfs(1);
           printf("%d\t",opt[1]);
           }
    }