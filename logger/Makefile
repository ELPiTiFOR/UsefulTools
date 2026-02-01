CC = gcc
CPPFLAGS = -Isrc/ -Ilibs/ -Itests/
LDFLAGS = -Llibs/
LDLIBS = -lconfig

SRC = \
	src/logger.c \

OBJ = ${SRC:.c=.o}

SRCTEST = \
	$(SRC) \
	tests/test.c \
	tests/test_fun.c \

OBJTEST = ${SRCTEST:.c=.o}

test: $(OBJTEST)
	$(CC) $(CPPFLAGS) -o $@ $^ $(LDFLAGS) $(LDLIBS)

clean:
	$(RM) $(OBJTEST)