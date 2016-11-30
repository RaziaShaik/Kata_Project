CC=gcc -std=c99
LIBS = -lcheck
CFLAGS=-I. 
OBIN = ../bin
TARGET = $(OBIN)/check_kata # target lib
PWD = $(pwd)
CHECK_SRC = check_kata.c
DEPS= 

SRCS = kata.c
		

$(TARGET): $(CHECK)
	$(CC) -o $(TARGET) $(SRCS) $(CHECK_SRC) $(LIBS) 

run:
	(cd $(OBIN); ./check_kata)

check:  
	checkmk check_kata_test.c >check_kata.c

.PHONY: clean

clean:
	rm -f *.o $(CHECK_SRC) ${TARGET} 
