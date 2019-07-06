#include<stdio.h>
#include<stdlib.h>
#define high 20
int top = 0, n , i, s[high] , opt;
void create();
void push();
void pop();
void display();
int main()
{
    while(1){
        printf("Menu\n1.Create\n2.Push\n3.Pop\n4.Display\n5.Exit\nEnter your Choice:\n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1 : create(); break;
            case 2 : push(); break;
            case 3 : pop();break;
            case 4 : display();break;
            case 5 : exit(0); break;
            default : printf("IInvalid Number");
        }
    }
      return 0;
}
void create()
{
    printf("Enter the limit of the stack:\n");
    scanf("%d",&n);
    if (n<high)
    {
        printf("Enter the elements:\n");
        for (i=0;i<n;i++){
            scanf("%d" , &s[i]);
        }
        printf("Stack Successfully created...\n");
        top = n-1;
    }
    else{
        printf("Stack can not be created..");
    }
}

void push(){
    if(top<high)
    {
        int x;
       printf("Enter the elements to be pushed:\n");
       scanf("%d",&x);
       top ++;
       s[top] = x;
       n = top + 1;
    }
    else{
        printf("Stack is full");
    }
}
void pop()
{
    if(top<=0){
        printf("Stack is empty");
    }
    else{
    printf("The element to be popped is %d",s[top]);
    top--;
    n = top -1;
    printf("\n");
    }
}
void display()
{
     if(top<=0){
        printf("Stack is empty");
    }
    else{
        printf("The elements in the stack are ..\n");
        for (i=top;i>=0;i--)
        {
            printf("%d",s[i]);
             printf("\n");
        }
    }
}


