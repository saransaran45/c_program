#include<stdio.h>
#include<Stdlib.h>
void main(){
    int n,x;
    printf("Enter the no of elements int the array : ");
    scanf("%d",&n);
    int arr[n],s;
    for(s=0;s<n;s++){
        printf("\nEnter the array element [%d] : ",s);
        scanf("%d",&arr[s]);
    }
    int i,j,temp;
    for(i=0;i<n-1;i++){
        int flag=0;
        for(j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag =1;
            }
        }
        if(flag==0){
            break;
        }
    }
    printf("\nThe sorted array is : ");
    for(x=0;x<n;x++){
        printf("%d\t\t",arr[x]);
    }
}