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
}

void insertAtRandom2(){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
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
        newNode->next = prev->next;
        prev->next = newNode;
        newNode->prev = prev;
        temp->prev = newNode;
    }
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
    }
}

int main(){
    int choice;
    while(1){
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at random\n");
        printf("4. Insert at random2\n");
        printf("5. Display\n");
        printf("6. Delete at beginning\n");
        printf("7. Delete at end\n");
        printf("8. Delete at random\n");
        printf("9. Exit\n");
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
                insertAtRandom2();
                break;
            case 5:
                display();
                break;
            case 6:
                deleteAtBeginning();
                break;
            case 7:
                deleteAtEnd();
                break;
            case 8:
                deleteAtRandom();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
