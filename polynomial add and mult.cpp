#include<stdio.h>
#include<stdlib.h>
struct node{
	float coef;
	int expo;
	struct node *link;
};
struct node *start1=NULL,*start2=NULL,*start3=NULL;
node *create(node*);
node *insert(node*,float,int);

void display(node*ptr);
void poly_add(node *,node *);
void poly_mult(node *,node *);
//main function
int main(){
	int ch;
	do{
		printf("\nMENU\n1.Insert Polynomial\n2.Traverse\n3.Addition\n4.Multiplication");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("...Enter First Polynomial Iteration...\n");
 				start1=create(start1);
 				printf("...Enter Second polynomial Iteration...\n");
				start2=create(start2); 	
			break;
			case 2:
				printf("Polynomial First: ");
 				display(start1);
 				printf("Polynomial Second: ");
				display(start2);
			break;
			case 3:
				poly_add(start1, start2);
			break;
			case 4:
				poly_mult(start1, start2);
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

//function definitions
node *create(node *start){
	int i,n,ex;
	float co; 
	printf("Enter the number of terms : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
	printf("Enter coeficient for term %d : ",i);
	scanf("%f",&co); 
	printf("Enter exponent for term %d : ",i);
	scanf("%d",&ex);
	start=insert(start,co,ex); 
	}
	return start;
}

node *insert(node *start,float co,int ex){ 
	struct node *ptr,*tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->coef=co;
	tmp->expo=ex;
	if(start==NULL || ex > start->expo){
	tmp->link=start;
	start=tmp; 
	} else{
	 ptr=start;
	 while(ptr->link!=NULL && ptr->link->expo >= ex)
	 ptr=ptr->link;
	 tmp->link=ptr->link;
	 ptr->link=tmp;
	}
	return start; 
}

void display(node *ptr){
	if(ptr==NULL){
	printf("List is Empty\n");
	return;
	}
	while(ptr!=NULL){
	printf("(%.0fx^%d)", ptr->coef,ptr->expo);
	ptr=ptr->link;
	if(ptr!=NULL)
	printf(" + ");
	else
	printf("\n");
	}
}

void poly_add(node *p1,node *p2){
	while(p1!=NULL && p2!=NULL){
		if(p1->expo > p2->expo){
		start3=insert(start3,p1->coef,p1->expo);
		p1=p1->link;
		} else if(p2->expo > p1->expo) {
		 start3=insert(start3,p2->coef,p2->expo);
		 p2=p2->link;
		} else if(p1->expo==p2->expo){
		start3=insert(start3,p1->coef+p2->coef,p1->expo);
		p1=p1->link;
		p2=p2->link;
		}
	}
	while(p1!=NULL){
	start3=insert(start3,p1->coef,p1->expo);
	p1=p1->link;
	}
	while(p2!=NULL){
	start3=insert(start3,p2->coef,p2->expo);
	p2=p2->link;
	} 
	printf("...Addition of polynomial...\n");
	display(start3);
}

void poly_mult(node *p1,node *p2){
	struct node *start3;
	struct node *p2_beg = p2;
	start3=NULL;
	if(p1==NULL || p2==NULL){
	printf("List is Empty\n");
	return;
	}
	while(p1!=NULL)
	{
	p2=p2_beg;
	while(p2!=NULL)
	{
	start3=insert(start3,p1->coef*p2->coef,p1->expo+p2->expo);
	p2=p2->link;
	}
	p1=p1->link;
	} 
	printf("...Multiplication of polynomial...\n");
	display(start3);
}
