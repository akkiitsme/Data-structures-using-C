#include<stdio.h>
#include<stdlib.h>
#define maxSize 10
int Queue[maxSize],front=-1,rear=-1;
//function declaration
void enQueue();
void deQueue();
void show();
//main function
int main(){
  int ch;
  while(1){
    printf("\n----MEnu----\n");
    printf(" 1.EnQueue\n 2.DeQueue\n 3.Display\n 4.Exit\n");
    scanf("%d",&ch);
    switch(ch){
      case 1 : 
	  enQueue();
      break;
      case 2 : 
	  deQueue();
      break;
      case 3 : 
	  show();
      break;
      case 4: 
	  exit(1);
      default: 
	  printf("\nWrong Choice ");
    } 
  }
	return 0;
}
//function definition
void enQueue()
{
  int data;
  if (rear==maxSize-1){
    printf("Queue is Overflow");
  }
  else{
    if(front==-1){
      front=0;
    }
    printf("Enter Element: ");
    scanf("%d",&data);
    rear++;
    Queue[rear]=data;
    printf("Element %d is inserted",data);
  }
}

void deQueue()
{
  int data;
  if (front== -1 ){
    printf("Queue is Underflow");
  } else if (front==rear){
    data=Queue[front];
    front=-1;
    rear=-1;
  } else{ 
    data=Queue[front];
    front=front+1;
  }
  printf("\nDeleted Element: %d",data);
}

void show(){
  if (front==-1){
    printf("\nQueue is Empty");
  }
  else{
    printf("\nQueue Elements are: ");
    for (int i=front;i<=rear;i++){
      printf("%d\t",Queue[i]);
    }
  }
  
}
