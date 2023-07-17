#include<stdio.h>
#include<conio.h>

int c[20];

void main()
{
    int n;
    int a[20];
    printf("enter the num of elements");
    scanf("%d",&n);
    int low=0;
    int high=n-1;
    printf("Enter an array to be merged");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    merge_sort(low,high,a);
    printf("The merged sorted array is \n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }

}

void merge_sort(int low,int high,int a[])
{
    if(low<high)
    {
        int mid=(low+high)/2;
        merge_sort(low,mid,a);
        merge_sort(mid+1,high,a);
        merge(low,mid,high,a);
    }
}

void merge(int low,int mid,int high,int a[])
{
    int i = low;
    int j = mid+1;
    int k = 0;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            c[k]=a[i];
            i=i+1;
            k=k+1;
        }
        else
        {
            c[k]=a[j];
            j=j+1;
            k=k+1;
        }
    }
    while(i<=mid)
    {
        c[k]=a[i];
        k=k+1;
        i=i+1;
    }
     while(j<=high)
    {
        c[k]=a[j];
        k=k+1;
        j=j+1;
    }
    for(int i=0;i<high-low+1;i++)
    {
        a[i+low]=c[i];
    }
}