//
// Created by Martin Alemajoh on 9/24/2020.
//

#include <stdlib.h>
#include <string.h>
#include "set.h"


void initSet(Set *set, char type){
    set->head = NULL;
    set->tail = NULL;
    set->type = type;
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

    if(isMember(set, data)){
        return NULL;
    }

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

int isMember(const Set *set, const void *data){

    if(set->head != NULL){

        Node *node = set->head;

        while (node != NULL){

                if(set->type == 's') {
                    if (strcmp((char *) data, (char *) node->data) == 0) {
                        return 1;
                    }
                }
                else if(set->type == 'i'){
                    if(*((int *)data) == *((int *)node->data)){
                        return 1;
                    }
                }
                else if(set->type == 'f'){
                    if(*((float *)data) == *((float *)node->data)){
                        return 1;
                    }
                }
                else if(set->type == 'd'){
                    if(*((double *)data) == *((double *)node->data)){
                        return 1;
                    }
                }
                else if(set->type == 'c'){
                    if(*((char *)data) == *((char *)node->data)){
                        return 1;
                    }
                }
            node = node->next;
            }
        return 0;
    }
    return 0;
}

int removeElement(Set *set, int index){

    if(set->head != NULL){

        Node *node = getNode(set, index);
        if(node == NULL){
            return -1;
        }
        Node *nextNode, *prevNode;
        if(set->head == node){
            nextNode = node->next;
            nextNode->prev = NULL;
            set->head = nextNode;
        }
        else if(set->tail == node){
            prevNode = node->prev;
            prevNode->next = NULL;
            set->tail = prevNode;
        }
        else{
            nextNode = node->next;
            prevNode = node->prev;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
        }
        freeNode((void **)&node);
        return 1;
    }
    return -1;
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


Set *Union(const Set *set1, const Set *set2){

    static Set set;
    initSet(&set, set1->type);

    if(set1->head == NULL && set2->head != NULL){
        set.head = set2->head;
        set.tail = set2->tail;
    }
    else if(set1->head != NULL && set2->head == NULL){
        set.head = set1->head;
        set.tail = set1->tail;
    }

    else if(set1->head != NULL && set2->head != NULL){
        Node *node = set1->head, *node2 = set2->head;

        while (node != NULL){
            addElement(&set,(const void *)node->data);
            node = node->next;
        }
        while (node2 != NULL){
            addElement(&set,(const void *)node2->data);
            node2 = node2->next;
        }
    }
    return &set;
}

Set *intersection(const Set *set1, const Set *set2){

    static Set set;
    initSet(&set, set1->type);

    if(set1->head != NULL && set2->head != NULL){
        Node *node = set1->head;
        while(node != NULL){
            if(isMember(set2, node->data)){
                addElement(&set, node->data);
            }
            node = node->next;
        }
    }
    return &set;
}

Set *difference(const Set *set1, const Set *set2){

    static Set set;
    initSet(&set, set1->type);

    if(set2->head == NULL){
        set.head = set1->head;
        set.tail = set1->tail;
    }
    else if(set1->head != NULL && set2->head != NULL){
        Node *node = set1->head;
        while(node != NULL){
            if(!isMember(set2, node->data)){
                addElement(&set, node->data);
            }
            node = node->next;
        }
    }
    return &set;
}

int Subset(const Set *set1, const Set *set2){

    if(set1->head != NULL && set2->head != NULL){
        Node *node = set1->head;
        while(node != NULL){
            if(!isMember(set2, node->data)){
                return 0;
            }
            node = node->next;
        }
        return 1;
    }
    return 0;
}