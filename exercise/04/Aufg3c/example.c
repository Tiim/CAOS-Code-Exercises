#include <stdio.h>

int maskenmethode(char c) {
    static char mask[] = {0x55, 0x33, 0x0f};
    c = (c & mask[0]) + ((c >> 1) & mask[0]);
    c = (c & mask[1]) + ((c >> 2) & mask[1]);
    c = (c & mask[2]) + ((c >> 4) & mask[2]);
    return (int)c;
}

void main() {
    printf("%d -> %d\n", 1, maskenmethode(1));
    printf("%d -> %d\n", 2, maskenmethode(2));
    printf("%d -> %d\n", 3, maskenmethode(3));
    printf("%d -> %d\n", 4, maskenmethode(4));
    printf("%d -> %d\n", 5, maskenmethode(5));
    printf("%d -> %d\n", 6, maskenmethode(6));
}