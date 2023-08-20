/*#include<stdio.h>

int main(){
    char str1[200];
    char temp[200];
    char c = 's';
    FILE *fptr;
    fptr = fopen("prit.txt","w+");
    printf("Enter the name=");
    scanf("%s",temp);
    printf("\n");
    fprintf(fptr,"%s",temp);
    int len=ftell(fptr);
    printf("%d",len);
    fseek(fptr,2,SEEK_SET);
    fputc(c,fptr);
    fseek(fptr,2,SEEK_SET);
    fputc('i',fptr);
    fclose(fptr);
}*/

#include<stdio.h>
int main(){
    char str[100];
    char s[100];
    FILE *ptr;
    ptr = fopen("new.txt","w+");
    printf("Enter your name:");
    gets(str);
    //fprintf(ptr,"%s",str);
    fputs(str,ptr);
    //fscanf(ptr,"%s",s);
    int len = ftell(ptr);
    printf("The length of the name is :%d",len);
    fseek(ptr,4,SEEK_SET);
    fputc('a',ptr);
    fclose(ptr);
}