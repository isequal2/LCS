//LCS
//author @ Shivam Singh(11it87), Shalav Saket (11it86), Sheikh(11it84)
//sample output
//enter string 1   = abcd
//enter string2    =abcd
//longest common subsequence is abcd
//the number matrix
//0   0    0   0   0
//0   1    1   1   1
//0   1    2   2   2   
//0   1    2   3   3
//0   1    2   3   4
//the traversal matrix
//c stands for left upright cross.
//u stands for upright or above
//l stands for left
//
//      c    l    l     l  
//      u    c    l     l
//      u    u    c     l
//      u    u    u     c
//
// the complexity is O(m*n)=16
//
//the time complexity :0.005000
//
#include<stdio.h>
//#include<conio.h>
#include<string.h>
#include<time.h>
int m,n,c[2000][2000];
char b[2000][2000];
void print_lcs(char b[][2000],char x[],int i,int j)
{
     if(i==0 || j==0)
      	return;
     if(b[i][j]=='c')
      {
	       print_lcs(b,x,i-1,j-1);
	       printf("%c",x[i-1]);
	  }
      else if(b[i][j]=='u')
      	   print_lcs(b,x,i-1,j);
      else
    	   print_lcs(b,x,i,j-1);
}  
void lcs_length(char x[],char y[])
{
     int i,j;
     
     m=strlen(x);
     n=strlen(y);    
     for(i=0;i<=m;i++)   //initialising 0 to row 0
    	c[i][0]=0;
     for(i=0;i<=n;i++)   //initialising 0 to coloumn 0
      	c[0][i]=0;
     for(i=1;i<=m;i++)   
	 {     
	 	for(j=1;j<=n;j++)
	      {
			if(x[i-1]==y[j-1])
		 	{
		  	 	c[i][j]=c[i-1][j-1]+1; 
		  		b[i][j]='c';           //c stands for left upright cross
		  	}
		 	else if(c[i-1][j]>=c[i][j-1])
		 	{
		      	c[i][j]=c[i-1][j];
		     	b[i][j]='u';         //u stands for upright or above
		    }
			else
		 	{
		    	c[i][j]=c[i][j-1];
		     	b[i][j]='l';         //l stands for left
		    }
		  } 
	}		
     print_lcs(b,x,m,n);      
 }     
void lcs(char x[],char y[])
{
     int i,j;
     
   	 printf("\nlongest common subsequence is:\n");
     lcs_length(x,y); 
     printf("\n");
   	 printf("\n\nthe number matrix is:\n\n");
	 
     for(i=0;i<m+1;i++)
     {
		 for(j=0;j<n+1;j++)
		     {
		     	printf("%d  ",c[i][j]);
		     }
	     printf("\n");
	 }
	 printf("\n\n\n");
	 printf("the traversal matrix:\n");
	 printf("c stands for left upright cross.\n");
	 printf("u stands for upright or above\n");
	 printf("l stands for left\n");
	 for(i=0;i<m+1;i++)
     {
		 for(j=0;j<n+1;j++)
		     {
		     	printf("%c ",b[i][j]);
		     }
	     printf("\n");
	 }
	 printf("\n\nthe complexity is O(m*n)=%d\n",m*n);
	 //printf("\n");           
	 //lcs_length(y,x);					//to check if any other lcs is their or not
	 
  
 }
main()
{		   
	int l,g=1,t[2000];
	char x[2000],y[2000];     
    printf("enter first sequence:");
     gets(x);
    printf("enter second sequence:");
     gets(y); 
	clock_t start,end;
   	for(l=0;l<g;l++)
   	{	
   		
   			start=clock();
   			lcs(x,y);
   			end=clock();
   			printf("\nthe time complexity :%f\n",(float)(end-start)/CLOCKS_PER_SEC);
			   	
	}
   // getch();
}
