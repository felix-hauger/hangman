#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "hangman.h"

int main(int argc, char *argv[])
{
    FILE * dictionary = read_file(argv[1]);

    // Testing args
    printf("You have entered %d arguments:\n", argc);

    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    if (dictionary == NULL) {
        printf("%s\n", "Erreur: Dictionnaire sélectionné non valide");

        return 1;
    }

    char *word = get_random_word(dictionary, argv[3], argv[2]);

    // char *chara = "é";

    // printf("TEST %s\n, toupper: ", chara);
    
    // // printf("char: %c, toupper: %c\n", chara, toupper(chara));

    printf("Word: %s\n", word);

    _Game game;

    init_game(&game, word);


    printf("Word to find: %s\n", game.word_to_find);

    char input_str[20];

    while (game.status == 'o') {
        if (my_strcmp(game.user_word, game.word_to_find) == 0) {
            printf("C'est gagné !\n");
            break;
            // printf("Voulez-vous recommencer ? Y : Oui, N : Non\n");
        } else if (game.lives <= 0) {
            printf("Perdu :(\n");
            break;
        }

        printf("User word: %s\n", game.user_word);
        printf("You have %d lives\n", game.lives);

        printf("Tapez une lettre\n");
        
        scanf("%s", input_str);

        printf("Votre lettre : %s\n", input_str);

        if (my_strlen(input_str) == 1) {
            printf("String has 1 char\n");

            int i = 0;
            int has_a_matching_char = 0;

            while (game.word_to_find[i] != 0) {
                if (toupper(input_str[0]) == toupper(game.word_to_find[i])) {
                    has_a_matching_char = 1;
                    
                    game.user_word[i] = game.word_to_find[i];
                }
                i++;
            }

            if (has_a_matching_char == 0) {
                game.lives--;
            }

        } else {
            printf("String has %d chars", my_strlen(input_str));
        }

    }

    return 0;
}