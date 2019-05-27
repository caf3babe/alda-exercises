#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main() {

    doubly_linked_list *list;
    list = init();
    insertEnd(list,1,"legage1");
    insertEnd(list,2,"legage2");
    insertEnd(list,3,"legage3");
    insertEnd(list,4,"legage4");
    insertEnd(list,12341234,"Das Leben ist so schoen! NICHT.");
    insertEnd(list,5,"legage5");
    print(list);

    printf("Searching for node with key 5 in list\n");
    node* toFind = find(list,5);
    printf("Key: %d\n",toFind->key);
    printf("Data: %s\n",toFind->data);

    printf("Attempting to delete node with key 12341234 from list\n");
    delete(list,12341234);
    print(list);

    printf("Inserting new node before node with key 1\n");
    insertBefore(list,69,"yeah",1);
    print(list);

    return 0;
}