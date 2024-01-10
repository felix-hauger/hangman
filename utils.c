#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 200


typedef struct Word
{
    char *word;
    char *difficulty;
    char *category;
}_Word;


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

    _Word *words = malloc(sizeof(_Word) * 500);

    int array_result_index = 0;

    while (fgets(row, MAX_CHARS, inputFile) != NULL) {
        struct Word current_word;

        // Ignore comments and empty lines
        if (strlen(row) > 1 && row[0] != '#') {

            // Tokenize rows with commas (,)
            token = strtok(row, ",");

            int token_index = 0;

            while (token != NULL) {

                // Select word
                if (token_index == 0) {
                    current_word.word = token;
                }
                printf("Token: %s\n", token);
                // printf("Word: %s\n", word);

                // Select category
                if (token_index == 1) {
                    // Compare current category to selected category
                    if (strcmp(token, category) == 0) {
                        printf("CATEGORY FOUND: %s\n", category);
                        printf("Adding word %s\n", current_word.word);

                        words[array_result_index] = current_word;
                        array_result_index++;
                        row = (char*)malloc(MAX_CHARS* sizeof(char));
                    }
                }

                // Resume tokenizing from last position
                token = strtok(NULL, ",");

                token_index++;
            }

        }
    }



    printf("%d\n", array_result_index);
    while (array_result_index--) {
        printf("Array result: %s\n", words[array_result_index].word);
        free(words[array_result_index].word);
    }
    free(words);
    free(row);
     //printf("Array result: %s\n", ( words )[3].word);

    return dict_file_name;
}
