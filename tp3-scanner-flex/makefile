all: flex
	gcc *.c -Wall -g -lfl && \
	./a.out < enunciado/entrada.txt  > enunciado/salida.txt  && \
	make clean && \
	echo '\n'Compilacion y ejecucion realizada con éxito

flex:
	flex scanner.l

clean:
	rm scanner.c 
	rm scanner.h