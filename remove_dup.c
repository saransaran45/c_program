#include<stdio.h>
#include<stdlib.h>
int main(){
    int i,j,k,size,arr[10];
    printf("Enter the size of the array :");
    scanf("%d",&size);
    printf("Enter %d elements in the array :",size);
    for (i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    for (i=0;i<size;i++){
        for(j=i+1;j<size;j++){
            if(arr[i]==arr[j]){
                for(k=j;k<size-1;k++){
                    arr[k]=arr[k+1];
                }
                size--;
                j--;
            }
        }
    }
    printf("After the removing duplicates :");
    for (i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}
