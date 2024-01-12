#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "hangman.h"


// char *hide_word
FILE * read_file(char *file_name)
{
    return fopen(file_name, "r");
}

char *ltrim(char *s)
{
    while(isspace(*s)) s++;
    return s;
}

char *rtrim(char *s)
{
    char* back = s + strlen(s);
    while(isspace(*--back));
    *(back+1) = '\0';
    return s;
}

char *trim(char *s)
{
    return rtrim(ltrim(s)); 
}

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] || s2[i]) {
        if (s1[i] > s2[i]) {
            return 1;
        } else if (s2[i] > s1[i]) {
            return -1;
        }
        i++;
    }
    return 0;
}

int my_strlen(char *str)
{
    int len = 0;

    while (str[len] != 0) {
        len++;
    }

    return len;
}

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i] != 0) {
        dest[i] = src[i];

        i++;
    }

    dest[i] = 0;

    return dest;
}

char *my_strdup(char *src)
{
    int str_length = my_strlen(src);

    char *str = (char*)malloc(sizeof(char*) * str_length);

    my_strcpy(str, src);

    return str;
}