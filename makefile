CC = g++ -std=c++14 -O2
objects = 
execs = 

objects += cezar-enc.o
execs += cezar-enc

objects += cezar-can.o
execs += cezar-can

objects += cezar-keyword-can.o
execs += cezar-keyword-can

objects += afina-enc.o
execs += afina-enc

objects += afina-dec.o
execs += afina-dec

objects += afina-stosic-can.o
execs += afina-stosic-can

common.o: makefile
	$(CC) -c common.cpp -o common.o

$(objects): %.o: %.cpp makefile
	$(CC) -c $< -o $@

$(execs): %: %.o common.o makefile
	$(CC) $< common.o -o $@

clean: makefile
	rm -f common.o $(objects) $(execs)
