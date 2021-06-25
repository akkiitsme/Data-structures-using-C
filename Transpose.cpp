#include<stdio.h>
void getarr(int[5][5],int,int);
void putarr(int[5][5],int,int);
int trans(int[5][5],int,int);
int main()
{	
	int a[5][5];
	int row,col;
	printf("Enter the size of row:");
	scanf("%d",&row);
	printf("Enter the size column:");
	scanf("%d",&col);
	if(row&&col<5){
	printf("Enter an array:\n");
	getarr(a,row,col);
	printf("\n....BEFORE TRANSPOSE....\n");
	putarr(a,row,col);		
	printf("\n....AFTER TRANSPOSE....\n");
	trans(a,row,col);
	putarr(a,row,col);
	}
	else {
	printf("!!Oversized,Enter less than 5\n");
	}
	return 0;
}
void getarr(int x[5][5],int row,int col)
{
	int i,j;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
		printf("enter the value %d,%d :",i,j);	
		scanf("%d",&x[i][j]);
		}
	}	
}
void putarr(int x[5][5],int row,int col)
{
	int i,j;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{	
		printf("%d ",x[i][j]);
		}
		printf("\n");
	}	
}
int trans(int x[5][5],int row,int col)
{	
	int i,j;
	int temp;
	for(i=0; i<row-1; i++)
	{
		for(j=0; j<col; j++)
		{
			temp=x[i][j];
			x[i][j]=x[j][i];
			x[j][i]=temp;
		}
	}	
}
