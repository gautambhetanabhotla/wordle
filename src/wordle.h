#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<string.h>

#ifndef WORDLE_H
#define WORDLE_H

typedef enum {white, black, green, yellow} Color;

void print(char* s, Color color);
void capitalise(char* s);
char* getWordFromDictionary();
bool isInWord(char a, char* answer);
bool correctGuess(char* guess, char* answer);
void clearPreviousLine();
void playGame(char* answer);

#endif
