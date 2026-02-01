CC = gcc

CPPFLAGS = -Isrc/
CFLAGS = -Wall -Wextra -std=c99 -pedantic -g

SRC = \
	src/config.c \

OBJ = ${SRC:.c=.o}

SRCMAIN = \
	$(SRC) \
	src/main.c \

OBJMAIN = ${SRCMAIN:.c=.o}

SRCTEST = \
	$(SRC) \
	tests/test.c \
	tests/test_fun.c \
	tests/check_config.c \

OBJTEST = ${SRCTEST:.c=.o}

all: main

lib: $(OBJ)
	ar csr libconfig.a $(OBJ)

main: $(OBJMAIN)
	$(CC) -o $@ $^

test: $(OBJTEST)
	$(CC) -o $@ $^

clean:
	$(RM) main test libconfig.a $(OBJTEST) $(OBJMAIN)
