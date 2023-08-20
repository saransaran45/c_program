#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node*left;
    struct node*right;
}node;

node*newnode(int val){
    node*temp=malloc(sizeof(node));
    temp->data=val;
    temp->left=temp->right=NULL;
    return temp;
}



node* insert(node*root,int val){
    if(root==NULL){
        return newnode(val);
    }
    if(val<root->data) root->left=insert(root->left,val);
    if(val>root->data) root->right=insert(root->right,val);
    return root;
}

void inorder(node*root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(node*root){
    if(root!=NULL){
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node*root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}

node*minvaluenode(node*root){
    node*cur=root;
    while(cur&&cur->left!=NULL){
        cur=cur->left;
    }
    return cur;
}

void max(node*root){
    node*temp=root;
    while(temp&&temp->right!=NULL){
        temp=temp->right;
    }
    printf("Max element of the tree is %d\n",temp->data);
}

node*deletet(node*root,int val){
    if(root==NULL){
        return root;
    }
    if(val<root->data) root->left=deletet(root->left,val);
    if(val>root->data) root->right=deletet(root->right,val);
    else{
        if(root->left==NULL){
            node*temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            node*temp=root->left;
            free(root);
            return temp;
        }
        node*temp=minvaluenode(root->right);
        root->data=temp->data;
        root->right=deletet(root->right,temp->data);
    }
    return root;
}


void min(node*root){
    node*temp=root;
    while(temp&&temp->left!=NULL){
        temp=temp->left;
    }
    printf("Minimum element of the tree is %d\n",temp->data);
}

int height(node*root){
    if(root==NULL){
        return 0;
    }
    int lmax=height(root->left);
    int rmax=height(root->right);
    if(lmax>rmax) return lmax+1;
    else return rmax+1;
}

node* mirror(node*root){
    if(root!=NULL){
        mirror(root->left);
        mirror(root->right);
        node*temp=root->left;
        root->left=root->right;
        root->right=temp;
    }
    else{
        return NULL;
    }
}



int main(){
    node* root=NULL;
    int loop=1;
    int val=0;
    while(loop==1){
        printf("Enter the data=");
        scanf("%d",&val);
        root=insert(root,val);  
        printf("Enter 1 to continue=");
        scanf("%d",&loop);
    }
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    printf("Height of the tree is %d\n",height(root));
    min(root);
    mirror(root);
    inorder(root);
    return 0;
}