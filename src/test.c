#include "wordle.h"

int main() {
	char* answer = getRandomWordFromDictionary();
	// printf("%s\n", answer);
	playGame(answer);
	free(answer);
	return 0;
}
