#include <stdio.h>
#include "set.h"


int main() {

    Set set1;

    initSet(&set1, 'i');

    int a = 10, b = 20, c = 30, d = 40, e = 50;

    addElement(&set1, (void *)&a);
    addElement(&set1, (void *)&b);
    addElement(&set1, (void *)&c);
    addElement(&set1, (void *)&d);
    addElement(&set1, (void *)&e);

    removeElement(&set1, 5);

    printf("Size: %d\n", Size(&set1));

    int *data;
    for(int i = 0; i < Size(&set1); i++){
        data = (int *)getElement(&set1, i);
        printf("%d ", *data);
    }

    clearSet(&set1);

    return 0;
}
