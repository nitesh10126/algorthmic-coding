/*
JULKA - Julka
#big-numbers

Julka surprised her teacher at preschool by solving the following riddle:

Klaudia and Natalia have 10 apples together, but Klaudia has two apples more than Natalia. How many apples does each of he girls have?

Julka said without thinking: Klaudia has 6 apples and Natalia 4 apples. The teacher tried to check if Julka's answer wasn't accidental and repeated the riddle every time increasing the numbers. Every time Julka answered correctly. The surprised teacher wanted to continue questioning Julka, but with big numbers she could't solve the riddle fast enough herself. Help the teacher and write a program which will give her the right answers.
Task

Write a program which

    reads from standard input the number of apples the girls have together and how many more apples Klaudia has,
    counts the number of apples belonging to Klaudia and the number of apples belonging to Natalia,
    writes the outcome to standard output

Input

Ten test cases (given one under another, you have to process all!). Every test case consists of two lines. The first line says how many apples both girls have together. The second line says how many more apples Klaudia has. Both numbers are positive integers. It is known that both girls have no more than 10100 (1 and 100 zeros) apples together. As you can see apples can be very small.
Output

For every test case your program should output two lines. The first line should contain the number of apples belonging to Klaudia. The second line should contain the number of apples belonging to Natalia. 

*/

    #include <stdio.h>
     
    int computeHalf(int a[],int aLength){
    	int aHalf[200];
    	int i = aLength-1,rmndr=0;
    	while(i >= 0){
    			a[i]=rmndr*10+a[i];
    			aHalf[i]=a[i]/2;
    			rmndr=a[i]%2;
    		i--;
    	}
    	int flag=1;
    	for(i=aLength-1;i>=0;i--){
    		if((aHalf[i] != 0)||(flag==0)){
    			flag=0;
    			printf("%d",aHalf[i]);
    		}
        }
        if(flag==1)printf("0");
        printf("\n");
    }
     
    void computeSum(int *a,int *b,int aLength,int bLength){
    	int rmndr = 0,i=aLength-1,j=bLength-1,sum[210],Isum=0;
    	while(i >= 0 && j >=0){
    		sum[Isum++]=(a[i]+b[j]+rmndr)%10;
    		rmndr=(a[i]+b[j]+rmndr)/10;
    		i--;
    		j--;
        }
    	while(i >=0){
    		sum[Isum++]=(a[i]+rmndr)%10;
    		rmndr=(a[i]+rmndr)/10;
    		i--;
    	}
    	sum[Isum++]=rmndr;
    	computeHalf(sum,Isum);
    }
     
    void computeSub(int *a,int *b,int aLength,int bLength){
        int i=aLength-1,j=bLength-1,sub[210],Isub=0;
        int d;
        while(i >= 0 && j >=0){
            d=a[i]-b[j];
            if(d < 0){
                d+=10;
                a[i-1]--;
                sub[Isub++]=d;
            }else{
            	sub[Isub++]=d;
            }
            i--;
            j--;
        }
        while(i >= 0){
            if(a[i]<0){
                a[i]+=10;
                a[i-1]--;
                sub[Isub++]=a[i];
                i--;
            }
            else{
                sub[Isub++]=a[i];
                i--;
            }
        }
       
        computeHalf(sub,Isub);
    }
     
     
    int main(void) {
    	int a[200],diff[200],i;
    	int j=0;
    	while(j!=20){
    	i=0;
    	int aLength,diffLength;
    	char c;
    	while((c=getchar())!='\n')a[i++]=c-48;
    	aLength=i;
    	i=0;
    	while((c=getchar())!='\n'){
    		if(c==EOF)break;
    		diff[i++]=c-48;
    	}
    	diffLength=i;
     
        //logic starts
        computeSum(a,diff,aLength,diffLength);
        computeSub(a,diff,aLength,diffLength);
       	j+=2;
    	}
    	printf("\n");
    	return 0;
    }