#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int rthread;
    struct tree* left;
    struct tree* right;
    int data;
}T;

void initTree(T** root);
void setLeft(T* parent, T* child);
void setRight(T* parent, T* child);
void insert(T** root, int data);
void inorder(T* root);
T* createNode(int data);

int main(){
    T* root;
    initTree(&root);
    while(1){
        printf("Enter data: ");
        int data;
        scanf("%d", &data);
        if(data < 0)
            break;
        insert(&root, data);
    }
    inorder(root);
    return 0;
}

void initTree(T** root){
    *root = (T*)malloc(sizeof(T*));
    *root = NULL;
}

T* createNode(int data){
    T* newNode = (T*)malloc(sizeof(T*));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->rthread = 1;
    return newNode;
}

void setLeft(T* parent, T* child){
    parent->left = child;
    child->right = parent;
}

void setRight(T* parent, T* child){
    child->right = parent->right;
    parent->right = child;
    parent->rthread = 0;
}

void insert(T** root, int data){
    T* newNode = createNode(data);
    if(*root == NULL){
        *root = newNode;
        return;
    }
    T** temp = root;
    while(1){
        if((*temp)->data > data){
            if((*temp)->left){
                setLeft((*temp), newNode);
                return;
            }
            (*temp) = (*temp)->left;
        }
        else{
            if(!(*temp)->rthread){
                setRight((*temp), newNode);
                return;
            }
            (*temp) = (*temp)->right;
        }
    }
}

void inorder(T* root){
    T* temp = root;
    while(temp->left){
        temp = temp->left;
    }
    while(temp){
        printf("%d ", temp->data);
        if(temp->rthread == 1)
            temp = temp->right;
        else{
            temp = temp->right;
            while(temp->left){
                temp = temp->left;
            }
        }
    }
}