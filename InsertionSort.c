#include<stdio.h>
int main()
{
    int n,key,j;
    printf("Enter the No .Of Elements:");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter the Elements:");
        scanf("%d",&a[i]);
    }

    for(int i=1;i<n;i++)
    {
        key =a[i];
        j = i-1;
        while(j>=0 && key<a[j])
        {
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] =key;
    }
    printf("\nElements in the Ascending Order:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}
