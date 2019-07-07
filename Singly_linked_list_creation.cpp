#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
int main()
{
    int num;
    struct node *head , *newnode, *last;
    head = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data of head: ");
    scanf("%d", &head->info);
    head->next = NULL;
    last = head;
    printf("Enter the no.of nodes: ");
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        newnode =  (struct node *)malloc(sizeof(struct node));
        printf("Enter the data of newnode: ");
        scanf("%d",&newnode->info);
        newnode->next = NULL;
        last->next=newnode;
        last = newnode;
    }
    printf("Successfully created..");
    return 0;
}
