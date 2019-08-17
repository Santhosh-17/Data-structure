#include<stdio.h>
#include<stdlib.h>
struct node{
int pow;
int coe;
struct node *next;
};
struct node *eq1,*eq2,*ans,*old;
void create()
{
struct node *old,*old1;
int c;
printf("\n--------EQUATION 1---------\n");

eq1 = (struct node *)malloc(sizeof(struct node));
printf("Enter power and Coefficient:\n");
scanf("%d %d",&eq1->pow,&eq1->coe);
eq1->next = NULL;
old=eq1;

do{
struct node *n;
n=(struct node *)malloc(sizeof(struct node));
printf("Enter power and Coefficient:\n");
scanf("%d %d",&n->pow,&n->coe);
old->next =n;
n->next = NULL;
old = old->next;
printf("\nDo you want Continue(1/0):\n");
scanf("%d",&c);
}while(c==1);

printf("\n--------EQUATION 2---------\n");

eq2 = (struct node *)malloc(sizeof(struct node));
printf("Enter power and Coefficient:\n");
scanf("%d %d",&eq2->pow,&eq2->coe);
eq2->next = NULL;
old1=eq2;

do{
struct node *n1;

n1=(struct node *)malloc(sizeof(struct node));
printf("Enter power and Coefficient:\n");
scanf("%d %d",&n1->pow,&n1->coe);
old1->next =n1;
n1->next = NULL;
old1= old1->next;
printf("\nDo you want Continue(1/0):\n");
scanf("%d",&c);
}while(c==1);
}
void link(int x,int y,int pw)
{
    struct node *n;
     n = (struct node *)malloc(sizeof(struct node));
     n->coe = x - y;
     n->pow = pw;
     n->next = NULL;
     old->next = n;
     old = old->next;
}
void  linkx(int x,int y ,int pw)
{
    ans->coe = x - y;
    ans->pow = pw;
    ans->next = NULL;
    old = ans;
}
void add()
{
    struct node *p,*p1,*n,*sol,*n1,*n2;
    p = eq1;
    p1 = eq2;
    ans = (struct node *)malloc(sizeof(struct node));
    if(p->pow == p1->pow)
    {
        linkx(p->coe,p1->coe,p->pow);
        p = p->next;
        p1 = p1->next;
    }
    else if(p1->pow > p->pow)
    {
        linkx(0,p1->coe,p1->pow);
        p1 = p1->next;
    }
    else{
        linkx(p->coe,0,p->pow);
        p = p->next;
    }

    while(p!= NULL && p1 != NULL){

        if(p->pow == p1->pow)
        {
            link(p->coe,p1->coe,p->pow);
            p = p->next;
            p1 = p1->next;
        }
        else if(p1->pow > p->pow)
        {
            link(0,p1->coe,p1->pow);
            p1 = p1->next;
        }
        else
        {
            link(p->coe,0,p->pow);
            p = p->next;
        }
    }
    while(p!=NULL && p1 == NULL)
    {
        link(p->coe,0,p->pow);
        p = p->next;
    }
    while(p==NULL && p1 != NULL)
    {
        link(0,p1->coe,p1->pow);
        p1= p1->next;
    }
    printf("\n\nThe solution is..\n");
    sol =ans;
    printf("\n-----------------------------\n");
    while(sol->next!=NULL){
        printf("(%dx)^%d+",sol->coe,sol->pow);
        sol = sol->next;
    }
    printf("(%dx)^%d",sol->coe,sol->pow);
    printf("\n-----------------------------\n");
}

void display()
{
struct node *p,*p1;
printf("\n--------EQUATION 1---------\n");
p = eq1;
while(p->next!=NULL)
{
printf("%d(x)^%d+",p->coe,p->pow);
p=p->next;
}
printf("%d(x)^%d\n",p->coe,p->pow);
printf("\n\n--------EQUATION 2---------\n");
p1 = eq2;
while(p1->next!=NULL)
{
printf("%d(x)^%d+",p1->coe,p1->pow);
p1=p1->next;
}
printf("%d(x)^%d\n",p1->coe,p1->pow);
}
int main()
{
create();
display();
add();
}
