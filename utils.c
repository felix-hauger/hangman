#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 200

char *get_random_word(char *dict_file_name, char *category, char *difficulty)
{
    FILE * inputFile;
    char * row;
    char * token;

    printf("Dictionary file name: %s\n", dict_file_name);
    printf("Category: %s\n", category);
    printf("Difficulty: %s\n", difficulty);

    inputFile = fopen(dict_file_name, "r");

    row = (char*)malloc(MAX_CHARS* sizeof(char));

    while (fgets(row, MAX_CHARS, inputFile) != NULL) {
        // printf("row: %s", row);

        // operations...

        // Tokenize (splice) rows with commas (,)
        token = strtok(row, ",");

        while (token != NULL) {
            printf("Token: %s\n", token);

            // Resume tokenizing from last position
            token = strtok(NULL, ",");
        }

        free(row);
        row = (char*)malloc(MAX_CHARS* sizeof(char));
    }

    free(row);

    return dict_file_name;
}