/*
CRSCNTRY - Cross-country
#dynamic-programming

Agness, a student of computer science, is very keen on cross­country running, and she participates in races organised every Saturday in a big park. Each of the participants obtains a route card, which specifies a sequence of checkpoints, which they need to visit in the given order. Agness is a very atractive girl, and a number of male runners have asked her for a date. She would like to choose one of them during the race. Thus she invited all her admirers to the park on Saturday and let the race decide. The winner would be the one, who scores the maximum number of points. Agnes came up with the following rules:

    a runner scores one point if he meets Agnes at the checkpoint,
    if a runner scored a point at the checkpoint, then he cannot get another point unless he and Agnes move to the next checkpoints specified in their cards.
    route specified by the card may cross the same checkpoint more than once,
    each competitor must strictly follow race instructions written on his card.

Between two consecutive meetings, the girl and the competitors may visit any number of checkpoints. The boys will be really doing their best, so you may assume, that each of them will be able to visit any number of checkpoints whilst Agnes runs between two consecutive ones on her route.
Task

Write a program which for each data set from a sequence of several data sets:

    reads in the contents of Agnes' race card and contents of race cards presented to Tom,
    computes the greatest number of times Tom is able to meet Agnes during the race,
    writes it to output.

Input

There is one integer d in the first line of the input file, 1 <= d <= 10. This is the number of data sets. The data sets follow. Each data set consists of a number of lines, with the first one specifying the route in Agnes' race card. Consecutive lines contain routes on cards presented to Tom. At least one route is presented to Tom. The route is given as a sequence of integers from interval [1, 1000] separated by single spaces. Number 0 stands for the end of the route, though when it is placed at the beginning of the line it means the end of data set. There are at least two and at most 2000 checkpoints in a race card.
Output

The i-th line of the output file should contain one integer. That integer should equal the greatest number of times Tom is able to meet with Agnes for race cards given in the i-th data set. 

*/
#include <stdio.h>
int agness[2001],tom[2001];
int memo[2001][2001];
int agness_length,tom_length;

int getMax(int a,int b){
	return a>b?a:b;
}
int getResult(){
		int i,j;
		for(i=0;i<=agness_length;i++){
			for(j=0;j<=tom_length;j++){
			if(i==0||j==0){
			memo[i][j]=0;
			continue;
			}
			if(agness[i-1]==tom[j-1])memo[i][j]=memo[i-1][j-1]+1;
			else memo[i][j]=getMax(memo[i][j-1],memo[i-1][j]);
			}
		}
		return memo[agness_length][tom_length];
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int i,result,ans,check;
		//input
		i=0;
		do{
		scanf("%d",&agness[i++]);
		}while(agness[i-1]);
		agness_length = i-1;
		//input
		i=0;
		do{
		scanf("%d",&tom[i++]);
		}while(tom[i-1]);
		tom_length = i-1;
		
		ans = getResult();
		//input
		while(1){
		scanf("%d",&check);
		if(check==0)break;
		tom[0]=check;
		i=1;
		do{
		scanf("%d",&tom[i++]);
		}while(tom[i-1]);
		tom_length = i-1;
		//store maximum
		result=getResult();
		ans=getMax(ans,result);
		}
		printf("%d\n",ans);
	}
return 0;
}