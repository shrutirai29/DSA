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
    printf("Enter the data\n");
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
    printf("Enter the data\n");
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

void insertAtRandom(){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
    }else{
        struct node *temp = head;
        int pos;
        printf("Enter the position\n");
        scanf("%d", &pos);
        for(int i=1; i<pos-1; i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
    }
    printf("Data inserted successfully\n");
}

void display(){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteAtBeginning(){
    if(head == NULL){
        printf("List is empty\n");
    }else{
        struct node *temp = head;
        head = head->next;
        head->prev = NULL;
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
        while(temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
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
        temp->next->prev = prev;
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
