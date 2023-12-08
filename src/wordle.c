#include "wordle.h"

void print(char* s, Color color) {
	switch(color) {
		case white: printf("\033[0m%s\033[0m", s); break;
		case green: printf("\033[0;32m%s\033[0m", s); break;
		case yellow: printf("\033[0;33m%s\033[0m", s); break;
		case black: printf("\033[0;30m%s\033[0m", s); break;
	}
}

void capitalise(char* s) {
	int i = 0;
	while(s[i] != '\0') {
		if(s[i] >= 'a' && s[i] <= 'z') {
			s[i] -= 32;
		}
		i++;
	}
}

char* getWordFromDictionary() {
	FILE* dict = fopen("assets/dictionary.txt", "r");
	int numberOfWords = 0;
	if(dict == NULL) {
		printf("Dictionary not found\n");
		return NULL;
	}
	char c = fgetc(dict);
	while(!feof(dict)) {
		if(c == '\n') numberOfWords++;
		c = fgetc(dict);
	}
	printf("Number of words in dictionary is %d\n", numberOfWords);
	return NULL;
}
