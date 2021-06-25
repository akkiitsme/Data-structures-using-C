#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int heapsize=MAX;
//function declaration
void getarr(int[],int);
void putarr(int[],int);
void swap(int*,int*);
void maxheap(int[],int);
void heapify(int[],int);
void HeapSort(int[],int);
//main function
int main(){
	int arr[MAX];
		getarr(arr,MAX);
		HeapSort(arr,MAX);
	    putarr(arr,MAX);
}
//function definition
void getarr(int x[],int size){
	printf("Enter Element in array:");
	for(int i=1; i<=size; i++){	
	scanf("%d",&x[i]);
	}	
}
void putarr(int x[],int size){
	printf("Your Sorted array:");
	for(int i=1; i<=size; i++){	
	printf("->%d ",x[i]);
	}	
}
void swap(int*a,int*b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void maxheap(int arr[],int size){
	for(int i=size/2; i>=1; i--){
		heapify(arr,i);
	}
}
void heapify(int arr[],int i){
	int largest;
	int left=2*i;
	int right=2*i+1;
	if(left<=heapsize && arr[left]>arr[i]){
		largest=left;
	}
	else{
		largest=i;
	}
	if(right<=heapsize && arr[right]>arr[largest]){
		largest=right;
	}
	if(largest !=i){
		swap(&arr[i],&arr[largest]);
		heapify(arr,largest);
	}
}

void HeapSort(int arr[],int size){
	maxheap(arr,size);
	for(int i=size; i>=2; i--){
		swap(&arr[1],&arr[i]);
		heapsize=heapsize-1;
		heapify(arr,1);
	}
}
