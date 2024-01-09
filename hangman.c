#include <stdio.h>
#include <stdlib.h>

#define MAX_CHARS 200

int main(int argc, char *argv[])
{

    FILE * inputFile;
    char * row;

    // Testing args
    printf("You have entered %d arguments:\n", argc);
 
    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    inputFile = fopen(argv[1], "r");

    if (inputFile == NULL) {
        printf("%s\n", "Erreur: Dictionnaire sélectionné non valide");

        return 1;
    }

    row = (char*)malloc(MAX_CHARS* sizeof(char));

    while (fgets(row, MAX_CHARS, inputFile) != NULL) {
        printf("row: %s", row);
        // operations...

        free(row);
        row = (char*)malloc(MAX_CHARS* sizeof(char));
    }

    free(row);

    return 0;
}