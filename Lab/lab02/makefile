cipher: cipher.o
	gcc cipher.o -o cipher
	make test

cipher.o: cipher.c

test: test1 test2 verify
test1:
	./cipher 1 infinitestring data.txt data.out
test2:
	./cipher 2 infinitestring data.out data.bak
verify:
	diff -s data.txt data.bak

clean:
	rm *.o
	rm *.bak
	rm *.out
	rm cipher
