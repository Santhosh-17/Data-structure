#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

struct node *head,*n;
struct node *top=NULL;

void display()
{
    struct node *ptr;
    ptr = top;
    printf("\nValues in the Stack ....\n");
    while(ptr->next != NULL)
    {
        printf("%d",ptr->data);
        printf("\n");
        ptr=ptr->next;
    }
    printf("%d",ptr->data);
    printf("\nSuccessfully Displayed!!\n");
}
void push()
{
    if(top == NULL)
    {
        int num;
        head = (struct node *)malloc(sizeof(struct node));
        printf("Enter the number to be Push:\n");
        scanf("%d",&head->data);
        head->next = NULL;
        top = head;
        printf("Enter the number of elements to Pushed:");
        scanf("%d",&num);
        for(int i=0;i<num;i++)
        {
         n = (struct node *)malloc(sizeof(struct node));
         printf("Enter the number to be Push:\n");
         scanf("%d",&n->data);
         n->next = top;
         top = n;
        }
    }
    else
    {
        n = (struct node *)malloc(sizeof(struct node));
        printf("Enter the number to be Push:\n");
        scanf("%d",&n->data);
        n->next = top;
        top = n;
    }
    printf("\nSuccessfully Pushed!!\n");
}

void pop()
{
    struct node *ptr ;
    ptr = top;
    top = ptr->next;
    free(ptr);
    printf("\nSuccessfully Popped!\n");

}
int main()
{
    int ch;
    while(1){
    printf("Operations in Stack..\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter your Option:\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1 : push(); break;
        case 2 : pop(); break;
        case 3 : display(); break;
        case 4 : exit(0);break;
        default : printf("Invalid Number!");
    }
    }
    return 0;
}


