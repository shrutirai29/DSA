#include <stdio.h>
#define max_size 5
int top = -1;
int stack[max_size];
void push();
void pop();
void display();
void peep();
void change();
int main() {
    printf("Welcome to a stack program!!");
    int choice;
    do{
        printf("\n1.Push \n2.Pop \n3.Display \n4.Peep \n5.Change \n6.Close \n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        if(choice == 1){
            push();
        }
        else if(choice == 2){
            pop();
        }
        else if(choice == 3){
            display();
        }
        else if(choice == 4){
            peep();
        }
        else if(choice == 5){
            change();
        }
        else{
            printf("Invalid Choice!! ");
        }
    }
    while(choice != 6);
    printf("Thank You!! \n \n Made By Shruti Rai.");

    return 0;
}

void push(){
    int num;
    if(top == max_size - 1){
        printf("Stack is full\n");
    }
    else{
        printf("Enter the item: ");
        scanf("%d", &num);
        top += 1;
        stack[top] = num;
        printf("Item added!!");
    }
}

void pop(){
    int num;
    if (top == -1){
        printf("Empty stack");
    }else{
        printf("Poped element is: %d", stack[top]);
        top -= 1;
    }
}

void display(){
    if (top == -1){
        printf("Stack is empty ");
    }
    else{
        for(int i = top; i >= 0; i--){
            printf("%d \n",stack[i]);
        }
    }
}

void peep(){
    if (top == -1){
        printf("Stack is empty ");
    }
    else{
        int x;
        printf("Enter the position you want to see: ");
        scanf("%d", &x);
        if(x > (top  + 1)){
            printf("Your stack is not this big");
        }else{
            printf("Element at position %d is %d",x, stack[(top - x + 1)]);
        }
    }
}

void change(){
    if (top == -1){
        printf("Stack is empty ");
    }
    else{
        int x, new;
        printf("Enter the position you want to change: ");
        scanf("%d", &x);
        if(x > (top  + 1)){
            printf("Your stack is not this big");
        }else{
            printf("Enter the new value: ");
            scanf("%d", &new);
            stack[top -x + 1] = new;
            printf("New element at position %d is %d",x, stack[top - x +1]);
        }
    }    
}