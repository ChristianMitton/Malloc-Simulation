all: first

first: memgrind.c
	gcc memgrind.c -o memgrind

clean:
	rm -rf fourth
