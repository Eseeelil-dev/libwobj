# $@ - The name of the target of the rule
# $^ - The name of all prerequisites
# $< - The name of the first prerequisite

AR = ar
CC = gcc
CFLAGS = -Wall -ggdb -DLIBWOBJ_DEBUG
INCLUDE = -I./include

SOURCES=src/libwobj.c

bin/libwobj.a: bin/libwobj.o
	${AR} rcs $@ $^

bin/libwobj.o: ${SOURCES}
	${CC} -c ${SOURCES} ${INCLUDE} ${CFLAGS} -o $@

bin/test_static_link: test/test_static_link.c bin/libwobj.a
	${CC} $< -Lbin -lwobj ${INCLUDE} ${CFLAGS} -o $@

tests: bin/test_static_link

clean:
	rm -rfv bin/*

