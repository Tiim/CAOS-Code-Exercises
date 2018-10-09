#include "vector3d.h"

typedef struct VectorList {
    struct VectorList* next;
    struct Vector* element;
} VectorList;



Vector* getElement(VectorList* l, int index);
void insertElementFront(VectorList* l, Vector* vec);
void insertElementBack(VectorList* l, Vector* vec);
int size(VectorList* l);