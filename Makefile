CFLAGS = -Wall -g

all: main
main: main.c
	gcc $(CFLAGS) main.c -o main
clean:
	rm -f main.exe