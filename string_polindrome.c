#include<stdio.h>
#include<string.h>

void main(){
    char a[100],b[100];
    int l,s=0;
    printf("Enter the string:");
    scanf("%s",a);
    l =strlen(a);
    for(l;l>0;l--){
        b[s] = a[l-1];
        s++;
    }
    if(strcmp(a,b)==0){
        printf("polindrome");
    }
    else{
        printf("Not a polindrome");
    }
}