#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main( int argc, char** argv )
{
    if (argc < 3) {
        printf("Ussage %s [source] [destination]\n", argv[0]);
        return 1;
    }

    char* from = argv[1];
    char* to = argv[2];

    printf("Copy %s --> %s\n", from, to);

    FILE *from_f = fopen(from, "r");
    FILE *to_f = fopen(to, "w");

    if (from_f == NULL || to_f == NULL) {
        printf("Something went wrong\n");
        return 2;
    }

    int ch;

    while ((ch = fgetc(from_f)) != EOF) {
      fputc(ch, to_f);
    }

    printf("File copied\n");
    fclose(from_f);
    fclose(to_f);

}