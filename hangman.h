#ifndef HANGMAN_H
#define HANGMAN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct Game
{
    char status; // w = win, l = lose, o = ongoing, r = restart
    int lives;
    int word_propositions_left; // For the user to propose a word
    char *word_to_find;
    char *user_word; // The hidden word displayed to the user
}_Game;

typedef struct Word
{
    char *word;
    char *difficulty;
    char *category;
}_Word;

void init_game(_Game *game, char *word_to_find);
int my_strlen(char *str);
int my_strcmp(char *s1, char *s2);
char *my_strdup(char *str);
char *rtrim(char *s);
int my_strcmp(char *s1, char *s2);
int my_strlen(char *str);
char *my_strdup(char *str);
FILE * read_file(char *file_name);
_Word *get_words_from_dict(FILE *dictionary_file, char *category, char *difficulty);
char *get_random_word(_Word *words);
void display_help();
void draw_hangman(int remaining_lives);


#endif // HANGMAN_H
