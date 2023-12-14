#include "wordle.h"

int compareStrings(const void* a, const void* b) {
	return strcmp((char*)a, (char*)b);
}

int numberOfWordsInDictionary() {
	FILE* dict = fopen("assets/dictionary.txt", "r");
	int numberOfWords = 0;
	if(dict == NULL) {
		printf("Dictionary not found\n");
		return 0;
	}
	//getting number of words in dictionary
	char c = fgetc(dict);
	while(!feof(dict)) {
		if(c == '\n') numberOfWords++;
		c = fgetc(dict);
	}
	fclose(dict);
	return numberOfWords;
}

char* getRandomWordFromDictionary() {
	srand(time(0));
	int numberOfWords = numberOfWordsInDictionary();
	//selecting a random word from dictionary
	FILE* dict = fopen("assets/dictionary.txt", "r");
	int index = rand() % numberOfWords;
	//The longest english word is 45 letters long.
	char* buff = (char*) malloc(46 * sizeof(char)); 
	while(index--) fscanf(dict, "%s", buff);
	fclose(dict);
	return buff;
	//don't forget to free later!
}

void sortAndRemoveDuplicates() {
	//sorts the dictionary in order and removes duplicates.
	int numberOfWords = numberOfWordsInDictionary();
	FILE* dict = fopen("assets/dictionary.txt", "r");
	char words[numberOfWords][46];
	for(int i = 0; i < numberOfWords; i++) {
		fscanf(dict, "%s", words[i]);
	}
	fclose(dict);
	qsort(words, numberOfWords, 46 * sizeof(char), compareStrings);
	dict = fopen("assets/dictionary.txt", "w");
	fprintf(dict, "%s\n", words[0]);
	for(int i = 1; i < numberOfWords; i++) {
		if(strcmp(words[i], words[i-1]) == 0) continue;
		fprintf(dict, "%s\n", words[i]);
	}
	fclose(dict);
	return;
}
