
#include <stdio.h>
#include <unistd.h>
#include <string.h> // for strlen()


const char help[] = "Optionen:\n-h gibt eine kurze Anleitung aus\n-t gibt den zu -t als Argument mitgegebenen Text in umgekehrter Buchstabenreihenfolge aus\n";

void print_help() {
    printf("%s", help);
}

void reverse(char* value) {
    int length = strlen(value) - 1;
    for(int i = length; i >= 0; i--) {
        printf("%c", value[i]);
    }
    printf("\n");
}

int main( int argc, char** argv )
{
    int success = 0;
	char c;
    char* value = NULL;

    while ((c = getopt(argc, argv, "ht:")) != -1) {
        value = optarg;
        success = 1;
        if (c == 'h') {
            print_help();
        } else if (c == 't') {
            reverse(value);
        }
    }

    if (!success) {
        print_help();
    }
}



