OLEVEL  = 3
COMMONFLAGS = -g
CC      = gcc
CFLAGS	= -O$(OLEVEL)
WFLAGS	= -std=c11 -Wall -Wextra
LDFLAGS = -lm
ISPC    = ispc
ISPCFLAGS  = -O$(OLEVEL) --pic

TARGETS	= test_simple run_simple run_simple_ispc
SOURCES	= $(shell echo *.c)
OBJECTS = simple_ispc.o simple.o 
TEST_OBJECTS = unity.o

all: $(TARGETS)

run_simple: simple.o run_simple.o 
	$(CC) $(COMMONFLAGS) $(CFLAGS) -o $@ $^ $(LDFLAGS)

run_simple_ispc: simple_ispc.o run_simple_ispc.o 
	$(CC) $(COMMONFLAGS) $(CFLAGS) -o $@ $^ $(LDFLAGS)

test_simple: $(OBJECTS) $(TEST_OBJECTS) test_simple.o
	$(CC) $(COMMONFLAGS) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%_ispc.o: %.ispc
	$(ISPC) $(COMMONFLAGS) $(ISPCFLAGS) $(PARAMFLAGS) -h $(basename $<)_ispc.h -o $@ $<

%.o: %.c
	$(CC) $(COMMONFLAGS) $(CFLAGS) $(WFLAGS) $(PARAMFLAGS)  -c $<

clean:
	rm -f $(TARGETS) *.o .depend

# .depend: $(SOURCES)
# 	$(CC) -MM $^ > $@

# -include .depend

.PHONY: clean all
