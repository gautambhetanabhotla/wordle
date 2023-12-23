default: wordle

all: wordle test

test: build/dictionary.o build/wordle.o build/test.o
	gcc -g build/test.o build/wordle.o build/dictionary.o -o test

wordle: build/dictionary.o build/wordle.o build/main.o
	gcc -g build/main.o  build/wordle.o  build/dictionary.o -o wordle

build/main.o: src/main.c
	gcc -c -g src/main.c -o build/main.o

build/test.o: src/test.c
	gcc -c -g src/test.c -o build/test.o

build/wordle.o: src/wordle.c
	gcc -c -g src/wordle.c -o build/wordle.o

build/dictionary.o: src/dictionary.c
	gcc -c -g src/dictionary.c -o build/dictionary.o

clean:
	rm wordle test build/*.o
