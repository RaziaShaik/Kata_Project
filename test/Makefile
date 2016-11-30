CC=gcc -std=c99
CFLAGS=-I. 
OBIN = ../bin
TARGET = $(OBIN)/test # target lib
PWD = $(pwd)
LFLAGS = -L$(PWD)../lib
LIBS = -lkata
DEPS= 

SRCS = test.c
 
$(TARGET): $(LIBS)
	export LD_LIBRARY_PATH=$(PWD)../lib
	sudo ldconfig 
	$(CC) -o $(TARGET) $(SRCS) $(LFLAGS) $(LIBS) 

run:
	(cd $(OBIN); ./test)

.PHONY: clean

clean:
	rm -f *.o ${TARGET} 
