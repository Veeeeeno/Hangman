CC = gcc
CFLAGS = -g -Wall --std=c99
OBJECTS = my_string.o unit_test.o test_def.o

unit_test: $(OBJECTS)
	$(CC) $(CFLAGS) -o unit_test unit_test.o test_def.o my_string.o
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o
my_string.o: my_string.c my_string.h status.h
	$(CC) $(CFLAGS) -c my_string.c -o my_string.o
clean:
	rm unit_test $(OBJECTS)
unit_test.o: unit_test.c unit_test.h 
	$(CC) $(CFLAGS) -c unit_test.c -o unit_test.o
test_def.o: test_def.c  unit_test.h
	$(CC) $(CFLAGS) -c test_def.c -o test_def.o
