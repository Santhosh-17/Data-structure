#include<stdio.h>
int main()
{
    int n,s,check=1;
    int first,mid,last;
    printf("Enter the No.of elements:");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        printf("\nEnter the elements:");
        scanf("%d",&a[i]);
    }
    printf("\nEter the Element to be search:");
    scanf("%d",&s);

    first = 0;
    last = n-1;
    while(first<=last){
    mid = (first+last)/2;
    if(a[mid] == s)
    {
        check = 0;
        printf("%d is Found at the %d position\n",s,mid+1);
        break;
    }
    else if(a[mid]>s)
    {
        last = mid-1;
    }
    else{
        first = mid+1;
    }
    }
    if(check)
    {
        printf("%d is not Found in the list\n",s);
    }

}
