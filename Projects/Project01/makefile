p1: functions.h p1.o functions.o
	gcc p1.o functions.o -Wall -o p1
	make test

p1.o: functions.h p1.c
	gcc -c p1.c

functions.o: functions.h functions.c
	gcc -c functions.c

test: test1 test2 verify

test1:
	./p1 e ZYXWVUTSRQPONMLKJIHGFEDCBA data.txt data.out

test2:
	./p1 d ZYXWVUTSRQPONMLKJIHGFEDCBA data.out data.bak

verify:
	diff -s data.txt data.bak

clean:
	rm -f p1 *.o data.bak data.out
