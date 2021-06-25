#include<stdio.h>
#include<stdlib.h>
int arr[5],front=0,rear=0;
//functions
void insert(int x){
	if(rear==5){
		printf("Queue is Overflow\n");
		exit(1);
	} else {
		arr[rear++]=x;
	}
}
void del(){
	if(front==-1){
		printf("\nQueue is Underflow\n");
		exit(1);
	} else {
		arr[front++];
	}
}
void show(){
	printf("\nElements in the Queue are:\n");
	for(int i=front; i<rear; i++){
		printf("%d\t",arr[i]);
	}
}
//main function
int main(){
	insert(5);
	insert(15);
	insert(20);
	insert(30);
	insert(50);
	show();
	printf("\nAfter Deletion");
	del();
	show();
	return 0;
}

