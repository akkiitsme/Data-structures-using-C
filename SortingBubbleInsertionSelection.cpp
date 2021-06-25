#include<stdio.h>
#include<stdlib.h>
//function declaration
void getarr(int[],int);
void putarr(int[],int);
void swap(int*,int*);
void Bubble(int[],int);
void Insertion(int[],int);
void Selection(int[],int);
//main function
int main(){
	int arr[10],size,ch;
	printf("Enter the size of an array:");
	scanf("%d",&size);
	while(1){
		printf("\nMenu:\n1.Bubble Sort\n2.Insertion Sort\n3.Selection Sort\n4.Heap\n 5.Exit\n");
	    printf("Enter Your Choice: ");
	    scanf("%d",&ch);
	    switch(ch){
	    	case 1: getarr(arr,size);
					Bubble(arr,size);
	    			putarr(arr,size);
	    	break;
	    	case 2:	getarr(arr,size);
					Insertion(arr,size);
	    			putarr(arr,size);
	    	break;
	    	case 3: getarr(arr,size);
					Selection(arr,size);
	    			putarr(arr,size);
	    	break;	
	    	case 4: getarr(arr,MAX);
					Heap(arr,MAX);
	    			putarr(arr,MAX);
	    	break;
	    	case 5: exit(0);	
	    	default:printf("Wrong choice!!");		
		}
	}
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
void Bubble(int arr[],int size){
	for(int i=0; i<size-1; i++){
		for(int j=0; j<size-1-i; j++){
			if(arr[j]>arr[j+1]){
				swap(&arr[j],&arr[j+1]);
			}
		}
	}	
}
void Selection(int arr[],int size){
	int mid;
	for(int i=0; i<size-1; i++){
		mid=i;
		for(int j=i+1; j<size; j++){
			if(arr[j]<arr[mid]){
				mid=j;
			swap(&arr[mid],&arr[i]);	
			}		
		}
	}	
}
void Insertion(int arr[],int size){
	int j,val;
	for(int i=1; i<size; i++){
		val=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>val){
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=val;
	}
}



