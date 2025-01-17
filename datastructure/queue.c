#include<stdio.h>
#define max_size 5
void enqueue();
void dequeue();
void display();
int front = -1;
int rear = -1;
int queue[max_size];

int main(){
    printf("Welcome to a queue program!!\n");
    int choice;
    printf("\n1. Enqueue \n2. Dequeue\n3. Display\n4. Exit \n");
    do{
        printf("What do you want to do: ");
        scanf("%d", &choice);
        if(choice == 1){
            enqueue();
        }
        else if(choice == 2){
            dequeue();
        }
        else if(choice == 3){
            display();
        }
        else if(choice == 4){
            printf("Thank You!! \n Made by Shruti Rai");
        }
        else{
            printf("Invalid choice!!");
        }
    }
    while(choice != 4);

    return 0;
}

void enqueue(){
    int element;
    if(rear == max_size - 1){
        printf("Stack is full!!");
    }else{
        if(front == -1){
            front = 0;
        }
        rear += 1;
        printf("Enter the element: ");
        scanf("%d", &element);
        queue[rear] = element;
    }
}

void dequeue(){
    if(front == -1 || front > rear){
        printf("The Queue is empty!!");
    }else{
        printf("%d is removed from the queue", queue[front]);
        front += 1;
    }
}

void display(){
     if(front == -1 || front > rear){
        printf("The Queue is empty!!");
    }else{
        printf("Elements of the queue are: ");
        for(int i = front; i <= rear; i++){
            printf("%d ", queue[i]);
        }
    }
}