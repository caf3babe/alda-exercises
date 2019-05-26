//
// Created by nichil on 25.05.2019.
//


#ifndef EXERCISE4_LIST_H
#define EXERCISE4_LIST_H

typedef struct node node;
typedef struct doubly_linked_list doubly_linked_list;

struct node{
    node *next;
    node *previous;
    int key;
    char *data;
};

struct doubly_linked_list{
    int count;
    node *head;
    node *tail;
};

//prototypes
doubly_linked_list *init();
void insertEnd(doubly_linked_list *list, int key, char *data);
node *find(doubly_linked_list *list, int key);
void print(doubly_linked_list *list);
void delete(doubly_linked_list *init, int key);
void insertBefore(doubly_linked_list *list, int key, char *data,int key2);

#endif //EXERCISE4_LIST_H
