//
// Created by nichil on 25.05.2019.
//
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

doubly_linked_list *init() {
    doubly_linked_list *list = (doubly_linked_list *) malloc(sizeof(doubly_linked_list));
    list->count = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void insertEnd(doubly_linked_list* list, int key, char *data) {
    node* n = (node*)malloc(sizeof(node));
    n->key = key;
    n->data = (char*)malloc(strlen(data + 1));
    strcpy(n->data, data);
    if (list->count < 1) {
        list->head = n;
    } else {
        list->tail->next = n;
    }
    n->previous = list->tail;
    n->next = NULL;
    list->tail = n;
    list->count++;
}

node* find(doubly_linked_list* list, int key) {
    if (list->head != NULL) {
        node *this = list->head;
        while (this != NULL) {
            if (this->key == key) {
                return this;
            }
            this = this->next;
        }
    } else {
        return NULL;
    }
}

void print(doubly_linked_list* list) {
    node *this = list->head;
    while (this != NULL) {
        printf("Key: %d\n", this->key);
        printf("Data: %s\n", this->data);
        this = this->next;
    }
}

void delete(doubly_linked_list* init, int key){
    node* n = find(init,key);
    if(n != NULL) {
        if(n->previous != NULL) {
            n->previous->next = n->next;
        }
        if (n->next != NULL) {
            n->next->previous = n->previous;
        }
        free(n);
    }
}


void insertBefore(doubly_linked_list *list, int key, char *data,int key2){
    node* node1 = (node*)malloc(sizeof(data)+1);
    strcpy(node1->data,data);
    node1->key = key;
    node* node2 = find(list,key2);
    if(node2->previous != NULL){
        node2->previous->next = node1;
    } else {
        list->head = node1;
        node2->previous = node1;
    }
    node1->previous = node2->previous;
    node1->next = node2;
}

