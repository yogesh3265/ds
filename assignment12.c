#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10
struct Node {
    int key;
    int value;
    struct Node* next;
};
struct HashTable {
    struct Node* table[TABLE_SIZE];
};  // Initialize the hash table
void initTable(struct HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
}// Hash function
int hash(int key) {
    return key % TABLE_SIZE;
}// Insert a key-value pair into the hash table
void insert(struct HashTable* ht, int key, int value) {
    int index = hash(key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}// Search for a value by key in the hash table
int search(struct HashTable* ht, int key) {
    int index = hash(key);
    struct Node* temp = ht->table[index];
    while (temp != NULL) {
        if (temp->key == key) {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1; // Not found
}// Delete a key-value pair from the hash table
void delete(struct HashTable* ht, int key) {
    int index = hash(key);
    struct Node* temp = ht->table[index];
    struct Node* prev = NULL;
    while (temp != NULL && temp->key != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Key not found\n");
        return;
    }
    if (prev == NULL) {
        ht->table[index] = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}// Print the hash table
void printTable(struct HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct Node* temp = ht->table[i];
        printf("Index %d: ", i);
        while (temp != NULL) {
            printf("(%d, %d) -> ", temp->key, temp->value);
            temp = temp->next;
        }
        printf("NULL\n");
    }  }
int main() {
    struct HashTable ht;
    initTable(&ht); 
    insert(&ht, 1, 100);
    insert(&ht, 2, 200);
    insert(&ht, 12, 300);
    printf("Hash Table:\n");
    printTable(&ht);
    printf("Search for key 2: %d\n", search(&ht, 2));
    delete(&ht, 2);
    printf("After deleting key 2:\n");
    printTable(&ht);
    return 0;
}
