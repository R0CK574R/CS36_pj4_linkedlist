#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>

typedef struct node {
    char data;
    struct node* next;
} Node;

typedef Node* LinkedList;

LinkedList create(void);                     
void addNode(LinkedList* list, char data); 
void printList(const LinkedList list);
void destroy(LinkedList list);
LinkedList merge(const LinkedList list1, const LinkedList list2);

#endif