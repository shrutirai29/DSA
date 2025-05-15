#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* root = NULL;

void insert(){
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    newNode->left = NULL;
    newNode->right = NULL;
    
    if(root == NULL){
        root = newNode;
    }else{
        struct TreeNode* temp = root;
        while(1){
            if(newNode->data < temp->data){
                if(temp->left == NULL){
                    temp->left = newNode;
                    break;
                }else{
                    temp = temp->left;
                }
            }else{
                if(temp->right == NULL){
                    temp->right = newNode;
                    break;
                }else{
                    temp = temp->right;
                }
            }
        }
    }
}

void deleteNode(){
    int data;
    printf("Enter the data to be deleted: ");
    scanf("%d", &data);
    struct TreeNode* temp = root;
    struct TreeNode* parent = NULL;
    while(temp != NULL && temp->data != data){
        parent = temp;
        if(data < temp->data){
            temp = temp->left;
        }else{
            temp = temp->right;
        }
    }
    if(temp == NULL){
        printf("Node not found\n");
        return;
    }
    if(temp->left == NULL && temp->right == NULL){
        if(parent == NULL){
            root = NULL;
        }else if(parent->left == temp){
            parent->left = NULL;
        }else{
            parent->right = NULL;
        }
    }else if(temp->left == NULL || temp->right == NULL){
        struct TreeNode* child = (temp->left != NULL) ? temp->left : temp->right;
        if(parent == NULL){
            root = child;
        }else if(parent->left == temp){
            parent->left = child;
        }else{
            parent->right = child;
        }
    }else{
        struct TreeNode* successorParent = temp;
        struct TreeNode* successor = temp->right;
        while(successor->left != NULL){
            successorParent = successor;
            successor = successor->left;
        }
        temp->data = successor->data;
        if(successorParent->left == successor){
            successorParent->left = successor->right;
        }else{
            successorParent->right = successor->right;
        }
    }
    free(temp);
}

void search(){
    int data;
    printf("Enter the data to be searched: ");
    scanf("%d", &data);
    struct TreeNode* temp = root;
    while(temp != NULL){
        if(data == temp->data){
            printf("Node found\n");
            return;
        }else if(data < temp->data){
            temp = temp->left;
        }else{
            temp = temp->right;
        }
    }
    printf("Node not found\n");
}


int main(){
    printf("Binary Tree\n");
    printf("1. Insert a node\n2. Delete a node\n3. Search a node\n5. Exit\n");
    int choice;
    do{
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Insert a node\n");
                insert();
                break;
            case 2:
                printf("Delete a node\n");
                deleteNode();
                break;
            case 3:
                printf("Search a node\n");
                search();
                break;
            case 4:
                printf("Exit\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    while(choice != 4);
    return 0;   
}