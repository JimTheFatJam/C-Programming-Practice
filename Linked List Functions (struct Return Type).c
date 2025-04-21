#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

void printList(struct Node* head) {
    struct Node* curr = head;

    while (curr != NULL) {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

struct Node* insertAtFront(struct Node* head, int new_data) {
    struct Node* new_node = createNode(new_data);
    new_node->next = head;
    return new_node;
}

struct Node* append(struct Node* head, int new_data) {
    struct Node* new_node = createNode(new_data);

    if(head == NULL) {
        return new_node;
    }

    struct Node* last = head;
    while(last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;

    return head;
}

struct Node* insertPos(struct Node* head, int pos, int new_data) {
    if(pos < 1) {
        return head;
    }

    if(pos == 1) {
        struct Node* new_node = createNode(new_data);
        new_node->next = head;
        return new_node;
    }

    struct Node* curr = head;
    for(int i = 1; i < pos - 1 && curr != NULL; i++) {
        curr = curr->next;
    }

    if(curr == NULL) {
        return head;
    }

    struct Node* new_node = createNode(new_data);
    new_node->next = curr->next;
    curr->next = new_node;

    return head;
}

struct Node* deleteHead(struct Node* head) {
    if(head == NULL)
        return NULL;

    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node* deleteEnd(struct Node* head) {
    if(head == NULL)
        return NULL;

    if(head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* second_last = head;
    while(second_last->next->next != NULL) {
        second_last = second_last->next;
    }

    free(second_last->next);
    second_last->next = NULL;

    return head;
}

struct Node* deletePos(struct Node* head, int pos) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    if(head == NULL)
        return head;

    if(pos == 1) {
        head = temp->next;
        free(temp);
        return head;
    }

    for(int i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        return head;
    }

    prev->next = temp->next;
    free(temp);

    return head;
}

int main() {
    //Create the linked list 2->3->4->5
    struct Node* head = createNode(2);
    head->next = createNode(3);
    head->next->next = createNode(4);
    head->next->next->next = createNode(5);

    //Print the original list
    printf("Original Linked list:\n");
    printList(head);

    //Insert new node at front
    printf("\nAfter insertion at front:\n");
    int data = 1;
    head = insertAtFront(head, data);
    printList(head);

    //Insert new node at end
    printf("\nAfter insertion at end:\n");
    data = 6;
    head = append(head, data);
    printList(head);

    //Insert new node at specific position
    printf("\nAfter insertion at specific position:\n");
    int pos = 3;
    data = 69;
    head = insertPos(head, pos, data);
    printList(head);

    //Delete front node
    printf("\nAfter deletion at front:\n");
    head = deleteHead(head);
    printList(head);

    //Delete end node
    printf("\nAfter deletion at end:\n");
    head = deleteEnd(head);
    printList(head);

    //Delete node at specific position
    printf("\nAfter deletion at specific position:\n");
    pos = 2;
    head = deletePos(head, pos);
    printList(head);

    return 0;
}
