#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "hangman.h"

int main(int argc, char *argv[])
{

    // Testing args
    // printf("You have entered %d arguments:\n", argc);

    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    if (argv[1] == NULL || argv[2] == NULL || argv[3] == NULL) {
        display_help();

        return 1;
    }

    char *dictionary_name = argv[1];
    FILE * dictionary = fopen(dictionary_name, "r");
    char *difficulty = argv[2];
    char *category = argv[3];

    // TEST ARGUMENTS 
    if (dictionary == NULL) {
        printf("%s\n", "Erreur: Dictionnaire sélectionné non valide");
        display_help();

        return 1;
    } else if (my_strcmp(difficulty, "facile") != 0 && my_strcmp(difficulty, "moyen") != 0 && my_strcmp(difficulty, "difficile") != 0) {
        printf("%s\n", "Erreur: Difficulté sélectionnée non valide");
        display_help();

        return 1;
    }

    _Word *words = get_words_from_dict(dictionary, category, difficulty);

    if (words[0].word == NULL) {
        printf("Aucun mot trouvé. Essayez une autre catégorie\n");

        display_help();

        return 1;
    }

    char *word = get_random_word(words);

    // Game structure, contains game infos
    _Game game;

    init_game(&game, word);

    char input_str[20];

    // Enter game loop
    while (game.status == 'o') {

        printf("\n""%s\n", game.user_word);

        draw_hangman(game.lives);

        if (my_strcmp(game.user_word, game.word_to_find) == 0) {
            printf("C'est gagné !\n");
            game.status = 'w';
        } else if (game.lives <= 0) {
            printf("Perdu :(\n");
            game.status = 'l';
        }

        if (game.status == 'w' || game.status == 'l') {
            // Close the dictionary to remove the pointer at the end of the file
            fclose(dictionary);

            printf("Voulez-vous recommencer ? Y : Oui, N : Non\n");

            scanf("%s", input_str);


            if (toupper(input_str[0]) == 'Y') {
                dictionary = fopen(dictionary_name, "r");

                word = get_random_word(words);

                init_game(&game, word);

                continue;
            } else {
                printf("Byebye !\n");
                break;
            }
        }

        printf("Tapez une lettre.");

        if (game.word_propositions_left > 0) {
            printf(" Vous pouvez également proposer un mot (restant : %d)", game.word_propositions_left);
        }

        printf("\n");
        
        scanf("%s", input_str);

        printf("Votre lettre : %s\n", input_str);

        // If the user propose one character
        if (my_strlen(input_str) == 1) {
            // printf("String has 1 char\n");

            int i = 0;
            int has_a_matching_char = 0;

            // Check if chosen char is present in the word to find
            while (game.word_to_find[i] != 0) {
                // Check if chosen char match current char
                if (toupper(input_str[0]) == toupper(game.word_to_find[i])) {
                    // Check if current char has yet to be found
                    if (game.user_word[i] == '*') {
                        has_a_matching_char = 1;
                        
                        game.user_word[i] = game.word_to_find[i];
                    }
                }
                i++;
            }

            if (has_a_matching_char == 0) {
                game.lives--;
            }

        // If the user proposes one word
        } else {
            if (game.word_propositions_left > 0) {

                printf("Mot proposé: %s\n", input_str);
                if (my_strcmp(input_str, game.word_to_find) == 0) {
                    // If he's right, the word is considered found
                    game.user_word = game.word_to_find;
                } else {
                    // Else he lose one possibility to propose a word
                    game.word_propositions_left--;
                }
            } else {
                printf("Vous ne pouvez plus proposer de mot.\n");
            }
        }
    }

    int word_index = 0;

    // Free the words at the end of the game
    while (words[word_index].word != 0) {
        free(words[word_index].word);
        word_index++;
    }

    free(words);

    return 0;
}