#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

struct queue{
    struct node *front;
    struct node *rear;
};

struct queue *q;
struct queue create_queue(struct queue *);
struct queue *insert(struct queue *,int val);
struct queue *delete(struct queue *);
struct queue *display(struct queue *);

int main(){
    int option,val;
    create_queue(q);
    do{
        printf("\n****main**** ");
        printf("\n 1. INSERT");
        printf("\n 2. DELETE");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT");
        printf("\n Enter your option : ");
        scanf("%d", &option);
        switch(option){
            case 1:
                printf("Entert the value to be inserted");
                scanf("%d",&val);
                q = insert(q,val);
                break;
            case 2:
                q = delete(q);
                break;
            case 3:
                val = peek(q);
                if(val!=-1){
                    printf("the first value : %d",val);
                }
                break;
            case 4:
                q = display(q) ;
                break;
        }
    }
    while(option != 5);{}
        getch();
        return 0;
    
}

struct queue create_queue (struct queue *q){
    q->front = NULL;
    q->rear = NULL;
}

struct queue *insert(struct queue *q,int val){
    struct node *ptr;
    ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = val;
    if(q->front == NULL){
        q->front = q->rear = ptr;
        q->front->next = q->rear->next = NULL;
    }
    else{
        q->rear->next = ptr;
        q->rear = ptr;
        q->rear->next = NULL;
    }
    return q;
}

struct queue *delete(struct queue *q){
    struct node *ptr;
    ptr = q;
    if(q->front == NULL){
        printf("Queue is empty");
    }
    else{
        q->front = q->front->next;
        printf("the deleted element : %d",ptr->data);
        free(ptr);
    }
    return q;
}

struct queue *display(struct queue *q){
    struct node *ptr;
    ptr = q;
    if(ptr == NULL){
        printf("queue is empty");
    }
    else{
        while(ptr!=q->rear){
            printf("%d \t",ptr->data);
            ptr = ptr->next;
        }    
        printf("%d",ptr->data);
        return q;
    }
}

/*struct queue *peek(struct queue *q);{
    if(q->front == NULL){
        printf("Queue is empty");
    }
    else
        return q->front->data;
    
}*/
