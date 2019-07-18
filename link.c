#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *head;
struct node *old,*n,*p;
void create();
void display();
void in_beg();
void in_mid();
void in_end();
void del_beg();
void del_mid();
void del_end();

int main()
{
int opt;
while(1){
printf("\nMenu\n1.Create\n2.Display\n3.Insert at beginning\n4.Insert at middle\n5.Insert at end\n6.Delete at beginning\n7.Delete at middle\n8.Delete at end\n-1.Exit\nEnter your option:\n");
scanf("%d",&opt);
switch(opt)
{
case 1 :create();break;
case 2 :display();break;
case 3 :in_beg();break;
case 4 :in_mid();break;
case 5 :in_end();break;
case 6 :del_beg();break;
case 7 :del_mid();break;
case 8 :del_end();break;
case -1 :exit(0);break;
default :printf("Enter a valid number!");break;
}
}
return 0;
}

void create()
{
int x,lim;
head = (struct node*)malloc(sizeof(struct node));
printf("Enter data:");
scanf("%d",&x);
head->data=x;
head->next=NULL;
old=head;
printf("Enter the limit..");
scanf("%d",&lim);
for(int i=0;i<lim;i++){
n = (struct node*)malloc(sizeof(struct node));
printf("Enter data:");
scanf("%d",&n->data);
n->next=NULL;
old->next=n;
old=old->next;
}
printf("Created linked list is..\n");
}

void display()
{
p = head;
printf("The value are ...\n");
while(p->next!=NULL)
{
printf("%d",p->data);
printf("\n");
p = p->next;
}
printf("%d",p->data);
}

void in_beg()
{
struct node *temp;
temp = head;
temp = (struct node*)malloc(sizeof(struct node));
printf("Enter data:");
scanf("%d",&temp->data);
temp->next = head;
head = temp;
printf("Successfully Inserted!");
}

void in_mid()
{

int i,ele,pos;
old = head;
p = head;
printf("Enter the position :");
scanf("%d",&pos);
printf("Enter the element:");
scanf("%d",&ele);
n = (struct node*)malloc(sizeof(struct node));
n->data = ele;

for(i=1;i<pos;i++)
{
old = p;
p = p->next;
}

old->next = n;
n->next = p;


printf("Successfully Inserted!");

}

void in_end()
{
p=head;
while(p->next!=NULL)
{
p=p->next;
}
n = (struct node*)malloc(sizeof(struct node));
printf("Enter data:");
scanf("%d",&n->data);
p->next =n;
n->next = NULL;
printf("Successfully Inserted!");
}

void del_beg()
{
p= head;
head = head->next;
p->next = NULL;
free(p);
printf("Successfully Deleted!");
}

void del_mid()
{
struct node *s;
int pos;
old = head;
p = head;
printf("Enter the position :");
scanf("%d",&pos);
for(int i=1;i<pos;i++)
{
old = p;
p = p->next;
}

p->next = s;
old->next =s;
p->next = NULL;
free(p);
printf("Successfully Deleted!");

}

void del_end()
{
p = head;
while(p->next!=NULL)
{
old = p;
p =p->next;
}
old->next = NULL;
free(p);
printf("Successfully Deleted!");
}

