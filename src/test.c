#include "wordle.h"

int main() {
	char* answer = getWordFromDictionary();
	printf("%s\n", answer);
	playGame(answer);
	free(answer);
	return 0;
}
