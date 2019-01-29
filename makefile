proj1:	proj1.o
	gcc -o proj1 proj1.o

proj1.o:	proj1.c
	gcc -c proj1.c

.PHONY:	clean
clean:
	/bin/rm -f *.o *~ proj1
