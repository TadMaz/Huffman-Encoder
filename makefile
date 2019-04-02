# include dependencies; rules below
ifeq ($(UNAME),incl.defs)
	include incl.defs
endif

# Directories
SRC=./src
BIN=./bin

CC=g++
CCFLAGS=-std=c++11
SOURCES= HuffmanNode.cpp HuffmanTree.cpp huffencode.cpp 
OBJECTS= HuffmanNode.o HuffmanTree.o huffencode.o 

main: $(OBJECTS)
	$(CC) $(CCFLAGS) $(OBJECTS) -o huffencode $(LIBS)

.cpp.o:
	$(CC) $(CCFLAGS) -c $<

# Type "make depend" to make dependencies
depend:
	$(CC) -M $(SOURCES) > incl.defs

run:
	./huffencode

clean:
	rm *.o
	rm main
	rm incl.defs
	rm *.tar.gz
tar:
	tar -zcvf MZRTAD001.tar.gz makefile README.txt *.cpp *.h .git