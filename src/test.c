#include "wordle.h"

int main() {
	char* answer = getRandomWordFromDictionary();
	printf("Answer is %s\n", answer);
	playGame(answer);
	free(answer);
	// sortAndRemoveDuplicates();
	return 0;
}
