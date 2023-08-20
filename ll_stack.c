#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node*next;
}node;

node*top=NULL;

node*newnode(){
    node*temp=malloc(sizeof(node));
    printf("Enter the data=");
    scanf("%d",&temp->data);
    temp->next=top;
    return temp;
}

void push(){
    int c=1;
    while(c==1){
        node*temp=newnode();
        if(temp==NULL){
            printf("Stack Overflow\n");
            exit(1);
        }
        top=temp;
        printf("Enter 1 to continue=");
        scanf("%d",&c);
    }
}

void print(){
    node*temp=top;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int pop(){
    node*temp=top;
    int val=temp->data;
    top=top->next;
    free(temp);
    temp=NULL;
    return val;
}

void peek(){
    node*temp=top;
    printf("The peek element is %d\n",temp->data);
}

int main(){
    int choice=1;
    while(choice<12){
        switch(choice){
            case 1:
                push();
                break;
            case 2:
                print();
                break;
            case 3:
                int a=pop();
                printf("The deleted element is %d\n",a);
                break;
            case 4:
                printf("Program Ends\n");
                exit(1);
            case 5:
                peek();
                break;
        }
        printf("Enter your choice=");
        scanf("%d",&choice);
    }
    return 0;
}