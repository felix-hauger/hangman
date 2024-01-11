#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "hangman.h"

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

                printf("Token: %s\n", token);

                if (token_index == 0) {
                    // Select word
                    current_word.word = token;
                } else if (token_index == 1) {
                    // Select category
                    current_word.category = token;

                    // Compare current category to selected category

                } else if (token_index == 2) {
                    // Remove line break at the end of the line
                    current_word.difficulty = rtrim(token);
                }

                // Resume tokenizing from last position
                token = strtok(NULL, ",");

                token_index++;
            }

            if (my_strcmp(current_word.category, category) == 0 ) {

                // printf("MATCHING CATEGORY %s\n", category);

                if (my_strcmp(current_word.difficulty, difficulty) == 0) {
                    // printf("MATCHING DIFFICULTY %s\n", difficulty);
                    // printf("Adding word %s\n", current_word.word);

                    words[array_result_index] = current_word;
                    array_result_index++;
                    row = (char*)malloc(MAX_CHARS* sizeof(char));
                }
            }
        }
    }

    // Init rand
    srand(time(NULL));

    int r = rand() % array_result_index;

    // Select random word from matching results
    char *result = my_strdup(words[r].word);
    // printf("RAND: %d\n");

    printf("RESULT: %s\n", result);

    while (array_result_index--) {
        // printf("Array result: %s\n", words[array_result_index].word);
        free(words[array_result_index].word);
    }
    free(words);
    free(row);

    return result;
}
