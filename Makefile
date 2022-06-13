run : main.o ytree.o
	gcc -Wall -o ytree *.o
	
clean :
	rm *.o	
		
ytree.o : ytree.c ytree.h
	gcc -c ytree.c

main.o : main.c ytree.h
	gcc -c main.c

