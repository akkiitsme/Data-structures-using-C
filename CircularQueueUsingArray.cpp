#include <stdio.h>
#include<stdlib.h>
#define SIZE 10
int CQueue[SIZE];
int front = -1, rear = -1;
//function declaration
int IsFull();
int IsEmpty();
int DeQueue();
void EnQueue();
void Display();
//main function
int main(){
    int ch;
    while(1){
        printf("\nMENU\n1.EnQueue\n2.DeQueue\n3.Display\n4.Exit \n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1: EnQueue();
            break;
            case 2: DeQueue();
            break;
            case 3: Display();
            break;
            case 4: exit(0);
            default:printf("Wrong choice!!\n");
        } 
    } 
}

int IsFull(){
	if ((front==rear + 1) || (front==0 && rear==SIZE - 1)) 
	return 1;
		return 0;
}

int IsEmpty(){
   if(front== -1) 
   return 1;
		return 0;
}

void EnQueue(){
	int element;
	if(IsFull())
	printf("\n Queue is full!! \n");
	else {
		if (front== -1) 
		front=0;
		printf("Enter the element: ");
		scanf("%d", &element);
	    rear = (rear + 1) % SIZE;
	    CQueue[rear] = element;
	    printf("\nElement has Inserted -> %d",element);
	}
}

int DeQueue(){
  int element;
  if (IsEmpty()) {
    printf("\n Queue is empty !! \n");
    return (-1);
  } else {
    element=CQueue[front];
    if (front==rear) {
      front = -1;
      rear = -1;
    } 
    else {
      front= (front + 1) % SIZE;
    }
    printf("\nDeleted element -> %d \n", element);
    return(element);
  }
}

void Display() {
  if (IsEmpty())
    printf(" \n Empty Queue\n");
  else {
  	printf("\n Front -> %d ",front);
    printf("\n Items -> ");
    int i;
    for(i=front; i!=rear; i=(i+1)%SIZE) {
      printf("%d ",CQueue[i]);
    }
    printf("%d ",CQueue[i]);
    printf("\n Rear -> %d \n",rear);
  }
}


