#include<stdio.h>
#include<stdlib.h>
//function declaration
void getarr(int[],int);
void putarr(int[],int);
void Linear(int[],int);
void Binary(int[],int);
//main function
int main(){
	int arr[10],size,ch;
	printf("Enter the size of an array:");
	scanf("%d",&size);
	while(1){
		printf("\nMenu:\n1.Insert\n2.Traverse\n3.Linear search\n4.Binary search\n5.Exit\n");
	    printf("Enter Your Choice: ");
	    scanf("%d",&ch);
	    switch(ch){
	    	case 1: getarr(arr,size);
	    	break;
	    	case 2: putarr(arr,size);
	    	break;
	    	case 3: Linear(arr,size);
	    	break;
	    	case 4:	Binary(arr,size);
	    	break;
	    	case 5: exit(0);	
	    	default:printf("Wrong choice!!");		
		}
	}
	return 0;
}
//functions
void getarr(int x[],int size){
	printf("Enter Element in array:");
	for(int i=0; i<size; i++){	
	scanf("%d",&x[i]);
	}	
}
void putarr(int x[],int size){
	printf("Your Entered array:");
	for(int i=0; i<size; i++){	
	printf("->%d ",x[i]);
	}	
}
void Linear(int arr[],int size){
	int i,flag=0,key;
	printf("Enter element to search:");
	scanf("%d",&key);
	for(i=0; i<size; i++){
		if(key==arr[i]){
		printf("Element found at %d position",i+1);
		flag=1;
		break;	
		} 
	}
	if(flag==0){
      printf("No Element Found");
    }
}
void Binary(int arr[],int size){
	int i,key,f=0;
	printf("Enter element to search:");
	scanf("%d",&key);
    while(f<=size){
		i=(f+size)/2;
		if(arr[i]==key){
        printf("Element Found at %d Position\n",i+1);
        break;
		} 
		else if (arr[i]<key)
        	f=i+1;    
      	else
        	size=i-1;
   }
   if (f>size)
    printf("%d Element Not Found",key);
}

