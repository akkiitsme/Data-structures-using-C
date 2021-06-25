//program for addition of polynomials using linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct link{
	int coff;
	int pow;
	struct link*next;
}poly;

void create_poly(poly**);
void display_poly(poly*);
void add_poly(poly**,poly*,poly*);

//main function
int main()
{
	int ch;
	do{
		poly*poly1,*poly2,*poly3;
		
		printf("Create first expression");
		create_poly(&poly1);
		printf("\nStored the first expression");
		display_poly(poly1);
		printf("\nCreate second expression");
		create_poly(&poly2);
		printf("\nStored the second expression");
		display_poly(poly2);
		
		//addition of polynomials
		add_poly(&poly3,poly1,poly2);
		display_poly(poly3);

		printf("\nAdd two more expression ?(Y/N):");
		fflush(stdin);
		ch=getchar();		
	}while(ch == 'Y' || ch == 'y');
	return 0;
}

//function defnition

void create_poly(poly**node){
	int flag;
	int coff,pow;
	poly*temp;
	temp=(poly*)malloc(sizeof(poly));
	*node=temp;
	do{
		printf("\nEnter the coefficient:");
		scanf("%d",&coff);
		temp->coff=coff;
		printf("Enter the power:");
		scanf("%d",&pow);
		temp->pow=pow;
		temp->next=NULL;
		printf("\nContinue adding more terms to polynomial?(Y=1/N=0):");
		scanf("%d",&flag);
		printf("FLAG:%d",flag);
		if(flag){
			temp->next=(poly*)malloc(sizeof(poly));
			temp=temp->next;
			temp->next=NULL;
		}
	}while(flag);
}

void display_poly(poly*node){
	printf("\nThe polynomial expression is:\n");
	while(node!=NULL){
		printf("%dx^%d",node->coff,node->pow);
		node=node->next;
		if(node!=NULL)
		printf("+");
	}
}

void add_poly(poly**res,poly*poly1,poly*poly2){
	poly*temp;
	temp=(poly*)malloc(sizeof(poly));
	temp->next=NULL;
	*res=temp;
	
	while(poly1&&poly2){
		if(poly1->pow > poly2->pow)
		{
			temp->pow=poly1->pow;
			temp->coff=poly1->coff;
			poly1=poly1->next;
		}
		else if(poly1->pow < poly2->pow)
		{
			temp->pow=poly2->pow;
			temp->coff=poly2->coff;
			poly2=poly2->next;
		}
		else{
			temp->pow=poly1->pow;
			temp->coff=poly1->coff+poly2->coff;
			poly1=poly1->next;
			poly2=poly2->next;
		}
		if(poly1&&poly2)
		{
			temp->next=(poly*)malloc(sizeof(poly));
			temp=temp->next;
			temp->next=NULL;
		}	
	}
	while(poly1||poly2)
	{
		temp->next=(poly*)malloc(sizeof(poly));
		temp=temp->next;
		temp->next=NULL;
		
		if(poly1)
		{
			temp->pow=poly1->pow;
			temp->coff=poly1->coff;
			poly1=poly1->next;
		}
		if(poly2)
		{
			temp->pow=poly2->pow;
			temp->coff=poly2->coff;
			poly2=poly2->next;
		}
	}
	printf("\nAddition complete\n");
}


