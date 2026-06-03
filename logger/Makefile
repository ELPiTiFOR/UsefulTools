CC = gcc
CPPFLAGS = -Isrc/ -Ilibs/ -Itests/
# LDFLAGS = -Llibs/
# LDLIBS = -lconfig

CFLAGS = -std=c99 #-g

SRC = \
	src/logger.c \

OBJ = ${SRC:.c=.o}

SRCTEST = \
	$(SRC) \
	tests/test.c \
	tests/test_fun.c \

OBJTEST = ${SRCTEST:.c=.o}

test: $(OBJTEST)
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(LDLIBS)

clean:
	$(RM) test.exe test $(OBJTEST) *.log