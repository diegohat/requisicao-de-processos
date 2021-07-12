all:
	gcc main.c disk.c process.c memory.c swap.c -o main
run:
	./main