NO_WARNING_FLAGS := -Wno-int-conversion -Wno-unused-result -Wno-unused-variable -Wno-unused-but-set-variable -Wno-unused-parameter -Wno-unused-function -Wno-format -Wno-format-security -Wno-format-extra-args -Wno-implicit-function-declaration -Wno-int-conversion -Wno-incompatible-pointer-types -Wno-poin

default: wordle

all: wordle test

test: src/dictionary.o src/wordle.o src/test.o
	gcc -g src/test.o src/wordle.o src/dictionary.o -o test

wordle: src/dictionary.o src/wordle.o src/main.o
	gcc -g $(NO_WARNING_FLAGS) src/main.o  src/wordle.o  src/dictionary.o -o wordle

src/main.o: src/main.c
	gcc -c -g src/main.c -o src/main.o

src/test.o: src/test.c
	gcc -c -g src/test.c -o src/test.o

src/wordle.o: src/wordle.c
	gcc -c -g src/wordle.c -o src/wordle.o

src/dictionary.o: src/dictionary.c
	gcc -c -g src/dictionary.c -o src/dictionary.o

clean:
	rm wordle test src/*.o
