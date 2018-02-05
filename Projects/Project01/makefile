p1:
	gcc p1.c functions.c -o p1
	make test

test: test1 test2 verify
test1:
	./p1 e infinitestring data.txt data.out
test2:
	./p1 d infinitestring data.out data.bak
verify:
	diff -s data.txt data.bak

clean:
	rm *.bak
	rm *.out
	rm p1
