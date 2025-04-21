#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 50
#define EXIT_FAILURE 1

typedef struct Person {
    char name[MAX];
    char address[MAX];
    int age;
    struct Person* next;
} Person;

Person* createPerson(char new_name[], char new_address[], int new_age) {
    Person* new_person = (Person*)malloc(sizeof(Person));
    if(new_person == NULL) {
        printf("Memory allocation failed!");
        exit(EXIT_FAILURE);
    }
    strcpy(new_person->name, new_name);
    strcpy(new_person->address, new_address);
    new_person->age = new_age;
    new_person->next = NULL;

    return new_person;
}

void insertAtFront(Person** head, char new_name[], char new_address[], int new_age) {
    Person* new_person = createPerson(new_name, new_address, new_age);
    new_person->next = *head;
    *head = new_person;
    printf("Person successfuly added to list!\n\n");
}

void insertAtEnd(Person** head, char new_name[], char new_address[], int new_age) {
    Person* new_person = createPerson(new_name, new_address, new_age);
    if(*head == NULL) {
        *head = new_person;
        printf("Person successfuly added to list!\n\n");
        return;
    }

    Person* last = *head;
    while(last->next != NULL) {
        last = last->next;
    }

    last->next = new_person;
    printf("Person successfuly added to list!\n\n");
}

void insertAtPos(Person** head, char new_name[], char new_address[], int new_age, int pos) {
    Person* new_person = createPerson(new_name, new_address, new_age);

    if(pos < 1) {
        printf("Invalid position!\n\n");
        return;
    }

    if(pos == 1) {
        new_person->next = *head;
        *head = new_person;
        printf("Person successfuly added to list!\n\n");
        return;
    }

    Person* curr = *head;
    for(int i = 1; i < pos - 1 && curr != NULL; i++) {
        curr = curr->next;
    }

    if(curr == NULL) {
        printf("Invalid position!\n\n");
        return;
    }

    new_person->next = curr->next;
    curr->next = new_person;
    printf("Person successfuly added to list!\n\n");
}

void printList(Person* head) {
    Person* curr =  head;
    printf("---------------------------------------------------------------------\n");
    printf("|%-30s|%-30s|%-5s|", "NAME", "ADDRESS", "AGE");
    printf("\n---------------------------------------------------------------------\n");
    while(curr != NULL) {
        printf("|%-30s|%-30s|%-5d|\n", curr->name, curr->address, curr->age);
        curr = curr->next;
    }
    printf("---------------------------------------------------------------------\n");
    printf("\n");
}

int main() {
    Person* head = NULL;
    char new_name[MAX];
    char new_address[MAX];
    int new_age;
    int input, pos;

    while(1) {
        printf("Cool People\n");
        printf("1. Insert new person at front\n");
        printf("2. Insert new person at end\n");
        printf("3. Insert new person at position\n");
        printf("4. Delete new person at front\n");
        printf("5. Delete new person at end\n");
        printf("6. Delete new person at position\n");
        printf("7. Sort list by age\n");
        printf("8. Swap people\n");
        printf("9. Display list\n");
        printf("10. Exit\n");
        printf("Input: ");
        scanf("%d", &input);

        switch(input) {
            case 1:
                getchar();

                printf("\nEnter name: ");
                fgets(new_name, MAX, stdin);
                new_name[strcspn(new_name, "\n")] = '\0';

                printf("Enter address: ");
                fgets(new_address, MAX, stdin);
                new_address[strcspn(new_address, "\n")] = '\0';

                printf("Enter age: ");
                scanf("%d", &new_age);

                insertAtFront(&head, new_name, new_address, new_age);
                break;
            case 2:
                getchar();

                printf("\nEnter name: ");
                fgets(new_name, MAX, stdin);
                new_name[strcspn(new_name, "\n")] = '\0';

                printf("Enter address: ");
                fgets(new_address, MAX, stdin);
                new_address[strcspn(new_address, "\n")] = '\0';

                printf("Enter age: ");
                scanf("%d", &new_age);

                insertAtEnd(&head, new_name, new_address, new_age);
                break;
            case 3:
                getchar();

                printf("\nEnter name: ");
                fgets(new_name, MAX, stdin);
                new_name[strcspn(new_name, "\n")] = '\0';

                printf("Enter address: ");
                fgets(new_address, MAX, stdin);
                new_address[strcspn(new_address, "\n")] = '\0';

                printf("Enter age: ");
                scanf("%d", &new_age);

                printf("Enter position: ");
                scanf("%d", &pos);

                insertAtPos(&head, new_name, new_address, new_age, pos);
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 9:
                printf("\nList of people:\n");
                printList(head);
                break;
            case 10:
                printf("Exiting...");
                return 0;
                break;
            default:
                printf("Invalid option!\n");
                break;
        }
    }

    return 0;
}
