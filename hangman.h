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
char *get_random_word(FILE * dictionary_file, char *category, char *difficulty);
void display_help();


#endif // HANGMAN_H
