#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
typedef struct node{
	int data;
	struct node*next;
}Queue;
struct node*front = NULL,*rear=NULL;
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
        printf("\nMENU\n1.EnQueue\n2.DeQueue\n3.Traverse\n4.Exit \n");
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
	if(front==0 && rear==0) 
	return 1;
		return 0;
}

int IsEmpty(){
   if(front==0) 
   return 1;
		return 0;
}
void EnQueue(){
	int val;
	struct node* new_n;
	new_n = (struct node*)malloc(sizeof(struct node));
	printf("Enter the element: ");
	scanf("%d", &val);
	new_n->data = val;
	new_n->next = NULL;
	if(IsFull()){
		front = rear = new_n;
	} else{
		rear->next = new_n;
		rear = new_n;
	}	
}
int DeQueue(){
	struct node *temp;
	temp = front;
	if(IsEmpty()){
		printf("Queue is Empty\n");
		return (0);
	}
	else{
		front = front->next;
		free(temp);
		printf("Element is successfully deleted!!\n");
	}
}
void Display(){
	struct node* temp;
	if(IsEmpty()){
		printf("Queue is Empty !LOL!\n");
	}
	else{
		temp = front;
		while(temp){
			printf("->%d ",temp->data);
			temp = temp->next;
		}
	}
}
