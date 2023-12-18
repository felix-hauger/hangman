# Hangman

Hangman game written in C

## How to install

1. Pull the repository or download and extract the archive
2. Compile the code into an executable: `gcc -Wall -Wextra -Werror -o main *.c`

## How to play

Launch the program with the next arguments: 
1. The name of the file containing the word list
2. The difficulty (easy/medium/hard)
3. The category, which is optional

Example:
```c
./hangman dict.csv easy languages
```