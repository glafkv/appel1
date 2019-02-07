appel1: appel1.o
	gcc -o appel1 appel1.o

appel1.o: appel1.c
	gcc -c appel1.c	

.PHONY:	clean
clean:
	/bin/rm -f *.o *~ proj1
