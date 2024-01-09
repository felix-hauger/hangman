#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_random_word(char *dict_file_name, char *category, char *difficulty);

int main(int argc, char *argv[])
{

    // Testing args
    printf("You have entered %d arguments:\n", argc);

    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    if (argv[1] == NULL) {
        printf("%s\n", "Erreur: Dictionnaire sélectionné non valide");

        return 1;
    }

    get_random_word(argv[1], argv[2], argv[3]);

    return 0;
}