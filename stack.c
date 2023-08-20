#include<stdio.h>
//implementation of stack using array
#define n 5
int stack[n];
int top=-1;
void push(int a){
    if(top==n-1){
        printf("Stack Overflow ");
    }
    else{
    printf("Enter the data to push : ");
    scanf("%d",&a);
    top++;
    stack[top]=a;
    } 
}
void pop(){
    int b;
    if(top==-1){
        printf("Underflow");
    }
    else{
        b=stack[top];
        top--;
    }
    printf("The last item is %d\n",b);
}
void display(){
    int i;
    printf("The data is : ");
    for(i=top;i>=0;i--){
        printf("%d\t",stack[i]);
    }
}

void main(){
    push(2);
    push(3);
    push(4);
    pop();
    display();
}