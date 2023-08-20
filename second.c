#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fptr1,*fptr2;
    char name[100],c;

    printf("Enter the filename to open for reading=");
    scanf("%s",name);

    fptr1=fopen(name,"r");
    if(fptr1==NULL){
        printf("Cannot open file %s \n",name);
        exit(0);
    }
    printf("Enter the filename for writing=");
    scanf("%s",name);

    fptr2=fopen(name,"w");
    c=fgetc(fptr1);
    while(c!=EOF){
        fputc(c,fptr2);
        c=fgetc(fptr1);
    }
    printf("\nContents copied to %s",name);
    fclose(fptr1);
    fclose(fptr2);
}