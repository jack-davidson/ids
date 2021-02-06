.POSIX:

LDFLAGS = -lncurses -lreadline
#CLFAGS = 

SRC = ids.c
OBJ = ${SRC:.c=.o}

all: ids

ids: ${OBJ}
	${CC} $^ -o $@ ${LDFLAGS}

${OBJ}: ${SRC}
	${CC} -c $^ ${CFLAGS}

clean:
	rm -f ids ${OBJ}
