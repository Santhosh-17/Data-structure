#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 3
int t=0;
struct node
{
char name[10];
int age;
int tc;
struct node *next;
};
struct node *train;
struct node *front=NULL;
struct node *rear=NULL ;
struct node *n;
struct node *dequeue();

void reserve()
{
int i=0,num,m;
struct node *old;
if(train == NULL)
{
    train = (struct node*)malloc(sizeof(struct node));
    printf("Enter the passenger name:");
    scanf("%s",train->name);
    printf("Enter the age:");
    scanf("%d",&train->age);
    train->tc = ++t;
    printf("Your seat no is :%d\n",train->tc);
    train->next=NULL;
    old=train;
}
for(i=0;i<MAX-1;i++)
{
n = (struct node*)malloc(sizeof(struct node));
printf("Enter the passenger name:");
scanf("%s",n->name);
printf("Enter the age:");
scanf("%d",&n->age);
n->tc = ++t;
printf("Your seat no is :%d\n",n->tc);
n->next=NULL;
old->next = n;
old = old->next;
}

}
void cancelation()
{
    int check = 1;
    struct node *ptr,*q;
    ptr = train;
    int sn;
    printf("\nEnter your Seat no.");
    scanf("%d",&sn);
    while(ptr != NULL && check ==1)
    {
        if(ptr->tc == sn)
        {
            check =0;
            q = dequeue();
            strcpy(ptr->name,q->name);
            ptr->age = q->age;
        }
        else
            check =1;
        ptr = ptr->next;
    }
    if(check)
    {
        printf("\nSeat number not Found!\nCheck your Seat number\n");
    }

}


void waitlist()
{
int num;
if(front == NULL)
{
front = (struct node *)malloc(sizeof(struct node));
printf("Enter the passenger name:");
scanf("%s",front->name);
printf("Enter the age:");
scanf("%d",&front->age);
front->tc = ++t;
printf("Your seat no is :%d\n",front->tc);
front->next = NULL;
rear = front;
}
printf("\nPRESS 1 to continue\nPRESS -1 to stop:\n");
scanf("%d",&num);
while(num != -1)
{
n = (struct node *)malloc(sizeof(struct node));
printf("Enter the passenger name:");
scanf("%s",n->name);
printf("Enter the age:");
scanf("%d",&n->age);
n->tc = ++t;
printf("Your seat no is :%d\n",n->tc);
rear->next = n;
rear =n;
n->next = NULL;
printf("\nPRESS 1 to continue:\nPRESS -1 to stop:");
scanf("%d",&num);
}
}
struct node *dequeue()
{

struct node *ptr;
ptr = front;
front = front->next;
ptr->next =NULL;
return ptr;
}
void display(struct node *temp)
{
struct node *ptr;
ptr = temp;
while(ptr->next != NULL)
{
printf("Name of the Passenger:%s\n",ptr->name);
printf("Age                 :%d\n",ptr->age);
printf("Ticket No           :%d\n",ptr->tc);
ptr = ptr->next;
}
printf("Name of the Passenger:%s\n",ptr->name);
printf("Age                  :%d\n",ptr->age);
printf("Ticket No            :%d\n",ptr->tc);
printf("\nSuccessfully Displayed\n");
}

int main()
{
    int ch,c;
    while(1){
    printf("\n--------------Railway Reservation System----------------\n");
    printf("\n\n1.Book Tickets\n2.Cancel Booking\n3.Check status\n4.List of Person who seat is confirmed\n5.List of waiting list\n6.Exit\n");
    printf("\n--------------------------------------------------------\n\nEnter your option:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:if(MAX>t)
               {
                   reserve();
               }
               if(MAX<=t){
               printf("\nSeats are Filled!\nDo you want Continue(1/0):");
               scanf("%d",&c);
               switch(c)
               {
                   case 1:printf("\nYou are Waiting List..\n");
                   waitlist();
                   break;
                   case 0:break;
                   default :printf("Invalid!!");
               }
               }

               break;
       case 2:cancelation();break;
       case 3:if(MAX>t)
              {
                  printf("\nSeats are Available!\n");
              }
              else
                printf("\nSeats are Filled!\n");
              break;
       case 4:printf("\nPersons confirmed for seats ....\n");
              display(train);break;
       case 5:if(MAX >= t ){
                printf("\nWait List is Empty\n");
              }
              else
              {
                  printf("\nPersons in the Waiting List ....\n");
                  display(front);
              }
              break;
       case 6:exit(0);break;
       default:printf("Invalid!");
    }
    }
return 0;
}
