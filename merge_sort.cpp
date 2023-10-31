#include<iostream>
using namespace std;
void merge(int a[],int s1,int e1,int s2,int e2)
{
    int temp[50],i=s1,j=s2,k=0;
    while(i<=e1 && j<=e2)
    {
        if(a[i]<a[j])
        {
            temp[k]=a[i];
            i++;
            k++;
        }
        else
        {
            temp[k++]=a[j++];
        }
    }
    while(i<=e1)
    {
        temp[k++]=a[i++];
    }
    while(j<=e2)
    {
        temp[k++]=a[j++];
    }
    for(k=0,i=s1;i<=e2;k++,i++)
    {
        a[i]=temp[k];
    }
}
void mergesort(int a[],int i,int j)
{
    int mid=(i+j)/2;
    if(i<j)
    {
        mergesort(a,i,mid);
        mergesort(a,mid+1,j);
        merge(a,i,mid,mid+1,j);
    }
}
int main()
{
    int arr[7]={30,27,43,3,9,82,10};
    mergesort(arr,0,6);
    for(int i=0;i<=6;i++)
    {
        cout<<arr[i]<<" ";
    }
    return(0);
}
