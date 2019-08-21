#include<stdio.h>
void ShellSort(int a[],int n)
{
    for(int gap =n/2;gap>0;gap=gap/2)
    {
        for(int i=gap;i<n;i++)
        {
           int temp = a[i];
           int j;
           for(j=i;j>=gap && a[j-gap]>temp;j=j-gap)
           {
               a[j]=a[j-gap];
           }
           a[j]=temp;
        }
    }
}
int main()
{
    int a[] = {4,6,2,8,1,9,3,5 };
    int n = sizeof(a) / sizeof(a[0]);
    ShellSort(a,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
