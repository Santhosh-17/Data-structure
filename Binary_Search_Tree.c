#include<stdio.h>
#include<stdlib.h>
int flag = 0;
struct node
{
    int data;
    struct node *left, *right;
};
struct node *root = NULL;
struct node *temp ,*r;
struct node *push(int n)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = n;
    p->left = NULL;
    p->right = NULL;
    return p;
}
void search(struct node *n,int s)
{
    if(n != NULL)
    {
        search(n->left,s);
        if(n->data == s)
        {
            flag = 1;
            printf("Found: %d",n->data,flag);
            temp = n;
        }
        search(n->right,s);
    }
    return ;
}
void searchX(struct node *n,int s)
{
    if(n != NULL)
    {
        if(n->left != NULL)
        {
            if(n->left->data == s)
            {
                r = n;
            }
        }
        searchX(n->left,s);
        if(n->right != NULL)
        {
            if(n->right->data == s)
            {
                r = n;
            }
        }
        searchX(n->right,s);
    }
    return ;
}
void DeleteNode(struct node *s)
{
    int num;
    printf("Enter the Data to be Delete:\n");
    scanf("%d",&num);
    if(num == root->data )
    {
        if(root->left != NULL && root->right == NULL)
        {
            root = root->left; printf("\nDeleted Successfully\n");
        }
        else if (root->left == NULL && root->right != NULL)
        {
            root = root->right; printf("\nDeleted Successfully\n");
        }
        else{
            struct node *t, *t1;
            t = root;
            t = t->left;
            while(t->right != NULL )
            {
                t1 = t;
                t = t->right;
            }
            root->data = t->data;
            t1->right = NULL;
            t = NULL;
            free(t);
            printf("\nSuccessfully Deleted\n");
        }
    }
    else
    {
        search(s,num);
        searchX(s,num);
        if(temp->left == NULL && temp->right == NULL)
        {
            if(r->left == temp){
                r->left = NULL;  free(temp); }
            else{
                r->right = NULL; free(temp); }
            printf("\nSuccessfully Deleted\n");
        }
        else if(temp->left != NULL && temp->right == NULL)
        {
            if(r->left == temp){
                r->left = temp->left;
                free(temp);}
            else{
                r->right = temp->left;
                free(temp); }
            printf("\nSuccessfully Deleted\n");
        }
        else if(temp->left == NULL && temp->right != NULL)
        {
            if(r->left == temp){
                r->left = temp->right;
                free(temp);  }
            else{
                r->right = temp->right;
                free(temp);  }
            printf("\nSuccessfully Deleted\n");
        }
        else
        {
            struct node *t,*t1;
            t = temp;
            t1 = t;
            t = t->left;
            while(t->right != NULL)
            {
                t1 = t;
                t = t->right;
            }
            temp->data = t->data;
            t1->right = NULL;
            t = NULL;
            free(t);
            printf("\nSuccessfully Deleted\n");
        }
    }
}
void insert(struct node *f,int num)
{
    if(root == NULL)
    {
        struct node *ptr = push(num);
        root = ptr;
        printf("\n%d is the Root Node\n",root->data);
        f = root;
    }
    else
    {
        struct node *ptr = push(num);
        if(f->data > ptr->data)
        {
            if(f->left == NULL)
            {
                printf("\n%d is the Left Child of %d\n",ptr->data,f->data);
                f->left = ptr;
                f = root;
            }
            else
            {
                insert(f->left,num);
                return ;
            }
        }
        else if(f->data < ptr->data)
        {
            if(f->right == NULL)
            {
                printf("\n%d is the Right Child of %d\n",ptr->data,f->data);
                f->right = ptr;
                f = root;
            }
            else
            {
                insert(f->right,num);
                return ;
            }
        }
    }
}
void display(struct node *n)
{
    if(n != NULL)
    {
        display(n->left);
        printf("%d ",n->data);
        display(n->right);
    }
    return ;
    if(n == NULL)
    {
        printf("\nTree is Empty..\n");
    }
}
void Delete(struct node *n)
{
    if(n != NULL)
    {
        Delete(n->left);
        free(n);
        Delete(n->right);
    }
    root = NULL;
}
int main()
{
    int ch ,n,s,a[10];
    while(1)
    {
        printf("\n\t\tMENU\n1.INSERT\n2.DISPLAY\n3.Search\n4.Delete\n5.Delete Node\n6.EXIT\nEnter your Option:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 :printf("\nEnter the no .of Elements to be Enter:");
                    scanf("%d",&n);printf("\nEnter the Elements:\n");
                    for(int i=0;i<n;i++)
                    {
                        scanf("%d",&a[i]);
                        insert(root,a[i]);
                    }
                    break;
            case 2 : if(root == NULL)
                         printf("\nTree is Empty ..");
                     display(root);break;
            case 3 : printf("\nEnter the Data to Search:\n");
                     scanf("%d",&s);
                     search(root,s);
                     if( flag == 0)
                         printf("Not Found!");
                     else
                        flag = 0;
                     break;
            case 4 :Delete(root);
                    printf("\nSuccessfully Deleted!\n");break;
            case 5 :if(root == NULL){
                        printf("\nTree is Empty..\n"); }
                    else if(root->left == NULL && root->right == NULL ){
                        root = NULL;
                        printf("\nDeleted Successfully!\n"); }
                    else{
                        DeleteNode(root); }
                    break;
            case 6 :exit(0);break;
            default: printf("Invalid");break;
        }
    }
}
