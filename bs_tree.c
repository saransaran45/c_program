#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node*left;
    struct node*right;
}node;
node * newnode(int val){
    node *temp =malloc(sizeof(node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}
node * insert(node *root,int val){
    //node *temp =create_node(root,val);
    if(root==NULL){
        return (newnode(val));
    }
    if(val<root->data){
        root->left = insert(root->left,val);
    }
    if(val>root->data){
        root->right = insert(root->right,val);
    }

    return root;
}
node * inorder(node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}

int height(node *root){
    if(root == NULL){
        return 0;
    }
    int lmax,rmax;
    lmax = height(root->left);
    rmax = height(root->right);
    if(lmax > rmax){
        return lmax + 1;
    }
    else{
        return rmax + 1;
    }
}
void min(node *root){
    node *temp = root;
    while(temp && temp->left != NULL){
        temp = temp->left;
    }
    printf("The min value of the b_tree : %d\n",temp->data);
}
node * mirror(node *root){
    if(root!=NULL){
        mirror(root->left);
        mirror(root->right);
        node *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    return root;
}
node *minimal_value_node(node *root){
    node *temp = root;
    while(temp && temp->left!=NULL){
        temp = temp->left;
    }
    return temp;
}
node *deletet(node *root,int val){
    if(root==NULL){
        return root;
    }
    if(val < root->data){
        root->left = deletet(root->left,val);
    }
    else if(val > root->data){
        root->right = deletet(root->right,val);
    }
    else{
        if(root->left == NULL){
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            node * temp = root->left;
            free(root);
            return temp;
        }
        node *temp = minimal_value_node(root->right);
        root->data = temp->data;
        root->right = deletet(root->right,temp->data);
    }
    return root;
}
void main(){
    node * root = NULL;
    int loop,val,val2;
    printf("1 to insert the data:");
    scanf("%d",&loop);
    while(loop==1){
        printf("Enter the data:");
        scanf("%d",&val);
        root=insert(root,val);
        printf("Enter loop value:");
        scanf("%d",&loop);
    }
    inorder(root);
    printf("\n height of the tree : %d\n",height(root));
    min(root);
    mirror(root);
    inorder(root);
    printf("Enter the to be deleted:");
    scanf("%d",&val2);
    root = deletet(root,val2);
    inorder(root);
}