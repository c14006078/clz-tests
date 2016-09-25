CC ?= gcc
CFLAGS_common ?= -Wall -std=gnu99
CFLAGS = -O0 -g

EXEC = clz_recursive clz_iterative clz_binary_search clz_byte_shift
all: $(EXEC)

SRCS_common = test.c

%.o: %.c
	$(CC) $(CFLAGS_common) $(CFLAGS) -c $^

clz_recursive: $(SRCS_common) clz_recursive.o
	$(CC) $(CFLAGS_common) $(CFLAGS_opt) \
	 -DVERSION="\"recursive\""	-o $@ $(SRCS_common) $@.o

clz_iterative: $(SRCS_common) clz_iterative.o
	$(CC) $(CFLAGS_common) $(CFLAGS_opt) \
		-DVERSION="\"iterative\"" -o $@ $(SRCS_common) $@.o
		
clz_binary_search: $(SRCS_common) clz_binary_search.o
	$(CC) $(CFLAGS_common) $(CFLAGS_opt) \
		-DVERSION="\"binary_search\""	-o $@ $(SRCS_common) $@.o

clz_byte_shift: $(SRCS_common) clz_byte_shift.o
	$(CC) $(CFLAGS_common) $(CFLAGS_opt) \
	 -DVERSION="\"byte_shift\""	-o $@ $(SRCS_common) $@.o

.PHONY: clean
clean:
	$(RM) $(EXEC) *.o
