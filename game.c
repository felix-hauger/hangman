#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "hangman.h"

void init_game(_Game *game, char *word_to_find)
{
    game->word_to_find = word_to_find;

    game->user_word = (char*)malloc(sizeof(char *) * my_strlen(game->word_to_find));

    int i = 0;

    // Fill the word displayed to the user, using the word to find
    while (game->word_to_find[i] != 0) {
        // Display the first and last characters as hints
        if (i == 0 || i == my_strlen(game->word_to_find) - 1) {
            (*game).user_word[i] = game->word_to_find[i];
        } else {
            (*game).user_word[i] = '*';
        }
        i++;
    }

    game->user_word[i] = 0;

    game->lives = 6;

    game->word_propositions_left = 3;

    game->status = 'o';
}

void display_help()
{
    printf("%s", "Utilisation du jeu : ./hangman dict.csv [facile/moyen/difficile] <category>\n");
}

#define MAX_CHARS 200

_Word *get_words_from_dict(FILE *dictionary_file, char *category, char *difficulty)
{
    char * row;
    char * token;

    // printf("Category: %s\n", category);
    // printf("Difficulty: %s\n", difficulty);

    row = (char*)malloc(MAX_CHARS* sizeof(char));

    _Word *words = malloc(sizeof(_Word) * 500);

    int array_result_index = 0;

    while (fgets(row, MAX_CHARS, dictionary_file) != NULL) {
        struct Word current_word;

        // Ignore comments and empty lines
        if (strlen(row) > 1 && row[0] != '#') {

            // Tokenize rows with commas (,)
            token = strtok(row, ",");

            int token_index = 0;

            while (token != NULL) {

                // printf("Token: %s\n", token);

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

    return words;

}

char *get_random_word(_Word *words)
{
    // To get the size of the words array, to get the random number
    int i = 0;

    while (words[i].word != NULL) {
        i++;
    }

    // Init rand
    srand(time(NULL));

    int r = rand() % i;

    return words[r].word;
}

void draw_hangman(int remaining_lives)
{
    switch (remaining_lives)
    {
    case 6:
        printf("  _____\n");
        printf("  |   |\n");
        printf("      |\n");
        printf("      |\n");
        printf("      |\n");
        printf("      |\n");
        printf("________\n");
        break;

    case 5:
        printf("  _____\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf("      |\n");
        printf("      |\n");
        printf("      |\n");
        printf("________\n");
        break;

    case 4:
        printf("  _____\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf("  |   |\n");
        printf("      |\n");
        printf("      |\n");
        printf("________\n");
        break;

    case 3:
        printf("  _____\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf("  |\\  |\n");
        printf("      |\n");
        printf("      |\n");
        printf("________\n");
        break;

    case 2:
        printf("  _____\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf(" /|\\  |\n");
        printf("      |\n");
        printf("      |\n");
        printf("________\n");
        break;

    case 1:
        printf("  _____\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf(" /|\\  |\n");
        printf("   \\  |\n");
        printf("      |\n");
        printf("________\n");
        break;

    case 0:
        printf("  _____\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf(" /|\\  |\n");
        printf(" / \\  |\n");
        printf("      |\n");
        printf("________\n");
        break;

    default:
        printf("Valeur d'entrée non valide (Vies restantes : %d)", remaining_lives);
        break;
    }

    printf("\n");
}