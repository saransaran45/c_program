#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main(){
    int size=0,i=0,j=0,temp=0,a[10];
    printf("Enter the size of the array:");
    scanf("%d",&size);
    for(i=0;i<size;i++){
        printf("Element of a[%d] : ",i);
        scanf("%d",&a[i]);
    }
    for(i=1;i<size;i++){
        temp = a[i];
        j = i-1;
        while(j>=0 && a[j]>temp){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
    printf("The insertion sort elements :");;
    for(i=0;i<size;i++){
        printf("\t%d",a[i]);
    }
}