#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char fname[20];
    char lname[20];
    int age;
} star;

int main() {
    int n;
    star *p;
    printf("Enter size of array: ");
    scanf("%d", &n);
    p = (star*)malloc(n *sizeof(star));
    if(p == NULL) {
        printf("Error");
        exit(1);
    }

    for(int i = 0; i < n; i++) {
        printf("\nEnter details for star #%d\n", i + 1);
        printf("Enter first name: ");
        scanf(" %s", p[i].fname);
        printf("Enter last name: ");
        scanf(" %s", p[i].lname);
        printf("Enter age: ");
        scanf("%d", &p[i].age);
    }

    for(int i = 0; i < n; i++) {
        printf("\nStar #%d\n", i + 1);
        printf("First name: %s\n", p[i].fname);
        printf("Last name: %s\n", p[i].lname);
        printf("Age: %d\n", p[i].age);
    }

    free(p);
    return 0;
}
