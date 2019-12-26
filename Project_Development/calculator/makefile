test:add.o sub.o
    gcc -g -o test add.o sub.o
add.o: add.c test.h
    gcc -g -c add.c
sub.o:sub.c test.h
    gcc -g -c sub.c
clean:
    rm -rf test
    rm -rf *.o