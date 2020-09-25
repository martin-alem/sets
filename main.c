#include <stdio.h>
#include "set.h"


int main() {

    Set set1, set2;

    initSet(&set1, 'i');
    initSet(&set2, 'i');

    int a = 10, b = 20, c = 30, d = 40, e = 50;
    int f = 60, g = 70, h = 80, i = 90, j = 100;

    addElement(&set1, (void *)&a);
    addElement(&set1, (void *)&b);
    addElement(&set1, (void *)&c);
    addElement(&set1, (void *)&d);
    addElement(&set1, (void *)&e);

    addElement(&set2, (void *)&f);
    addElement(&set2, (void *)&g);
    addElement(&set2, (void *)&h);
    addElement(&set2, (void *)&i);
    addElement(&set2, (void *)&j);

    Set *uSet = Union(&set1, &set2);


    int *data , counter;
    printf("---------Set1 ----------\n");
    for(counter = 0; counter  < Size(&set1); counter ++){
        data = (int *)getElement(&set1, counter );
        printf("%d ", *data);
    }

    printf("\n---------Set2 ----------\n");
    for(counter = 0; counter  < Size(&set2); counter ++){
        data = (int *)getElement(&set2, counter );
        printf("%d ", *data);
    }

    printf("\n---------Union Set----------\n");
    for(counter = 0; counter  < Size(uSet); counter ++){
        data = (int *)getElement(uSet, counter );
        printf("%d ", *data);
    }

    clearSet(&set1);
    clearSet(&set2);

    return 0;
}
