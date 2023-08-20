#include<conio.h>
#include<stdio.h>

void main(){
    int a,temp,n,l,rev=0;
    printf("Enter a number:");
    scanf("%d",&a);
    temp = a;
    while(temp!=0) {
        n = temp % 10;
        rev = rev*10 + n;
        temp/=10;
    }
    if(a==rev){
        printf("%d is polindrome",a);
    }
    else{
        printf("%d is not a polindrome",a);
    }

}