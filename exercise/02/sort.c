#include <stdlib.h>
#include <stdio.h>

#include "sort.h"

/**
 * Compare vectors based on their abs 
 **/
int comp(const void* a, const void* b) {
    Vector* v1 = (Vector*)a;
    Vector* v2 = (Vector*)b;
    
    int abs1 = v1->x * v1->x + v1->y * v1->y + v1->z * v1->z;
    int abs2 = v2->x * v2->x + v2->y * v2->y + v2->z * v2->z;
    return abs1 - abs2;
}

/**
 * Write vector array to file "output.txt" 
 **/
void out(Vector vecs[], int size) {
    FILE* fptr = fopen("output.txt","w");

    for (int i = 0; i < size; i++) {
        fprintf(fptr, "(%f, %f, %f)\n", vecs[i].x,vecs[i].y,vecs[i].z);

    }
    fclose(fptr);
}


int main() {
    // Define 12 vectors
    Vector array[] = {
        {1,2,3},
        {2,3,4},
        {1,7,2},
        {5,0,21},
        {3,9,4},
        {1,5,0},
        {0,8,4},
        {9,12,1},
        {1,45,5},
        {9,0,6},
        {5,7,1},
        {12,65,12},
    };
    // Sort vectors
    qsort(&array, 12, sizeof(Vector), comp);
    // Print vectors
    out(array, 12);
    return 0;
}