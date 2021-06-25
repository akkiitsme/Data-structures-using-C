#include<stdio.h>
#include<stdlib.h>
//function declaration
void getarr(int[],int);
void putarr(int[],int);
void swap(int*,int*);
int Partition(int[],int,int);
void Quicksort(int[],int,int);
//main function
int main(){
	int arr[20],size;
	printf("Enter the size of an array:");
	scanf("%d",&size);
	getarr(arr,size);
	Quicksort(arr,0,size-1);
	putarr(arr,size);
	return 0;
}
//function definition
void getarr(int x[],int size){
	printf("Enter Element in array:");
	for(int i=0; i<size; i++){	
	scanf("%d",&x[i]);
	}	
}
void putarr(int x[],int size){
	printf("Your Sorted array:");
	for(int i=0; i<size; i++){	
	printf("->%d ",x[i]);
	}	
}
void swap(int*a,int*b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void Quicksort(int arr[],int beg,int end){
	if(beg<end){
		int loc=Partition(arr,beg,end);
		Quicksort(arr,beg,loc-1); 
		Quicksort(arr,loc+1,end);
	}	
}
int Partition(int arr[],int beg,int end){
	int x=arr[end];
	int i=(beg-1);
	for(int j=beg; j<=end-1; j++){
		if(arr[j]<=x){
			i++;
			swap(&arr[i],&arr[j]);
		}
	} swap(&arr[i+1],&arr[end]);
	return i+1;
}
