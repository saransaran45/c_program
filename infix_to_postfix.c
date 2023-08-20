#include<stdio.h>
#include<string.h>
char stk[50];
int top=-1;
void push(char a){
    top++;
    stk[top]=a;
}
char pop(){
    char item=stk[top];
    top--;
    return item;
}
int priority(char a){
    if(a=='('){
        return 0;
    }
    if(a=='+'||a=='-'){
        return 1;
    }
    if(a=='*'||a=='/'){
        return 2;
    }
}
void main(){
    char ex[50],*e,a;
    printf("\nenter the infix exp :");
    gets(ex);
    e=ex;
    while(*e !='\0'){
        if(isalnum(*e)){
            
            printf("%c",*e);
        }
        else if(*e =='('){
            push(*e);
        }
        else if(*e==')'){
            a=pop();
            while(a!='('){
                printf("%c",a);
                a=pop();
            }
        }
        else{
            if((top!=-1)&&(priority(stk[top])>=priority(*e))){
                a=pop();
                printf("%c",a);
                
            }
            push(*e);
        }
        e++;
    }
    
    while(top!=-1){
            a=pop();
            printf("%c",a);
            
        }
}