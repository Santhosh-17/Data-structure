#include<stdio.h>
int main()
{
    int n,min;
    printf("Enter the No .Of Elements:");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter the Elements:");
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n-1;i++)
    {
        min = i;
        for(int j=i+1;j<n;j++)
        {
            if(a[min]>a[j])
            {
                min = j;
            }
        }
        int temp ;
        temp = a[i];
        a[i]= a[min];
        a[min] = temp;
    }
    printf("\nElements in the Ascending Order:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}
