#include<stdio.h>
#include<stdlib.h>

struct Node {               // Node structure for linked list
    int data;               // Data field can store any type of data and any value
    struct Node* next;      // Node pointer that links to the next node
};

struct Node* createNode(int new_data) {                                     // Function to create new node in linked list
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));      // Allocate memory for new node

    if(new_node == NULL) {                              // Check is memory allocation was successful
        printf("\nMemory allocation failed!\n");        // Print error message
        exit(EXIT_FAILURE);                             // Exit program
    }

    new_node->data = new_data;      // Assign the given data to the new node's data field
    new_node->next = NULL;          // Initialize the next pointer to NULL
    return new_node;                // Return the pointer to the newly created node
};

void printList(struct Node* head) {     // Function to print the elements of a linked list
    struct Node* curr = head;           // Create a temporary pointer to traverse the list,
                                        // starting at the head

    while (curr != NULL) {              // Traverse the linked list until NULL is reached
        printf("%d->", curr->data);     // Print the current node's data
        curr = curr->next;              // Move to the next node in the list
    }
    printf("NULL\n");                   // Print "NULL" to indicate end
}

void insertAtFront(struct Node** head, int new_data) {  // Function to insert a new node at the front of the linked list
    struct Node* new_node = createNode(new_data);       // Create new node with given data
    new_node->next = *head;                             // Make the next pointer of the new node point to the current head
    *head = new_node;                                   // Update the head pointer to point to the new node,
}                                                       // making it the new head

void append(struct Node** head, int new_data) {         // Function to insert a new node at the end of the linked list
    struct Node* new_node = createNode(new_data);       // Create new node with given data

    if(*head == NULL) {         // If list is empty, make the new node the head
        *head = new_node;       // Assign the new node as the head
        return;                 // Exit function
    }

    struct Node* last = *head;
    while(last->next != NULL) {     // Traverse the linked list until the last node
        last = last->next;          // Move to the next node
    }

    last->next = new_node;           // Change the next pointer of the last node to point to the new node
}

void insertPos(struct Node** head, int pos, int new_data) {     // Function to insert a new node at a specific
                                                                // position in the linked list
    if(pos < 1) return;                                     // Return if the given position is invalid (less than 1)

    struct Node* new_node = createNode(new_data);           // Create a new node with the given data

    if(pos == 1) {                      // If inserting at position 1, update the head of the list (insertAtFront)
        new_node->next = *head;         // Make the next pointer of the new node point to the current head
        *head = new_node;               // Update the head pointer to point to the new node, making it the new head
        return;
    }

    struct Node* curr = *head;
    for(int i = 1; i < pos - 1 && curr != NULL; i++) {      // Traverse to the node that will be just before the new node
        curr = curr->next;                                  // Move to the next node
    }

    if(curr == NULL) return;            // If the position is greater than the number of nodes, return without inserting

    new_node->next = curr->next;        // Update the next pointers to insert the new node at the correct position
    curr->next = new_node;
}

void deleteHead(struct Node** head) {       // Function to delete the node at the front of the linked list
    if(*head == NULL) return;               // Return if list is empty (nothing to delete)

    struct Node* temp = *head;              // Store the current head node in a temporary variable
    *head = (*head)->next;                  // Move the head pointer to the next node in the list

    free(temp);                             // Free the memory allocated for the old head node
}

void deleteEnd(struct Node** head) {        // Function to delete the node at the end of the linked list
    if(*head == NULL) return;               // Return if list is empty (nothing to delete)

    if((*head)->next == NULL) {             // If only one node in the list
        free(*head);                        // Free the only node
        *head = NULL;                       // Set head to NULL since the list is now empty
        return;
    }

    struct Node* second_last = *head;
    while(second_last->next->next != NULL) {    // Traverse to the second last node
        second_last = second_last->next;        // Move to the next node
    }

    free(second_last->next);                    // Free memory of the last node (node after second_last)
    second_last->next = NULL;                   // Change the next pointer of the second-to-last node to NULL
}

void deletePos(struct Node** head, int pos) {       // Function to delete a node at a given position in the linked list
    if(*head == NULL) return;                       // Return if list is empty (nothing to delete)

    struct Node* temp = *head;                  // Temporary pointer to traverse the list
    struct Node* prev = NULL;                   // Pointer to store the previous node

    if(pos == 1) {                  // If the node to be deleted is the head (position 1)
        *head = temp->next;         // Move the head pointer to the next node
        free(temp);                 // Free memory of the old head node
        return;
    }

    for(int i = 1; i < pos && temp != NULL; i++) {      // Traverse the list to find the node at the given position
        prev = temp;                                    // Store the previous node
        temp = temp->next;                              // Move to the next node
    }

    if(temp == NULL) return;        // If the position is greater than the number of nodes, return

    prev->next = temp->next;        // Update the next pointer of the previous node to skip the node to be deleted
    free(temp);                     // Free memory of the node to be deleted
}

int getLength(struct Node* head) {      // Function to get the number of nodes of linked list
    int len = 0;                        // Initialize a counter 'len' to store the length of the list

    struct Node* curr = head;
    while(curr != NULL) {               // Traverse the linked list until NULL is reached
        len++;                          // Increment the length counter for each node
        curr = curr->next;              // Move to the next node
    }

    return len;                         // Return the total number of nodes in the list
}

void bubbleSort(struct Node** head) {           // Function to sort linked list with bubble sort
    int swapped;                                // Flag to check if any swapping was done in an iteration
    struct Node* curr = NULL;                   // Pointer to track the current node
    struct Node* last_sorted =  NULL;           // Marks the last sorted node (boundary for comparisons)

    if(*head == NULL || (*head)->next == NULL)   // Return if the list is empty or if only one node in the list
        return;

    do {
        swapped = 0;            // Reset swapped flag at the start of each iteration
        curr = *head;           // Start traversing from the head

        while(curr->next != last_sorted) {                  // Traverse the list until the last sorted node

            if (curr->data > curr->next->data) {        // Compare adjacent nodes
                swapData(curr, curr->next);             // Swap if out of order
                swapped = 1;                            // Set swapped flag to indicate a change
            }

            curr = curr->next;    // Move to the next node
        }

        last_sorted = curr;     // Move the last sorted boundary one step back
    } while(swapped);           // Continue until no swaps occur
}

void swapData(struct Node* nodeA, struct Node* nodeB) {         // Function to swap the data of two nodes
    int temp = nodeA->data;                 // Store nodeA's data in a temporary variable
    nodeA->data = nodeB->data;              // Assign nodeB's data to nodeA
    nodeB->data = temp;                     // Assign temp (original nodeA data) to nodeB
}

int main() {
    // Create the linked list 2->3->4->5
    struct Node* head = createNode(12);
    head->next = createNode(15);
    head->next->next = createNode(9);
    head->next->next->next = createNode(3);

    // Print the original list
    printf("Original Linked list:\n");
    printList(head);
    printf("Size: %d\n", getLength(head));

    // Insert new node at front
    printf("\nAfter insertion at front:\n");
    int data = 1;
    insertAtFront(&head, data);
    printList(head);
    printf("Size: %d\n", getLength(head));

    // Insert new node at end
    printf("\nAfter insertion at end:\n");
    data = 6;
    append(&head, data);
    printList(head);
    printf("Size: %d\n", getLength(head));

    // Insert new node at specific position
    printf("\nAfter insertion at specific position:\n");
    int pos = 3;
    data = 69;
    insertPos(&head, pos, data);
    printList(head);
    printf("Size: %d\n", getLength(head));

    // Delete front node
    printf("\nAfter deletion at front:\n");
    deleteHead(&head);
    printList(head);
    printf("Size: %d\n", getLength(head));

    // Delete end node
    printf("\nAfter deletion at end:\n");
    deleteEnd(&head);
    printList(head);
    printf("Size: %d\n", getLength(head));

    // Delete node at specific position
    printf("\nAfter deletion at specific position:\n");
    pos = 2;
    deletePos(&head, pos);
    printList(head);
    printf("Size: %d\n", getLength(head));

    // Sort linked list with bubble sort
    printf("\nAfter sorting list:\n");
    bubbleSort(&head);
    printList(head);
    printf("Size: %d\n", getLength(head));

    free(head);
    return 0;
}
