#include<stdio.h>
#include<stdlib.h>
struct node 
{
int data;
struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL ;
struct node *n;

void create()
{
int num;
if(front == NULL)
{
front = (struct node *)malloc(sizeof(struct node));
printf("\nEnter the number:\n");
scanf("%d",&front->data);
front->next = NULL;
rear = front;
}
printf("\nEnter -1 to STOP\n");
printf("Enter the elements in queue:\n");
scanf("%d",&num);
while(num != -1)
{
n = (struct node *)malloc(sizeof(struct node));
n->data = num;
rear->next = n;
rear =n;
n->next = NULL;
printf("Enter the elements in queue:\n");
scanf("%d",&num);
}
printf("\nSuccessfully Created!\n");
}

void insert()
{
if(front == NULL){
create();
}
else
{
struct node *ptr;
ptr = (struct node *)malloc(sizeof(struct node));
printf("\nEnter the number:\n");
scanf("%d",&ptr->data);
ptr->next = NULL;
rear->next = ptr;
rear = ptr;
printf("\nSuccessfully Inserted!!\n");
}
}

void delete()
{
struct node *ptr;
ptr = front;
front = front->next;
ptr->next =NULL;
free(ptr);
printf("\nSuccessfully Deleted\n");
}

void display()
{

struct node *ptr;
ptr = front;
printf("\nThe Values in the list ....\n");
while(ptr->next != NULL)
{
printf("%d",ptr->data);
printf("\n");
ptr = ptr->next;
}
printf("%d",ptr->data);
printf("\nSuccessfully Displayed\n");
}

int main()
{
int ch;
while(1){
printf("\nOperations in Queue....\n1.Create\n2.Insert\n3.Delete\n4.Display\n5.Exit\nEnter your option:\n");
scanf("%d",&ch);
switch(ch)
{
case 1 : create();break;
case 2 : insert();break;
case 3 : delete();break;
case 4 : display();break;
case 5 : exit(0);break;
default : printf("\nInvalid Number!!\n");break;
}
}
return 0;
}

