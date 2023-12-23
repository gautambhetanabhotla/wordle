#include "wordle.h"

int main() {
	char* answer = getRandomWordFromDictionary();
	playGame(answer);
	free(answer);
	return 0;
}
