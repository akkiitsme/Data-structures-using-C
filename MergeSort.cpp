#include<stdio.h>
#include<stdlib.h>
//function declaration
void getarr(int[],int);
void putarr(int[],int);
void Merge(int[],int,int,int);
void Mergesort(int[],int,int);
//main function
int main(){
	int arr[20],size;
	printf("Enter the size of an array:");
	scanf("%d",&size);
	getarr(arr,size);
	Mergesort(arr,0,size-1);
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
void Mergesort(int arr[],int beg,int end){
	if(beg<end){
		int mid=(beg+end)/2;
		Mergesort(arr,beg,mid); //left
		Mergesort(arr,mid+1,end); //right
		Merge(arr,beg,mid,end); //merging two sorted sub arrays
	}	
}
void Merge(int arr[],int beg,int mid,int end){
	int temp[20];
	int i=beg; 
	int j=mid+1; 
	int k=0;
	while(i<=mid && j<=end){ 
		if(arr[i] < arr[j])
		temp[k++]=arr[i++];
		else
		temp[k++]=arr[j++];
	}
	while(i<=mid) 
	temp[k++]=arr[i++];
	while(j<=end) 
	temp[k++]=arr[j++];
	for(i=beg,j=0;i<=end;i++,j++) 
	arr[i]=temp[j];
}

