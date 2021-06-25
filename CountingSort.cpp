#include<stdio.h>
#include<stdlib.h>
//function declaration
void getarr(int[],int);
void putarr(int[],int);
void CountingSort(int[],int[],int);
//main function
int main(){
	int arr[20],arr2[20]={0};
	int size;
	printf("Enter the size of an array:");
	scanf("%d",&size);
	getarr(arr,size);
	CountingSort(arr,arr2,size);
	putarr(arr2,size);
	return 0;
}
//function definition
void getarr(int x[],int size){
	printf("Enter Element in array:");
	for(int i=1; i<=size; i++){
	scanf("%d",&x[i]);
	}
}
void putarr(int x[],int size) {
	printf("Your Sorted array:");
	for(int i=1; i<=size; i++){	
	printf("->%d ",x[i]);
	}	
}
void CountingSort(int x[],int y[],int size){
	int z[20];
	int k=10;
	for(int i=0; i<=k; i++)
		z[i]=0;
	for(int j=1; j<=size; j++)
		z[x[j]]=z[x[j]]+1;
	for(int i=1; i<=k; i++)
		z[i]=z[i]+z[i-1];
		
	for(int j=size; j>=1; j--){
		y[z[x[j]]]=x[j];
		z[x[j]]=z[x[j]]-1;
	}
}


