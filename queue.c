#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 5
int front=-1;
int rear=-1;
int q[size];
void insert();
void delete();
int display();
int main()
{
int choice;
do{
printf("\n\nMenu\n1.Insert\n2.delete\n3.display\n4.Exit\n\nEnter your choice: ");
scanf("%d",&choice);
switch(choice){
case 1: insert(); display();break;
case 2: delete(); display();break;
case 3: display();break;
case 4: printf("END OF THE PROGRAM");exit(0);
}
}while(choice!=4);
}
void insert()
{
int no;
printf("\nEnter no.: ");
scanf("%d",&no);
if(rear<size-1){
q[rear=rear+1]=no;
if(front==-1)
front+=1;
}
else
{
printf("\nQueue overflow\n");
}
}
void delete(){
if(front==-1){
printf("\nQueue underflow");
return;
}
else{
printf("\nDeleted item: %d\n",q[front]);
}
if(front==rear){
front=-1;
rear=-1;
}
else{
front=front+1;
}}
int display()
{
int i;
if(front==-1)
printf("\nQueue is empty\n\n");
else{
printf("\nthe elements in the queue are:\n");
for(i=front;i<=rear;i++)
printf("%d\n",q[i]);
}
}

