#include "wordle.h"

char* getRandomWordFromDictionary() {
	srand(time(0));
	FILE* dict = fopen("assets/dictionary.txt", "r");
	int numberOfWords = 0;
	if(dict == NULL) {
		printf("Dictionary not found\n");
		return NULL;
	}
	//getting number of words in dictionary
	char c = fgetc(dict);
	while(!feof(dict)) {
		if(c == '\n') numberOfWords++;
		c = fgetc(dict);
	}
	fclose(dict);
	//selecting a random word from dictionary
	dict = fopen("assets/dictionary.txt", "r");
	int index = rand() % numberOfWords;
	char* buff = (char*) malloc(46);
	while(index--) fscanf(dict, "%s", buff);
	fclose(dict);
	return buff;
}

void sortAndRemoveDuplicates() {
	//sorts the dictionary in order and removes duplicates.
	
}
