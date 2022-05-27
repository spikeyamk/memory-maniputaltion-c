
main.bin: main.o foo.o
	gcc -Wall -Wextra -Wpedantic -g objects/main.o objects/foo.o -o bin/main 

main.o: main.c
	gcc -Wall -Wextra -Wpedantic -g -c main.c -o objects/main.o 

foo.o: foo.c foo.h
	gcc -Wall -Wextra -Wpedantic -g -c foo.c -o objects/foo.o 

clean: 
	rm bin/main
	rm objects/*.o 
