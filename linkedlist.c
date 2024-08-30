#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node *) malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> next = NULL;
    return newNode;
}

Node* insertAtHead(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head) 
        newNode -> next = *head;
    *head = newNode;
    return newNode;
}

Node* getTail(Node* head) {
    if (head != NULL) {
        while(head -> next) {
            head = head -> next;
        }
    }    
    return head;
}

Node* insertAtTail(Node** head, int value) {
    Node* tail = getTail(*head);
    Node* newNode = createNode(value);
    if (tail == NULL) {
        *head = newNode;
    }
    else {
        tail -> next = newNode;
    }
    return newNode;
}

Node* insertAfter(Node* head, int value) {
    
}

void iterate(Node* head) {
    while (head) {
        printf("%d -> ", head -> data);
        head = head -> next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    int values[] = {-53, 32, 107, 13};

    for (int i = 0 ; i < 4 ; i++) {
        if (insertAtHead(&head, values[i])) {
            printf("Successfully inserted %d at head\n", values[i]);
        }
        else {
            printf("Failed to insert %d at head\n", values[i]);
        }
    }

    for (int i = 0 ; i < 4 ; i++) {
        if (insertAtTail(&head, values[i])) {
            printf("Successfully inserted %d at tail\n", values[i]);
        }
        else {
            printf("Failed to insert %d at tail\n", values[i]);
        }
    }
    

    iterate(head);
    return 0;
}