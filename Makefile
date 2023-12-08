clean:
	@rm wordle

wordle:
	@gcc src/test.c src/wordle.c -o wordle
