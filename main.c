#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Book {
    char title[100];
    float price;
    int pages;
    char language[50];
    float weight;
    int year;
    struct Book* next;
};

struct Book* head = NULL;

void printList() {
    struct Book* p = head;
    printf("\nHarry Potter Books:\n\n");

    // Start from the beginning of the list
    while (p != NULL) {
        printf("Title: %s\n", p->title);
        printf("Price: %.2f\n", p->price);
        printf("Number of pages: %d\n", p->pages);
        printf("Language: %s\n", p->language);
        printf("Weight: %.2f kg\n", p->weight);
        printf("Year of publication: %d\n", p->year);
        printf("-------------------------\n");
        p = p->next;
    }
}

void insertAtBeginning(char* title, float price, int pages, char* language, float weight, int year) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    strcpy_s(newBook->title, sizeof(newBook->title), title);
    newBook->price = price;
    newBook->pages = pages;
    strcpy_s(newBook->language, sizeof(newBook->language), language);
    newBook->weight = weight;
    newBook->year = year;
    newBook->next = head;
    head = newBook;
}

void insertAtEnd(char* title, float price, int pages, char* language, float weight, int year) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    strcpy_s(newBook->title, sizeof(newBook->title), title);
    newBook->price = price;
    newBook->pages = pages;
    strcpy_s(newBook->language, sizeof(newBook->language), language);
    newBook->weight = weight;
    newBook->year = year;
    newBook->next = NULL;

    if (head == NULL) {
        head = newBook;
    }
    else {
        struct Book* last = head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newBook;
    }
}

void freeList() {
    struct Book* current = head;
    struct Book* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    head = NULL;
}

int main() {
    insertAtBeginning("Harry Potter and the Philosopher's Stone", 20.99, 223, "English", 0.5, 1997);
    insertAtEnd("Harry Potter and the Chamber of Secrets", 22.99, 251, "English", 0.6, 1998);
    insertAtEnd("Harry Potter and the Prisoner of Azkaban", 25.99, 317, "English", 0.65, 1999);
    insertAtEnd("Harry Potter and the Goblet of Fire", 27.99, 636, "English", 0.75, 2000);
    insertAtEnd("Harry Potter and the Order of the Phoenix", 29.99, 766, "English", 0.8, 2003);
    insertAtEnd("Harry Potter and the Half-Blood Prince", 31.99, 607, "English", 0.7, 2005);
    insertAtEnd("Harry Potter and the Deathly Hallows", 33.99, 607, "English", 0.7, 2007);

    printList();

    freeList();

    return 0;
}
