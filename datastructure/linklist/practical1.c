// Write a menu driven program to implement following operations on the singly linked list.
// (a) Insert a node at the front of the linked list.
// (b) Insert a node at the end of the linked list.
// (c) Insert a node such that linked list is in ascending order.(according to info. Field)
// (d) Delete a first node of the linked list.
// (e) Delete a node before specified position.
// (f) Delete a node after specified position.
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertAtBeginning(){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
    }else{
        struct node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertInAscending() {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if (head == NULL || newNode->data < head->data) {
        newNode->next = head;
        head = newNode;
        return;
    }
    struct node *temp = head;
    struct node *prev = NULL;
    while (temp != NULL && temp->data < newNode->data) {
        prev = temp;
        temp = temp->next;
    }
    newNode->next = temp;
    prev->next = newNode;
}

void deleteAtBeginning(){
    if(head == NULL){
        printf("List is empty\n");
    }else{
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
}

void deleteBeforePosition(){
    if(head == NULL || head->next == NULL){
        printf("List is empty or has only one node\n");
        return;
    }
    int pos;
    printf("Enter the position before which you want to delete: ");
    scanf("%d", &pos);
    if(pos == 1){
        printf("No node before the first node\n");
        return;
    }
    struct node *temp = head;
    struct node *prev = NULL;
    for(int i = 1; i < pos - 1 && temp != NULL; i++){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Position out of range\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void deleteAfterPosition(){
    if(head == NULL || head->next == NULL){
        printf("List is empty or has only one node\n");
        return;
    }
    int pos;
    printf("Enter the position after which you want to delete: ");
    scanf("%d", &pos);
    struct node *temp = head;
    for(int i = 1; i < pos && temp != NULL; i++){
        temp = temp->next;
    }
    if(temp == NULL || temp->next == NULL){
        printf("Position out of range or no node after the specified position\n");
        return;
    }
    struct node *toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

void display(){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main(){
    printf("Welcome to the single linlist program\n");
    int choice;
    printf("1. Insert a node at the front of the linked list.\n2. Insert a node at the end of the linked list. \n3. Insert a node such that linked list is in ascending order.\n4. Delete a first node of the linked list.\n5. Delete a node before specified position.\n6. Delete a node after specified position.\n7. Display\n8. Exit\n");
    do{    
        printf("\n What do you want to do?: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                insertAtBeginning();
                break;
            case 2:
                insertAtEnd();
                break;
            case 3:
                insertInAscending();
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteBeforePosition();
                break;
            case 6:
                deleteAfterPosition();
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting\n Made by Shruti\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice != 8);
    return 0;
}