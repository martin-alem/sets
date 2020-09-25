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
