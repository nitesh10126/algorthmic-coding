/*
NOTATRI - Not a Triangle

#binary-search

You have N (3 <= N <= 2,000) wooden sticks, which are labeled from 1 to N. The i-th stick has a length of Li (1 <= Li <= 1,000,000). Your friend has challenged you to a simple game: you will pick three sticks at random, and if your friend can form a triangle with them (degenerate triangles included), he wins; otherwise, you win. You are not sure if your friend is trying to trick you, so you would like to determine your chances of winning by computing the number of ways you could choose three sticks (regardless of order) such that it is impossible to form a triangle with them.

Input

The input file consists of multiple test cases. Each test case starts with the single integer N, followed by a line with the integers L1, ..., LN. The input is terminated with N = 0, which should not be processed.

Output

For each test case, output a single line containing the number of triples.
	
*/

#include <stdio.h>



int main(void) {



 int numberOfSticks;



 scanf("%d",&numberOfSticks);



 while(numberOfSticks){



 int mango;



 int length[numberOfSticks];



 for(mango=0;mango<numberOfSticks;mango++)scanf("%d",&length[mango]);

 

 quicksort(length,0,numberOfSticks-1);



 // Implementing binary search



 int i,j,lo,hi,mid,sumOfSticks,answer=0;



 for(i=0;i<numberOfSticks-1;i++){



  for(j=i+1;j<numberOfSticks;j++){



   



   sumOfSticks = length[i]+length[j];



   lo=j+1;



   hi=numberOfSticks-1;



   if(lo<numberOfSticks-1){



   while(lo<hi){



   mid=lo+(hi-lo)/2;



   if(length[mid]>sumOfSticks)



    hi=mid;



   else



    lo=mid+1;



   }



   }



  //printf("for %d and %d : lo = %d",length[i],length[j],lo); 



  //printf("\n");



  if(length[lo]>sumOfSticks)answer=answer+(numberOfSticks-lo);



  //printf("answer is now %d\n",answer);



  }



 }



 printf("%d\n",answer);



 scanf("%d",&numberOfSticks);



 }



 return 0;



}



void quicksort(int x[10],int first,int last){    int pivot,j,temp,i;



     if(first<last){         pivot=first;         i=first;         j=last;



         while(i<j){             while(x[i]<=x[pivot]&&i<last)                 i++;             while(x[j]>x[pivot])                 j--;             if(i<j){                 temp=x[i];                  x[i]=x[j];                  x[j]=temp;             }         }



         temp=x[pivot];         x[pivot]=x[j];         x[j]=temp;         quicksort(x,first,j-1);         quicksort(x,j+1,last);



    }}
