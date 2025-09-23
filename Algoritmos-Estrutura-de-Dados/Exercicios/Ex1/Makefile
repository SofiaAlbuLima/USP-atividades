all: circulo.o ponto.o main.o
	gcc circulo.o ponto.o main.c -o main -std=c99 -Wall -lm

ponto.o:
	gcc -c ponto.c -o ponto.o
	
circulo.o:
	gcc -c circulo.c -o circulo.o

zip:
	zip -R arquivo.zip . '*.c' '*.h' 'Makefile' && mv arquivo.zip ~/Downloads

run:
	./main
clean:
	rm ponto.o
	rm circulo.o
	rm main

