#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push();
void pop();
void peek();
void display();

int main() {
    int ch;
    while (1) {
        printf("\n 1. PUSH\n 2. POP\n 3. PEEK\n 4. DISPLAY\n 5. EXIT\n");
        printf(" Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}

void push() {
    int val;
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        printf("Enter value to push: ");
        scanf("%d", &val);
        top++;
        stack[top] = val;
        printf("%d pushed in stack.\n", val);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
    } else {
        printf("%d popped from stack.\n", stack[top]);
        top--;
    }
}

void peek() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element is %d\n", stack[top]);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
