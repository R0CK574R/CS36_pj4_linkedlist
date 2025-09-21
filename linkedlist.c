#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"


LinkedList create() {
    return NULL;
}


void addNode(LinkedList list, char data) {
    LinkedList newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = list;
    list = newNode;  
}


void printList(LinkedList list, const char *message) {
    printf("%s", message);
    LinkedList current = list;
    while (current != NULL) {
        printf(" %c", current->data);
        current = current->next;
    }
    printf("\n");
}


void destroy(LinkedList list) {
    LinkedList current = list;
    LinkedList nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}


LinkedList merge(LinkedList list1, LinkedList list2) {
    LinkedList mergedList = NULL;
    LinkedList *tail = &mergedList;

    
    while (list1 != NULL) {
        *tail = malloc(sizeof(struct node));
        (*tail)->data = list1->data;
        (*tail)->next = NULL;
        tail = &(*tail)->next;
        list1 = list1->next;
    }

  
    while (list2 != NULL) {
        *tail = malloc(sizeof(struct node));
        (*tail)->data = list2->data;
        (*tail)->next = NULL;
        tail = &(*tail)->next;
        list2 = list2->next;
    }

    
    LinkedList current, next;
    char temp;
    int swapped;

    do {
        swapped = 0;
        current = mergedList;
        while (current != NULL && current->next != NULL) {
            next = current->next;
            if (current->data > next->data) {  
                temp = current->data;
                current->data = next->data;
                next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
    } while (swapped);

    return mergedList;
}