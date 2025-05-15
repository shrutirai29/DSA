#include <stdio.h>
#define max_size 5

void enqueue();
void dequeue();
void display();
void queueSort();
void bubbleSort(int arr[], int n);

int front = -1;
int rear = -1;
int queue[max_size];

int main() {
    printf("Welcome to a queue program!!\n");
    int choice;
    printf("\n1. Enqueue \n2. Dequeue\n3. Display\n4. Sorting\n5. Exit\n");

    do {
        printf("\nWhat do you want to do: ");
        scanf("%d", &choice);

        if (choice == 1) {
            enqueue();
        } else if (choice == 2) {
            dequeue();
        } else if (choice == 3) {
            display();
        } else if (choice == 4) {
            queueSort();
        } else if (choice == 5) {
            printf("Thank You!! \nMade by Shruti Rai\n");
        } else {
            printf("Invalid choice!!");
        }
    } while (choice != 5);

    return 0;
}

void enqueue() {
    int element;
    if (rear == max_size - 1) {
        printf("Queue is full!!");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear += 1;
        printf("Enter the element: ");
        scanf("%d", &element);
        queue[rear] = element;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("The Queue is empty!!");
    } else {
        printf("%d is removed from the queue\n", queue[front]);
        front += 1;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("The Queue is empty!!");
    } else {
        printf("Elements of the queue are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void queueSort() {
    if (front == -1 || front > rear) {
        printf("The Queue is empty!!");
        return;
    }

    bubbleSort(&queue[front], rear - front + 1);
    printf("Queue has been sorted!\n");
}
