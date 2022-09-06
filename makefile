all: build run


build:
	gcc -I  ./include/ -o ./lib/kisi.o -c ./src/kisi.c
	gcc -I  ./include/ -o ./lib/dosya.o -c ./src/dosya.c
	gcc -I  ./include/ -o ./lib/oyun.o -c ./src/oyun.c
	gcc -I  ./include/ -o ./bin/main ./lib/kisi.o ./lib/dosya.o ./lib/oyun.o ./src/main.c

run: 
	./bin/main
