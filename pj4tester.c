#include <stdio.h>
#include "linkedlist.h"

int main(void) {
    LinkedList list1 = create();
    LinkedList list2 = create();

    
    char input;
    printf("Enter 5 characters for the first list:\n");
    for (int i = 0; i < 5; i++) {
        scanf(" %c", &input);
        addNode(list1, input);
    }
    printList(list1, "The first set of characters is:");

    printf("Enter 5 characters for the second list:\n");
    for (int i = 0; i < 5; i++) {
        scanf(" %c", &input);
        addNode(list2, input);
    }
    printList(list2, "The second set of characters is:");

    
    LinkedList mergedList = merge(list1, list2);
    printList(mergedList, "Here is your merged and alphabetized list:");

    // Clean
    destroy(list1);
    destroy(list2);
    destroy(mergedList);

    return 0;
}