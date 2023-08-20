#include <stdio.h>
#include <stdlib.h>
struct queue{
    int data;
    struct queue *next;
};
struct queue *front=NULL;
struct queue *rear=NULL;
struct queue *getnode(int b){
    struct queue *newnode;
    newnode=(struct queue*)malloc(sizeof(struct queue));
    printf("Enter the data : ");
    scanf("%d",&b);
    newnode->data=b;
    newnode->next=NULL;
    return newnode;
}
void enqueue(int a){
    struct queue *linked=NULL;
    linked=getnode(a);
    if(front==NULL && rear==NULL){
        front=rear=linked;
    }
    else{
        rear->next=linked;
        rear=linked;
    }
}
void dequeue(){
    printf("The dequeued element is : %d\n",front->data);
    front=front->next;
}
void display(){
   struct queue *ptr;
   ptr=front;
   while(ptr!=NULL){
    printf("%d\t",ptr->data);
    ptr=ptr->next;
   }
}
void main(){
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    dequeue();
    dequeue();
    display();
}
