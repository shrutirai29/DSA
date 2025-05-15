// Write a program to implement following operations on the doubly linked list.
// (a) Insert a node at the front of the linked list.
// (b) Insert a node at the end of the linked list.
// (c) Delete a last node of the linked list.
// (d) Delete a node before specified position.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;


void insertAtBeginning(){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    newNode->next = head;
    newNode->prev = NULL;
    if(head != NULL){
        head->prev = newNode;
    }
    head = newNode;
    printf("Data inserted successfully\n");
}

void insertAtEnd(){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if(head == NULL){
        newNode->prev = NULL;
        head = newNode;
    }else{
        struct node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Data inserted successfully\n");
}

void deleteAtEnd(){
    if(head == NULL){
        printf("List is empty\n");
    }else{
        struct node *temp = head;
        struct node *prev = NULL;
        while(temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
        printf("Data deleted successfully\n");
    }
}

void deleteBeforePosition() {
    if (head == NULL || head->next == NULL) {
        printf("List is empty or has only one node\n");
        return;
    }
    int pos;
    printf("Enter the position before which you want to delete: ");
    scanf("%d", &pos);
    if (pos <= 2) {
        struct node *del = head;
        head = head->next; 
        if (head != NULL) {
            head->prev = NULL; 
        }
        free(del);
        printf("Node deleted successfully\n");
        return;
    }
    struct node *temp = head;
    for (int i = 1; i < pos - 2 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    if (temp->next == NULL || temp->next->next == NULL) {
        printf("Position out of range\n");
        return;
    }
    struct node *del = temp->next; 
    temp->next = del->next;    

    if (del->next != NULL) {
        del->next->prev = temp;
    }
    free(del);
    printf("Node deleted successfully\n");
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
    int choice;
    printf("1. Insert a node at the front of the linked list.\n2. Insert a node at the end of the linked list.\n3. Delete a last node of the linked list\n4. Delete a node before specified position.\n5. Display\n6. Exit\n");
    do{
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                insertAtBeginning();
                break;
            case 2:
                insertAtEnd();
                break;
            case 3:
                deleteAtEnd();
                break;
            case 4:
                deleteBeforePosition();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Thank you for using it \nMade by SHRUTI RAI");
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    while(choice != 6);
    return 0;
}