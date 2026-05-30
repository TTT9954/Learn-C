all:
	gcc struct_exercise/struct3.c src/RingBuffer.c src/Some_exercises.c src/String.c src/Array.c src/LinkedList.c main.c -o a -I.inc/LinkedList.h
	gcc -g struct_exercise/struct3.c src/RingBuffer.c src/Some_exercises.c src/String.c src/Array.c src/LinkedList.c main.c
