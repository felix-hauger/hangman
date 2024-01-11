#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hangman.h"

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

    char *word = get_random_word(argv[1], argv[3], argv[2]);

    printf("Word: %s\n", word);

    _Game game;

    init_game(&game, word);


    printf("Word to find: %s\n", game.word_to_find);
    printf("User word: %s\n", game.user_word);

    return 0;
}