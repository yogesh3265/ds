#include <stdio.h>
#define MAX 100
int arr[MAX], n;
void display() {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void insert(int pos, int val) {
    if (pos > n || pos < 0) {
        printf("Invalid position\n");
        return;
    }
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    n++;
}
void delete(int pos) {
    if (pos >= n || pos < 0) {
        printf("Invalid position\n");
        return;
    }
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}
int search(int val) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            return i;
        }
    }
    return -1;
}
int main() {
    n = 5;
    arr[0] = 10; arr[1] = 20; arr[2] = 30; arr[3] = 40; arr[4] = 50;
    
    printf("Array before operations: ");
    display();

    insert(2, 25);  // Insert 25 at position 2
    printf("Array after insertion: ");
    display();

    delete(3);  // Delete element at position 3
    printf("Array after deletion: ");
    display();

    int pos = search(25);  // Search for element 25
    if (pos != -1)
        printf("Element 25 found at position %d\n", pos);
    else
        printf("Element not found\n");

    return 0;
}
