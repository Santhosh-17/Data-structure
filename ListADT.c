#include<stdio.h>
#include<stdlib.h>

int a[10];
int n,i;
void create()
{
printf("Enter the no .of elements:");
scanf("%d",&n);
for( i=0;i<n;i++)
{
printf("Enter the elements:");
scanf("%d",&a[i]);
}
printf("\nSuccessFully Created!!\n");
}

void insert(){
int pos;
printf("Enter the position to insert an element:");
scanf("%d",&pos);
pos--;
n++;
for( i=n-1;i>=pos;i--)
{
a[i+1] = a[i];

}
a[pos]=0;
printf("Enter the element:");
scanf("%d",&a[pos]);
printf("\nSuccessFully Inserted!!\n");
}

void delete()
{
int pos;
printf("Enter the position to delete an element:");
scanf("%d",&pos);
pos--;
for( i=pos;i<n;i++)
{
a[i] = a[i+1];

}
printf("\nSuccessFully Deleted!!\n");
}
void search()
{
int search;
printf("Enter the element to be search:");
scanf("%d",&search);
for( i =0;i<n;i++)
{
if(a[i] == search)
{
printf("%d found at the %d",search,i+1);
}
}
printf("\nSuccessfully Found!\n");
}
void display()
{
printf("\nElements in the array:\n");
for( i =0;i<n;i++)
{
printf("%d\n",a[i]);
}
printf("\nSuccessfully Displayed!!\n");
}

int main()
{
int ch;
while(1)
{
printf("\n\t\tOperations in LIST ADT:\n1.Create\n2.Insert\n3.Delete\n4.Search\n5.Display\n6.Exit\nEnter your option:\n");
scanf("%d",&ch);
switch(ch)
{
case 1 :create();break;
case 2 :insert();break;
case 3 :delete();break;
case 4 :search();break;
case 5 :display();break;
case 6 :exit(0);break;
default :printf("Enter a Valid Number!!");break;
}
}
 return 0;
}


