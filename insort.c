#include<stdio.h>
#include<Stdlib.h>
void main(){
    int n;
    printf("Enter the no of elements int the array : ");
    scanf("%d",&n);
    int arr[n],s;
    for(s=0;s<n;s++){
        printf("\nEnter the array element [%d] : ",s);
        scanf("%d",&arr[s]);
    }
    
    int i,j,temp,x;
    for(i=1;i<n;i++){
        temp=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
    printf("\nThe sorted array is : ");
    for(x=0;x<n;x++){
        printf("%d\t\t",arr[x]);
    }
}