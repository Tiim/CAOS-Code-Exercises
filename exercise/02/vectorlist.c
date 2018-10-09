#include "vectorlist.h"

Vector* getElement(VectorList* l, int index) {
    for(int i = 0; i < index; i++) {
        l = l->next;
    }
    return l->element;
}

void insertElementFront(VectorList* l, Vector* vec) {
    VectorList* elem = (VectorList*) malloc(sizeof(VectorList));
    elem->element = vec;
    elem->next = l;
    *l = *elem;
}

void insertElementBack(VectorList* l, Vector* vec) {
    VectorList* elem = (VectorList*) malloc(sizeof(VectorList));
    elem->element = vec;
    while(l->next) {
        l = l->next;
    }
    l->next = elem;
}

int size(VectorList* l) {
    int i = 0;
    while(l->next) {
        i += 1;
    }
    return i;
}