#include<stdio.h>
void countsort(int a[],int n,int e);
void print(int a[],int n);
int max(int a[],int n)
{
    int i ,max;
    for(int i=1;i<n;i++)
    {
        max = a[0];
        if(max < a[i])
        {
            max = a[i];
        }
    }
    return max;
}
void radixsort(int a[],int n)
{
    int m =max(a,n);
    int e;
    for(e=1;m/e>0;e=e*10)
    {
        countsort(a,n,e);
    }
}
void countsort(int a[],int n,int e)
{
    int count[10]={0};
    int i;
    int output[n];
    for(i=0;i<n;i++)
    {
        count[(a[i]/e)%10]++;
    }
    for(i=1;i<10;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    for(i=n-1;i>=0;i--)
    {
        output[count[(a[i]/e)%10]-1] = a[i];
        count[(a[i]/e)%10]--;
    }
    for(i=0;i<n;i++)
    {
        a[i]=output[i];
    }

}
void print(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
int main() {
    int a[] = { 247,192,345,121,222,101,99,253 };
    int n = sizeof(a) / sizeof(a[0]);
    radixsort(a,n);
    print(a,n);
    return 0;
}
