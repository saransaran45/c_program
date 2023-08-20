#include<stdio.h>
#include<stdlib.h>
void merge(int arr[],int ,int ,int );
void mergesort(int arr[],int ,int );
void main(){
    int n,z,x;
    printf("Enter the no of elements int the array : ");
    scanf("%d",&n);
    int arr[n],s;
    for(s=0;s<n;s++){
        printf("\nEnter the array element [%d] : ",s);
        scanf("%d",&arr[s]);
    }
    z=n-1;
    mergesort(arr,0,z);
    printf("\nThe sorted array is : ");
    for(x=0;x<n;x++){
        printf("%d\t\t",arr[x]);
    }
}
void merge(int arr[],int lb,int mid,int ub){
    int i,j,k,a;int b[100];
    i=lb;
    j=mid+1;
    k=lb;
    while(i<=mid && j<=ub){
        if(arr[i]<=arr[j]){
            b[k]=arr[i];
            i++;
        }
        else{
            b[k]=arr[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=ub){ 
            b[k]=arr[j];
            j++;k++;
            }
    }
    else{
        while(i<=mid){
            b[k]=arr[i];
            i++;k++;
        }
    }
    for(a=lb;a<=ub;a++){
        arr[a]=b[a];
    }
}
void mergesort(int arr[],int lb,int ub){
    if(lb<ub){
    int mid;
    mid=(lb+ub)/2;
    mergesort(arr,lb,mid);
    mergesort(arr,mid+1,ub);
    merge(arr,lb,mid,ub);
    }
}

