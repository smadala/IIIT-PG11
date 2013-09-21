app : yshell.o parse.o cd.o
	g++ -g -o app yshell.o parse.o cd.o
	
yshell.o : yshell.cpp yshell.h
	   g++ -c -g yshell.cpp

cd.o : cd.cpp yshell.h
	g++ -c -g cd.cpp yshell.h

parse.o : parse.cpp yshell.h
	g++ -c -g parse.cpp

