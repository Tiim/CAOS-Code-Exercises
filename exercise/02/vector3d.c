#include <stdio.h>
#include "vector3d.h"

Vector addVectors(Vector v1, Vector v2) {
    Vector newvec = { 
        .x = v1.x + v2.x,
        .y = v1.y + v2.y,
        .z = v1.z + v2.z
    };
    return newvec;
}

int main() {
    Vector v1 = { .x = 1, .y = 2,.z = 3};
    Vector v2 = { .x = 4, .y = 5,.z = 6};
    
    Vector result = addVectors(v1, v2);

    printf("(%f, %f, %f)\n", result.x, result.y, result.z);
}