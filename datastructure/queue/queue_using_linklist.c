#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

int main(){
    printf("Welcome to queue using linklist program\n");
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    int choice;
    do{
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enqueue operation\t");
                struct node *newNode = (struct node*)malloc(sizeof(struct node));
                printf("Enter the data: ");
                scanf("%d", &newNode->data);
                newNode->next = NULL;
                if(front == NULL && rear == NULL){
                    front = rear = newNode;
                }else{
                    rear->next = newNode;
                    rear = newNode;
                }
                printf("Data inserted successfully\n");
                break;
            case 2:
                printf("Dequeue operation\t");
                if(front == NULL && rear == NULL){
                    printf("Queue is empty\n");
                }else{
                    struct node *temp = front;
                    front = front->next;
                    free(temp);
                    printf("Data deleted successfully\n");
                }
                break;
            case 3:
                printf("Display operation\t");
                if(front == NULL && rear == NULL){
                    printf("Queue is empty\n");
                }else{
                    struct node *temp = front;
                    while(temp != NULL){
                        printf("%d ", temp->data);
                        temp = temp->next;
                    }
                    printf("\n");
                }
                break;
            case 4:
                printf("Exit operation\t");
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice != 4);
    return 0;
}