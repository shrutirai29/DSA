#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

int main(){
    printf("Welcome to stack using linklist program\n");
    printf("1. Push\n2. Pop\n3. Display\n4. Peep\n5. Exit\n");
    int choice;
    do{
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Push operation\t");
                struct node *newNode = (struct node*)malloc(sizeof(struct node));
                printf("Enter the data: ");
                scanf("%d", &newNode->data);
                newNode->next = top;
                top = newNode;
                printf("Data inserted successfully\n");
                break;
            case 2:
                printf("Pop operation\t");
                if(top == NULL){
                    printf("Stack is empty\n");
                }else{
                    struct node *temp = top;
                    top = top->next;
                    free(temp);
                    printf("Data deleted successfully\n");
                }
                break;
            case 3:
                printf("Display operation\t");
                if(top == NULL){
                    printf("Stack is empty\n");
                }else{
                    struct node *temp = top;
                    while(temp != NULL){
                        printf("%d ", temp->data);
                        temp = temp->next;
                    }
                    printf("\n");
                }
                break;
            case 4:
                printf("Peep operation\t");
                if (top == NULL) {
                    printf("Stack is empty\n");
                } else {
                    printf("Enter the position: ");
                    int pos;
                    scanf("%d", &pos);
                    
                    struct node *temp = top;
                    int count = 1;  // Position counter
                    
                    // Traverse the linked list safely
                    while (count < pos && temp != NULL) {
                        temp = temp->next;
                        count++;
                    }
                    
                    if (temp == NULL) {
                        printf("Invalid position\n");  // Safe check added
                    } else {
                        printf("Data at position %d is %d\n", pos, temp->data);
                    }
                }
                break;            
            case 5:
                printf("Exit\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice != 5);
}