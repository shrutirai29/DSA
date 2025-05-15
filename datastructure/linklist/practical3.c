// Write a program to implement following operations on the circular linked list.
// (a) Insert a node at the end of the linked list.
// (b) Insert a node before specified position.
// (c) Delete a first node of the linked list.
// (d) Delete a node after specified position.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertAtEnd(){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    if(head == NULL){
        head = newNode;
        newNode->next = head;
    }else{
        struct node *temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    printf("Data inserted successfully\n");
}

void insertBeforePosition() {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    if (head == NULL) {
        head = newNode;
        newNode->next = head; 
        printf("Data inserted successfully at position 1\n");
        return;
    }
    int pos;
    printf("Enter the position before which you want to insert: ");
    scanf("%d", &pos);
    if (pos == 1) {
        struct node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
        printf("Data inserted successfully at position 1\n");
        return;
    }
    struct node *temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }
    if (temp->next == head) {
        printf("Position out of range\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Data inserted successfully before position %d\n", pos);
}

void deleteAtBeginning(){
    if(head == NULL){
        printf("List is empty\n");
    }else{
        struct node *temp = head;
        struct node *last = head;
        while(last->next != head){
            last = last->next;
        }
        head = head->next;
        last->next = head;
        free(temp);
        printf("Data deleted successfully\n");
    }
}

void deleteAfterPosition() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    int pos;
    printf("Enter the position after which you want to delete: ");
    scanf("%d", &pos);
    struct node *temp = head;
    for (int i = 1; i < pos && temp->next != head; i++) {
        temp = temp->next;
    }
    if (temp->next == head) {
        printf("No node exists after position %d\n", pos);
        return;
    }
    struct node *del = temp->next;
    temp->next = del->next;
    if (del == head) {
        head = del->next;
    }
    free(del);
    printf("Node deleted successfully after position %d\n", pos);
}

void display(){
    struct node *temp = head;
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp != head);
    printf("\n");
}

int main(){
    int choice;
    printf("1. Insert a node at the end of the linked list.\n2. Insert a node before specified position.\n3. Delete a first node of the linked list.\n4. Delete a node after specified position.\n5. Display\n6. Exit\n");
    do{
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                insertAtEnd();
                break;
            case 2:
                insertBeforePosition();
                break;
            case 3:
                deleteAtBeginning();
                break;
            case 4:
                deleteAfterPosition();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Thank you for using the program\n Made by SHRUTI RAI\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    while(choice != 6);
    return 0;
}