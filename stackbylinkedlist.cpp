#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*link;
};
struct node*top=NULL;
void push();
void pop();
void Top();
void show();
//main function
int main(){
    int ch;
    while(1){
        printf("\n1.Push\n2.Pop\n3.Show\n4.Top\n5.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: show();
            break;
            case 4: Top();
            break;
            case 5: exit(0);
            default:printf("Wrong choice!!\n");
        } 
    } 
}
//functions
void push(){
	int val;
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
	printf("Overflow\n");
	else {
	printf("Enter the element: ");
	scanf("%d",&val);	
	temp->data=val;
	temp->link=top;
	top=temp;
	}
}
void pop(){
	struct node*del=top;
	if(top!=NULL){
		top=top->link;
		free(del);
		printf("Element is Popped!!");
	}
	else {
		printf("Stack is Underflow\n");
	}
}
void Top(){
	struct node*T=top;
	printf("Top element is %d\n",T->data);
}
void show(){
	struct node*head=top;
	printf("Elements in the stack are: \n");
	while(head!=NULL){
	printf("->%d ",head->data);
	head=head->link;	
	}
}

