#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

#ifndef WORDLE_H
#define WORDLE_H

typedef enum {white, black, green, yellow} Color;

void print(char* s, Color color);
void capitalise(char* s);
char* getWordFromDictionary();

#endif
