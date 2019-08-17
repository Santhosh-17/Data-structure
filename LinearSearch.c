#include<stdio.h>
int main()
{
    int n,s,c=1,check=1;
    printf("Enter the No.of elements:");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        printf("\nEnter the elements:");
        scanf("%d",&a[i]);
    }
    printf("\nEnter the Element to be search:");
    scanf("%d",&s);
    for(int i=0;i<n;i++)
    {
        if(a[i]==s)
        {
            check = 0;
            printf("%d is Found at the %d position\n",s,c);
        }
        c++;
    }
    if(check)
    {
        printf("%d is not Found in the list\n",s);
    }

}
