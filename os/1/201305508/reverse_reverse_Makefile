app : main.o reversefile.o
	cc -o app main.o reversefile.o

main.o : main.c reversefile.h
	cc -c main.c

reversefile.o : reversefile.c reversefile.h
	cc -c reversefile.c
clean   :
	'rm' main.o reversefile.o
