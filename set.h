//
// Created by Martin Alemajoh on 9/24/2020.
//

#ifndef SETS_SET_H
#define SETS_SET_H

/*
 *Structure to represent a node
*/
typedef struct node {
    const void *data;
    struct node *next;
    struct node *prev;
}Node;

/*
 * Structure to represent a set
 */
typedef struct set{
    Node *head;
    Node *tail;
    char type;
}Set;


/*
 * DEF: initializes a Set
 * PARAM: Set *set - Set to be initialize
 * RETURN: returns void
*/
void initSet(Set *set, char type);


/*
 * DEF: Frees a node in a Set
 * PARAM: void ** node - node to be freed
 * RETURN: returns void
*/
void freeNode(void **node);


/*
 * DEF: Destroys a Set by freeing all allocated memory
 * PARAM: Set *set - Set to be destroyed
 * RETURN: returns void
*/
void clearSet(Set *set);

/*
 * DEF: checks if an element is a member of a Set
 * PARAM: Set *set - Set - set
 * PARAM: const void *data - data
 * RETURN: returns 1 if true and 0 otherwise
*/
int isMember(const Set *set, const void *data);


/*
 * DEF: inserts an element into a Set
 * PARAM: Set *set - Set
 * PARAM2:const void *data - data to be stored in node
 * RETURN: returns pointer to the inserted node
*/
Node *addElement(Set *set, const void *data);

/*
 * DEF: computes the size of a set
 * PARAM: const Set *set - set to compute its size
 * RETURN: returns the size of the set.
*/
unsigned int Size(const Set *set);


/*
 * DEF: returns the node at a specific index
 * PARAM: Set *set - Set
 * PARAM: int index - index
 * RETURN: returns pointer to node
*/
Node *getNode(const Set *set, int index);

/*
 * DEF: prints the members of a set
 * PARAM: Set *set - Set
 * RETURN: returns pointer to void
*/
void *getElement(const Set *set, int index);


/*
 * DEF: removes a node from the set
 * PARAM: Set *set - Set
 * PARAM2: int index - element index to be removed
 * RETURN: 1 on success and -1 on failure
*/
int removeElement(Set *set, int index);


/*
  DEF: computes the union of two sets
  PARAM2: const Set *set1 - first set
  PARAM3: const Set *set2 - second set
  RETURN: returns pointer to new set
*/
Set *Union(const Set *set1, const Set *set2);


/*
  DEF: computes the intersection of two sets
  PARAM2: const Set *set1 - first set
  PARAM3: const Set *set2 - second set
  RETURN: returns pointer to new set
*/
Set *intersection(const Set *set1, const Set *set2);


/*
  DEF: computes the difference of two sets
  PARAM2: const Set *set1 - first set
  PARAM3: const Set *set2 - second set
  RETURN: returns a pointer to a set
*/
Set *difference(const Set *set1, const Set *set2);


/*
  DEF: determines if set1 is a subset of set2
  PARAM: const Set *set1 - first set
  PARAM2: const Set *set2 - second set
  RETURN: returns 1 if set1 is a subset of set2 and -1 otherwise
*/
int Subset(const Set *set1, const Set *set2);


/*
  DEF: determines if set1 is equal to set2
  PARAM: const Set *set1 - first set
  PARAM2: const Set *set2 - second set
  RETURN: returns 1 if set1 is a equal to set2 and -1 otherwise
*/
int Equal(const Set *set1, const Set *set2);


#endif //SETS_SET_H
