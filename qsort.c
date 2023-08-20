#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int par(int arr[],int lb,int ub){
    int pivot,start,end;
    pivot=arr[lb];
    start=lb;
    end=ub;
    while(start<end){
        while(arr[start]<=pivot){
            start++;
        }
        while(arr[end]>pivot){
            end--;
        }
        if(start<end){
            swap(&arr[start],&arr[end]);
        }
    }
    swap(&arr[lb],&arr[end]);
    return end;
}
void quick(int arr[],int lb,int ub){
    int loc;
    if(lb<ub){
        loc=par(arr,lb,ub);
        quick(arr,lb,loc-1);
        quick(arr,loc+1,ub);
    }
}

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
    quick(arr,0,z);
    printf("\nThe sorted array is : ");
    for(x=0;x<n;x++){
        printf("%d\t\t",arr[x]);
    }
}