#include<stdio.h>
#include<stdlib.h>

struct node {
    int value;
    struct node *next;
};
struct node *start=NULL;
struct node * get_node(){
    struct node * new_node;
    new_node=(struct node *)malloc(sizeof(struct node *));
    printf("Enter the value: ");
    scanf("%d",&new_node->value);
    new_node->next=NULL;
    return new_node;
}

void create(int n){
    int i;
    struct node *linked=NULL, *temp;
    for (i=0;i<n;i++){
        linked=get_node();
        if (start==NULL){
            start=linked;
        }
        else{
            temp=start;
            while (temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=linked;
        }

    }

    
    
}
void display(){
    struct node *ptr;
    ptr=start;
    while (ptr!=NULL){
        printf("%d\t",ptr->value);
        ptr=ptr->next;
    }
}

void insert(int n){
	struct node *new,*ptr;
	new=get_node();
	ptr=start;
	while(ptr->value!=n){
		ptr=ptr->next;
		}
		new->next=ptr->next;
	ptr->next=new;	
	}
void delete(int n){
	struct node *ptr,*preptr;
	ptr=start;
	preptr=NULL;
	while(ptr->value!=n){
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	
}

int main(){
	int option;
	printf("Enter the option : \n1.Create\n2.Insert\n3.delete\n4.Display\n5.Exit\n");
		scanf("%d",&option);
	int a,b,c;
	while(option!=5){	
		switch (option){
			case 1:
		
			printf("Enter the number of elements : ");
			scanf("%d",&a);
			create(a);break;
			case 2:
			
			printf("Enter the element after which you want to insert : ");
			scanf("%d",&b);
			insert(b);break;
			case 3:
			
			printf("Enter the element you want to delete : ");
			scanf("%d",&c);
			delete(c);break;
			case 4:
			display();
			break;
		}
		printf("Enter the option : \n1.Create\n2.Insert\n3.delete\n4.Display\n5.Exit\n");
		scanf("%d",&option);
		
	}
	printf("Thank you");
	
       /* create(6);
        insert(3);
        delete(69);
        display();
        return 0;*/
    }
