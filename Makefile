CC=gcc -std=c99
CFLAGS=-I.
LDFLAGS = -shared # linking flags
OLIB = lib
TARGET_LIB = $(OLIB)/libkata.so # target lib
DEPS= 

ODIR=obj
OSRC=src

_LOCAL_OBJ  = kata.o 
LOCAL_OBJ  = $(patsubst %, $(ODIR)/%, $(_LOCAL_OBJ))

$(ODIR)/%.o: $(OSRC)/%.c $(DEPS)
	$(CC) -c -fPIC -o $@ $< $(CFLAGS)

$(TARGET_LIB): $(LOCAL_OBJ) 
	$(CC) ${LDFLAGS} -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o  ${TARGET_LIB} 
