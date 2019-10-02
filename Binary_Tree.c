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
struct node *push()
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the Data ");
    scanf("%d",&p->data);
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
            t1 = root;
            while(t->left != NULL )
            {
                t = t->left;
                if(t1->left != t)
                    t1 = t1->left;
            }
            root->data = t->data;
            t1->left = NULL;
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
                r->left = NULL; temp = NULL;  free(temp); }
            else{
                r->right = NULL; temp = NULL;  free(temp); }
            printf("\nSuccessfully Deleted\n");
        }
        else if(temp->left != NULL && temp->right == NULL)
        {
            if(r->left == temp){
                r->left = temp->left;
                free(temp);temp = NULL;
            }
            else{
                r->right = temp->left;
                free(temp);temp = NULL;
            }
            printf("\nSuccessfully Deleted\n");
        }
        else if(temp->left == NULL && temp->right != NULL)
        {
            if(r->left == temp){
                r->left = temp->right;
                free(temp);temp = NULL;
            }
            else{
                r->right = temp->right;
                free(temp);temp = NULL;
            }
            printf("\nSuccessfully Deleted\n");
        }
        else
        {
            struct node *t,*t1;
            t = temp;
            t1 = r;
            while(t->left != NULL)
            {
                if(t1->left == t)
                    t1 = t1->left;
                else
                    t1 = t1->right;
                t = t->left;
            }
            temp->data = t->data;
            t1->left = NULL;
            t = NULL;
            free(t);
            printf("\nSuccessfully Deleted\n");
        }
    }
}
void insert(struct node *f)
{
    int pos =0;
    int c =0;
    if(root == NULL)
    {
        struct node *ptr = push();
        root = ptr;
        f = root;
    }
    while(c == 0)
    {
        printf("Enter the Position(Left - 1/Right - 2/Stop - 3):");
        scanf("%d",&pos);
        if(pos == 1 )
        {
            if(f->left == NULL)
            {
                printf("Enter the Left Child of %d",f->data);
                struct node *ptr = push();
                f->left = ptr;
                f = root;
            }
            else
            {
                insert(f->left);
                return ;
            }
        }
        else if(pos == 2 )
        {
            if(f->right == NULL)
            {
                printf("Enter the Right Child of %d",f->data);
                struct node *ptr = push();
                f->right = ptr;
                f = root;
            }
            else
            {
                insert(f->right);
                return ;
            }
        }
        else if(pos == 3)
        {
            c = 1;
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
    int ch ,s;
    while(1)
    {
        printf("\n\t\tMENU\n1.INSERT\n2.DISPLAY\n3.Search\n4.Delete\n5.Delete Node\n6.EXIT\nEnter your Option:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : insert(root);break;
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
