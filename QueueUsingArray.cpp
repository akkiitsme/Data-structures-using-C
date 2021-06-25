#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int queue_arr[MAX];
int rear = - 1,front = - 1;
//funtion Declaration
void Insert();
void Delete();
void Display();
//main function
int main(){
    int ch;
    while(1){
        printf("\nMENU\n1.Insertion\n2.Deletion\n3.Traverse\n4.Exit \n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch (ch){
            case 1: Insert();
            break;
            case 2: Delete();
            break;
            case 3: Display();
            break;
            case 4: exit(1);
            default:printf("Wrong choice \n");
        } 
    } 
}
 
void Insert(){
    int item;
    if (rear == MAX - 1)
    printf("Queue is Overflow\n");
    else{
        if (front == - 1)
        front = 0;
        printf("Enter the element: ");
        scanf("%d", &item);
        rear = rear + 1;
        queue_arr[rear] = item;
    }
}
 
void Delete(){
    if(front == - 1 || front > rear){
        printf("Queue is Underflow \n");
        return ;
    } else{
        printf("The deleted element from queue is : %d\n", queue_arr[front]);
        front = front + 1;
    }
} 
 
void Display(){
    if (front == - 1)
        printf("Queue is Empty \n");
    else {
        printf("Queue is : \n");
        for (int i = front; i <= rear; i++)
            printf("->%d ", queue_arr[i]);
       		 printf("\n");
    }
}
