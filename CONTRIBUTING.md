- # Dictionary
You may add english words to ```assets/dictionary.txt```

One word per line, and make sure the number of lines in the file is same as the number of words, i.e. no stray newlines.

- # Yellow/green logic
As of right now, the logic behind making a character yellow or green doesn't account for duplicates.

For example, guessing ```abbey``` for ```about``` will result in one ```b``` being displayed in green, and the other in yellow. This would mean that there's another ```b``` somewhere else in the word according to classic Wordle. However, the current program currently only checks if the character (at all) exists in the string. Therefore, one occurence is enough to make all instances of it occur green/yellow. You may contribute by coming up with another function that assigns colors to the characters of the guessed word.

The changes are to be made in the ```wordle.c``` file, by creating a function similar to ```evaluateGuess```.