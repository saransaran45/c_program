#include<stdio.h>

void main(){
    int b[100],val;
    printf("Enter five element:");
    for(int j=0;j<5;j++){
        scanf("%d",&b[j]);
    }
    for(int i=4;i>=0;i--){
        b[i+1] = b[i];
       
    }
    printf("Enter the value to added ar begging:");
    scanf("%d",&val);
    b[0] = val;
    printf("After insertion the values are :");
    for(int i=0;i<=5;i++){
        printf("%d ",b[i]);
    }
}