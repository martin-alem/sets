//
// Created by Martin Alemajoh on 9/24/2020.
//

#include <stdlib.h>
#include "set.h"

void initSet(Set *set){
    set->head = NULL;
    set->tail = NULL;
}

void freeNode(void **node){

    if(node != NULL && *node != NULL){
        free(*node);
        *node = NULL;
    }
}

void clearSet(Set *set){

    if(set->head != NULL){
        Node *node = set->head;
        Node *nextNode;

        while (node != NULL){
            nextNode = node->next;
            freeNode((void **)&node);
            node = nextNode;
        }
        set->head = NULL;
        set->tail = NULL;
    }
}


Node *addElement(Set *set, const void *data){

    Node *node = (Node *)malloc(sizeof(Node));
    if(node == NULL){
        return NULL;
    }
    node->data = data;
    node->next = NULL;

    if(set->head == NULL){
        node->prev = NULL;
        set->head = node;
    }
    else{
        set->tail->next = node;
        node->prev = set->tail;
    }
    set->tail = node;
    return node;
}

Node *getNode(const Set *set, int index){

    if(set->head != NULL){

        if(index <= -1 || index >= Size(set)){
            return NULL;
        }
        Node *node = set->head, *newNode;
        int i = 0;

        do{
            newNode = node;
            node = node->next;
            i += 1;
        }while(i <= index);
        return newNode;
    }
    return NULL;
}


void *getElement(const Set *set, int index){

    if(set->head != NULL){

        Node *node = getNode(set, index);
        return (void *)node->data;
    }
    return NULL;
}

unsigned int Size(const Set *set) {

    unsigned int len = 0;
    if (set->head != NULL) {
        Node *node = set->head;
        while(node != NULL){
            len += 1;
            node = node->next;
        }
        return len;
    }
    return len;
}
