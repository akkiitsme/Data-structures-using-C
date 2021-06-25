#include <stdio.h>
int stack[10],i,j,ch=0,n,top=-1;
//function declaration
void push();
void pop();
void show();
//main function
int main (){
	printf("Enter how many elements want to Insert: ");
	scanf("%d",&n);
	while(ch!=4) {
	printf("\nMENU");
	printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");
	printf("\nEnter your choice: ");
	scanf("%d",&ch);
	switch(ch) {
	case 1: push();
	break;
	case 2: pop();
	break;
	case 3: show();
	break;
	case 4: printf("Exiting...");
	break;
	default:printf("Please Enter valid choice ");
	};
 }
}

void push(){
	int val;
	if (top == n )
	printf("Overflow\n");
	else {
	printf("Enter the value: ");
	scanf("%d",&val);
	top = top +1;
	stack[top] = val;
	}
}
void pop(){
	if(top == -1)
	printf("Underflow\n");
	else 
	top = top -1;
	printf("Element is Deleted\n");
}
void show(){
	printf("Elements in the Stack:\n");
	for (i=top;i>=0;i--){
	printf("->%d",stack[i]);
	}
	if(top == -1){
	printf("Stack is empty\n");
	}
}
