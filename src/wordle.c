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

bool isInWord(char a, char* answer) {
	//checks if the character 'a' is in the word 'answer'.
	for(int i = 0; i < strlen(answer); i++) {
		if(a == *(answer + i)) return true;
	}
	return false;
}

bool correctGuess(char* guess, char* answer) {
	if(strcmp(guess, answer) == 0) return true;
	return false;
}

void clearPreviousLine() {
	printf("\x1b[1F"); // Move to beginning of previous line
	printf("\x1b[2K"); // Clear entire line
}

void evaluateGuess(char* guess, char* answer) {
	for(int i = 0; i < strlen(answer); i++) {
			char s[2];
			s[0] = guess[i];
			s[1] = '\0'; //appending null character to a single character to be able to pass it into the print() function
			if(guess[i] == answer[i]) print(s, green);
			else if(isInWord(guess[i], answer)) print(s, yellow);
			else print(s, white);
		}
}

void playGame(char* answer) {
	capitalise(answer);
	int l = strlen(answer);
	char guess[l + 1];
	/*
	scanf("%s", guess);
	capitalise(guess);
	fflush(stdin);
	while(!correctGuess(guess, answer)) {
		clearPreviousLine();
		evaluateGuess(guess, answer);
		printf("\n");
		scanf("%s", guess);
		capitalise(guess);
		fflush(stdin);
	}
	*/
	do {
		scanf("%s", guess);
		capitalise(guess);
		fflush(stdin);
		clearPreviousLine();
		evaluateGuess(guess, answer);
		printf("\n");
	} while(!correctGuess(guess, answer));
	clearPreviousLine();
	print(answer, green);
	printf("\nYou have guessed the word correctly!\n");
}
