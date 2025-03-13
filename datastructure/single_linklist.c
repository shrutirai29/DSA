#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//structure of a node
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

//function to insert at beginning
void insertAtBeginning(){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));     //creation of node
    printf("Enter the data\n");
    scanf("%d", &newNode->data);
    newNode->next = head;                                                //old data of head is given to the next of newNode
    head = newNode;                                                     //newNode is the new head
}

//function to insert at end
void insertAtEnd(){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));    //creation of node
    printf("Enter the data\n");
    scanf("%d", &newNode->data);
    newNode->next = NULL;                                               //as it is the last node
    if(head == NULL){                                                   
        head = newNode;                                                // if no head is present then newNode = head = last
    }else{
        struct node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;                                        //searching for last node
        }
        temp->next = newNode;
    }
}

//function to insert at ramdom position using a counter position
void insertAtRandom(){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));   //creation of node
    printf("Enter the data\n");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if(head == NULL){                                                  // if no head is present then newNode = head = last = node at ramdom position
        head = newNode;
    }else{
        struct node *temp = head;
        int pos;
        printf("Enter the position\n");
        scanf("%d", &pos);
        for(int i=1; i<pos-1; i++){                                  //going to the required position
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

//function to insert at random position (ascending order insetion)
void insertAtRandom2(){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));   // creation of node
    printf("Enter the data\n");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;                                               //if no head is present then newNode = head = last = node at ramdom position
    }else{
        struct node *temp = head;
        struct node *prev = NULL;
        while(newNode->data > temp->data){                           //searching for the node with data less than data of new node
            prev = temp;
            temp = temp->next;
        }
        newNode->next = prev->next;
        prev->next = newNode;
    }
}

//function to display data
void display(){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//
void deleteAtBeginning(){
    if(head == NULL){
        printf("List is empty\n");
    }else{
        struct node *temp = head;
        head = head->next;
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
        free(temp);
    }
}

int main(){
    printf("Welcome to the single linlist program\n");
    int choice;
    printf("1. Insert at the beginning\n2. Insert at the end \n3. Insert at random position(using count)\n4.Insert at random position(ascending order)\n5. Display\n6. Delete at the beginning\n7.Delete at the end\n8. Delete at random\n9. Exit\n");
    do{    
        printf("What do you want to do?\n");
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
                printf("Exiting\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice != 9);
    return 0;
}
