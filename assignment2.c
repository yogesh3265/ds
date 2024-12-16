#include <stdio.h>
#define MAX 100
int stack[MAX], top = -1;
void push(int val) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = val;
        printf("%d pushed to stack\n", val);
    }
}
void pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
    } else {
        printf("%d popped from stack\n", stack[top--]);
    }
}
int search(int val) {
    for (int i = top; i >= 0; i--) {
        if (stack[i] == val) {
            return i;
        }
    }
    return -1;
}
void display() {
    if (top < 0) {
        printf("Stack is empty\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
int main() {
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    int pos = search(20);
    if (pos != -1)
        printf("Element found at position %d\n", pos);
    else
        printf("Element not found\n");
    return 0;
}
