#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void swap(int *a,int *b){
    int temp =*a;
    *a = *b;
    *b = temp;
}
int sortquick(int a[],int lb,int ub){
    int start,pivot,end;
    pivot = a[lb];
    start = lb;
    end = ub ;
    while(start<end){
        while(a[start]<=pivot){
            start++;
        }
        while(a[end]>pivot){
            end--;
        }
        if(start<end){
            swap(&a[start],&a[end]);
        }
    }
    swap(&a[lb],&a[end]);
    return end;
}
void quick(int a[],int lb,int ub){
    int loc;
    if(lb<ub){
        loc = sortquick(a,lb,ub);
        quick(a,lb,loc-1);
        quick(a,loc+1,ub);
    }
}
int main(){
    int size;
    printf("Enter the array size:");
    scanf("%d",&size);
    int a[size],i;
    for(i=0;i<size;i++){
        printf("Enter the element a[%d]:",i);
        scanf("%d",&a[i]);
    }
    quick(a,0,size-1);
    printf("After sorting array is :");
    for(i=0;i<size;i++){
        printf("\t%d",a[i]);
    }
    return 0;
}