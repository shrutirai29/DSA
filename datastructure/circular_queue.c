#include <stdio.h> 
#define max_size 5
int front = -1;
int rear = -1;
int queue[max_size];

void enqueue();
void dequeue();
void display();

int main(){ 
    int choice;
    printf("Welcome to a circular queue program!!\n");
    printf("\n1. Enqueue \n2. Dequeue\n3. Display\n4. Exit \n");
    do{
        printf("\nWhat do you want to do: ");
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
            printf("--------------------------------------------------------------------------------\n");
            printf("\nThank You!! \nMade by Shruti Rai");
        }
        else{
            printf("Invalid choice!!");
        }
    }while(choice != 4);

    return 0;
}

void enqueue(){
    int element;
    if((front == 0 && rear == max_size - 1) || (front == rear + 1)){
        printf("Queue is full!! \n");
    }else{
        if(front == -1){
            front = 0;
        }
        if(rear == max_size - 1){
            rear = 0;
        }else{
            rear += 1;
        }
        printf("Enter the element: ");
        scanf("%d", &element);
        queue[rear] = element;
    }
}

void dequeue(){
    if(front == -1 || front > rear){
        printf("The Queue is empty!!\n");
    }else{
        printf("%d is removed from the queue\n", queue[front]);
        if(front == rear){                //condition for only one element in the queue
            front = -1;
            rear = -1;
        }else{                            
            if(front == max_size - 1){    //condition for front to be at the end of the queue
                front = 0;
            }else{
                front += 1;
            }
        }
    }
}

void display(){
    if(front == -1 || front > rear){
        printf("The Queue is empty!!\n");
    }else{
        printf("The elements in the queue are: \n");
        if(front <= rear){                                  //condition when refilling has not been done
            for(int i = front; i <= rear; i++){
                printf("%d ", queue[i]);
            }
        }else{
            for(int i = front; i < max_size; i++){
                printf("%d ", queue[i]);
            }
            for(int i = 0; i <= rear; i++){
                printf("%d ", queue[i]);
            }
        }
    }
}