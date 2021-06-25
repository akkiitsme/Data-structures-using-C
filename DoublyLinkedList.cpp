#include<stdio.h>
#include<stdlib.h>
typedef struct DoublyList{
	int info;
	struct DoublyList *pre;
	struct DoublyList *next;
}node;
//function Declaration
void Create_DoublyList(node **,node **);
void Traversing(node *);
void Insert_Beg(node **,node **,int);
void Insert_End(node **,node**,int);
void Insert_After(node *,node **,int);
void Insert_Before(node **,node *,int);
void Delete_Beg(node **,node **);
void Delete_End(node **,node **);
void Reverse(node*);
void Search(node*);
//Main Function
int main(){
	node *head,*tail;
	int ch,data,element;
	Create_DoublyList(&head,&tail);
	do{
		printf("\n1.Insert At Begining\n2.Insert At End\n3.Insert After Element\n4.Insert Before Element");
		printf("\n5.Delete From Begining\n6.Delete From End");
		printf("\n7.Traversing\n8.Reverse List\n9.Searching");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("Enter the Element:");
					scanf("%d",&data);
					Insert_Beg(&head,&tail,data);
					break;
			case 2: printf("Enter the Element:");
					scanf("%d",&data);
					Insert_End(&head,&tail,data);
					break;
			case 3: printf("Enter that Element After You want to Insert:");
					scanf("%d",&element);
					Insert_After(head,&tail,element);
					break;
			case 4: printf("Enter that Element Before You want to Insert:");
					scanf("%d",&element);
					Insert_Before(&head,tail,element);
					break;
			case 5: Delete_Beg(&head,&tail);
					printf("Element Deleted From Begining");
					break;
			case 6:	Delete_End(&head,&tail);
					printf("Element Deleted From End");
					break;
			case 7: Traversing(head);
					break;
			case 8: Reverse(tail);
					break;
			case 9: Search(head);
					break;		
			default : 
			printf("Wrong Choice");
		} 
	printf("\nEnter Y to continue and N to stop: ");
    fflush(stdin);
    ch = getchar();
	} while (ch == 'Y' || ch == 'y');
	return 0;
}
//Function Definitions
void Create_DoublyList(node **HEAD,node **TAIL){
	*HEAD=NULL;
	*TAIL=NULL;
}
void Traversing(node *HEAD){
	while(HEAD!=NULL){
		printf("%d\t",HEAD->info);
		HEAD=HEAD->next;
	}
}
void Insert_Beg(node **HEAD,node **TAIL,int data){
	node *Num;
	Num = (node *)malloc(sizeof(node));
	Num->next=NULL;
	Num->pre=NULL;
	Num->info=data;
	if(*HEAD==NULL){
		*HEAD = Num;
		*TAIL = Num;
	} else{
		Num->next=*HEAD;
		(*HEAD)->pre = Num;
		*HEAD=Num;
	}
}
void Insert_End(node **HEAD,node **TAIL,int data){
	node *Num;
	Num = (node *)malloc(sizeof(node));
	Num->next=NULL;
	Num->pre=NULL;
	Num->info=data;
	if(*HEAD==NULL){
		*HEAD = Num;
		*TAIL = Num;
	} else{
		(*TAIL)->next=Num;
		Num->pre=*TAIL;
		*TAIL=Num;
	}
}
void Insert_After(node *HEAD,node **TAIL,int element){
	int data;
	node *loc,*ptr;
	loc = HEAD;
	printf("Now Enter the Element:");
	scanf("%d",&data);
	while(loc !=NULL){
		if(loc->info == element){
			break;
		}
		loc=loc->next;
	}
	if(loc != NULL){
		ptr=(node *)malloc(sizeof(node));
		ptr->info=data;
		if(loc->next!=NULL){
			ptr->next = loc->next;
			ptr->pre=loc;
			(loc->next)->pre=ptr;
			loc->next=ptr;
		} else{
			ptr->pre =loc;
			ptr->next = NULL;
			loc->next = ptr;
			*TAIL=ptr;
		}
	} else{
		printf("Element not found");
	}

}
void Insert_Before(node **HEAD,node *TAIL,int element){
	int data;
	node *loc,*ptr;
	loc = *HEAD;
	printf("Now Enter the Element:");
	scanf("%d",&data);
	while(loc != NULL){
		if(loc->info==element){
			break;
		}
		loc=loc->next;
	}
	if(loc!=NULL){
		ptr=(node *)malloc(sizeof(node));
		ptr->info=data;
		if(loc->pre != NULL){
			ptr->pre = loc->pre;
			ptr->next = loc;
			(loc->pre)->next = ptr;
			loc->pre = ptr;
		}
		else{
			ptr->pre = NULL;
			ptr->next=*HEAD;
			loc->pre = ptr;
			*HEAD = ptr;
		}
	}
	else{
		printf("Element not found");
	}
}
void Delete_Beg(node **HEAD,node **TAIL){
	node *loc,*temp;
	if(*HEAD==NULL){
		printf("List is Empty");
	}
	else if(*HEAD == *TAIL){
		free(*HEAD);
		*HEAD=*TAIL=NULL;
	}
	else{
		loc=*HEAD;
		temp=(*HEAD)->next;
		free(loc);
		temp->pre = NULL;
		*HEAD=temp;
	}
}
void Delete_End(node **HEAD,node **TAIL){
	node *loc,*temp;
	if(*HEAD==NULL){
		printf("List is Empty");
	}
	else if(*HEAD == *TAIL){
		free(*HEAD);
		*HEAD=*TAIL=NULL;
	}
	else{
		loc = *TAIL;
		temp = loc->pre;
		*TAIL = temp;
		temp->next = NULL;
		free(loc);
	}
}
void Reverse(node *TAIL){
	while(TAIL != NULL){
		printf("%d\t",TAIL->info);
		TAIL=TAIL->pre;
	}
}
void Search(node*HEAD){
	struct DoublyList *temp=HEAD;
	int n,i=1,f=0;
	printf("Enter Number to Search: ");
	scanf("%d",&n);
	while(temp->next!=NULL){
	    if(temp->info==n){
	      printf("Item is at %d position",i);
	      f=1;
	    }
	    temp=temp->next;
	    i++;
	}
	if(f==0){
	    printf("No Element Found");
	}
}
