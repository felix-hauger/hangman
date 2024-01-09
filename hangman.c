#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 200

int main(int argc, char *argv[])
{

    printf("You have entered %d arguments:\n", argc);
 
    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    FILE * inputFile = fopen(argv[1], "r");

    if (inputFile == NULL) {
        printf("%s\n", "Erreur: Dictionnaire sélectionné non valide");

        return 1;
    }

    char str[MAX_BUFFER_SIZE];

    while (fgets(str, MAX_BUFFER_SIZE, inputFile) != NULL) {
        printf("%s", str);
        // printf("hmm");
    }



    // printf(inputFile);

    return 0;
}