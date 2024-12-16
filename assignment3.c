#include <stdio.h>
#define MAX 5
int queue[MAX], front = -1, rear = -1;
void enqueue(int val) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        queue[++rear] = val;
        printf("%d enqueued to queue\n", val);
    }    }
void dequeue() {
    if (front == rear) {
        printf("Queue Underflow\n");
    } else {
        printf("%d dequeued from queue\n", queue[front++]);
    }    }
int search(int val) {
    for (int i = front; i <= rear; i++) {
        if (queue[i] == val) {
            return i;
        }     }
    return -1;
}
void display() {
    if (front == rear) {
        printf("Queue is empty\n");
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }      }
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    int pos = search(20);
    if (pos != -1)
        printf("Element found at position %d\n", pos);
    else
        printf("Element not found\n");
    return 0;
}
