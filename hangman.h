#ifndef HANGMAN_H
#define HANGMAN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct Game
{
    int status; // 1 = win, -1 = lose, 0 = ongoing
    int lives;
    char *word_to_find;
}_Game;

typedef struct Word
{
    char *word;
    char *difficulty;
    char *category;
}_Word;


int my_strlen(char *str);
int my_strcmp(char *s1, char *s2);
char *my_strdup(char *str);
char *rtrim(char *s);
int my_strcmp(char *s1, char *s2);
int my_strlen(char *str);
char *my_strdup(char *str);



#endif // HANGMAN_H
