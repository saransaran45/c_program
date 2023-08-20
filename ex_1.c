#include<stdio.h>

void main(){
    int a,b,c;
    printf("Enter three side of the triangle:");
    scanf("%d%d%d",&a,&b,&c);
    if(a==b==c){
        printf("this is equilatral triangle");
    }
    else if(a==b||b==c||c==a){
        printf("isosceles triangle");
    }
    else{
        printf("scalene triange");
    }
}