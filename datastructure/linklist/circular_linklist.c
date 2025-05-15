#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertAtBeginning(){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d", &newNode->data);
    newNode->next = head;
    head = newNode;
    printf("Data inserted successfully\n");
}

void insertAtEnd(){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data\n");
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

void insertAtRandom(){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d", &newNode->data);
    if(head == NULL){
        head = newNode;
        newNode->next = head;
    }else{
        struct node *temp = head;
        int pos;
        printf("Enter the position\n");
        scanf("%d", &pos);
        for(int i=1; i<pos-1; i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Data inserted successfully\n");
}

void display(){
    struct node *temp = head;
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp != head);
    printf("\n");
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

void deleteAtEnd(){
    if(head == NULL){
        printf("List is empty\n");
    }else{
        struct node *temp = head;
        struct node *prev = NULL;
        while(temp->next != head){
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        free(temp);
        printf("Data deleted successfully\n");
    }
}

void deleteAtRandom(){
    if(head == NULL){
        printf("List is empty\n");
    }else{
        struct node *temp = head;
        struct node *prev = NULL;
        int pos;
        printf("Enter the position\n");
        scanf("%d", &pos);
        for(int i=1; i<pos; i++){
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
        printf("Data deleted successfully\n");
    }
}

int main(){
    int choice;
    do{
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at random\n");
        printf("4. Display\n");
        printf("5. Delete at beginning\n");
        printf("6. Delete at end\n");
        printf("7. Delete at random\n");
        printf("8. Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                insertAtBeginning();
                break;
            case 2:
                insertAtEnd();
                break;
            case 3:
                insertAtRandom();
                break;
            case 4:
                display();
                break;
            case 5:
                deleteAtBeginning();
                break;
            case 6:
                deleteAtEnd();
                break;
            case 7:
                deleteAtRandom();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    while(choice != 8);
    return 0;
}