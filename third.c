#include <stdio.h>

int main(){
    FILE *fptr;
    char str1[100],c[100];
    fptr=fopen("prit.txt","r");
    while(fgets(str1,100,fptr)!=NULL){
        printf("%s",str1);
    }
    fclose(fptr);
}