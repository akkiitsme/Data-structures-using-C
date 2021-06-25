#include<stdio.h>
#include<stdlib.h>
struct Node
{
  int data;
  struct Node *next;
};
struct Node *start = NULL;
//function declaration
void Traversal();
void Insert_Beg();
void Insert_nthPosition();
void Insert_End();
void Delete_beg();
void Delete_End();
void Search();
//main function
int main()
{
  char ch;
  int n;
  do
  {
    printf("Menu:\n1.Traversal\n2.Insert At Beginning\n3.Insert At nth Position\n");
	printf("4.Insert at End\n5.Delete from Beg\n6.Delete from End\n7.Search in list\n");
    printf("Enter Choice: ");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
      Traversal();
      break;
    case 2:
      Insert_Beg();
      break;
    case 3:
      Insert_nthPosition();
      break;
    case 4:
      Insert_End();
      break;
    case 5:
      Delete_beg();
      break;
    case 6:
      Delete_End();
      break;
    case 7:
	  Search();
	  break;	  
    default:
      printf("Wrong Input");
    }
    printf("\nEnter Y to continue and N to stop: ");
    fflush(stdin);
    ch = getchar();
  } while (ch == 'Y' || ch == 'y');
  return 0;
}

void Traversal()
{
  if (start == NULL)
  {
    printf("No item");
  }
  else
  {
    printf("....Displaying the List.... \n");
    struct Node *temp;
    temp = start;
    while (temp != NULL)
    {
      printf("%d\t", temp->data);
      temp = temp->next;
    }
  }
}
void Insert_Beg()
{
  struct Node *ptr;
  int n;
  ptr = (struct Node *)malloc(sizeof(struct Node *));
  printf("Enter Number to Insert: ");
  scanf("%d", &n);
  ptr->data = n;
  ptr->next = NULL;
  if (start == NULL)
  {
    printf("Item added at Start");
    start = ptr;
  }
  else
  {
    ptr->next = start;
    start = ptr;
    printf("Node Inserted");
  }
}

void Insert_nthPosition()
{
  int n, pos;
  struct Node *ptr, *temp;
  printf("Enter position where to insert:");
  scanf("%d", &n);
  printf("Enter value to insert:");
  scanf("%d", &n);
  ptr = (struct Node *)malloc(sizeof(struct Node *));
  ptr->data = n;
  ptr->next = NULL;
  if (start == NULL)
  {
    printf("Item added at Start");
    start = ptr;
  }
  else
  {
    int count = 1;
    temp = start;
    while (temp->next != NULL)
    {
      if (count == n)
      {
      }
      temp = temp->next;
      count++;
      printf("Count: %d", count);
    }
    temp->next = ptr;
    printf("Item added at nth");
  }
}

void Insert_End()
{
  int n;
  struct Node *ptr, *temp;
  printf("Enter value to insert: ");
  scanf("%d", &n);
  ptr = (struct Node *)malloc(sizeof(struct Node *));
  ptr->data = n;
  ptr->next = NULL;
  if (start == NULL)
  {
    printf("Item added at Start");
    start = ptr;
  }
  else
  {
    temp = start;
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = ptr;
    printf("Item added at End");
  }
}

void Delete_beg()
{
  if (start == NULL)
  {
    printf("No Node for deletion");
  }
  else
  {
    start = start->next;
    printf("Node deleted from beginning");
  }
}

void Delete_End()
{
  struct Node *temp, *temp1;
  if (start == NULL)
  {
    printf("No Node for deletion");
  }
  else
  {
    temp = start;
    while (temp->next != NULL)
    {
      temp1 = temp;
      temp = temp->next;
    }
    temp1->next = NULL;
    free(temp);
    printf("Node deleted from End");
  }
}

void Search(){
  struct Node *temp;
  temp=start;
  int n,i=1,f=0;
  printf("Enter Number to Search: ");
  scanf("%d",&n);
  while(temp->next!=NULL){
    if(temp->data==n){
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
