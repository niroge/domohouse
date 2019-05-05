CC=clang
CFLAGS=-O2 -march=native -Wall
TARGET=main.c
EXE=main.exe
LINK=`pkg-config --cflags --libs gtk+-3.0`
compile: ${TARGET}
	${CC} ${CFLAGS} ${LINK} ${TARGET} -o ${EXE}
