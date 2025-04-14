ifeq ($(findstring MINGW, $(shell uname -s)), MINGW)
	MINGW = 1
endif

CC = gcc
TARGET = train
SRC = main.c
LIBS =
CFLAGS = -Wall -Wextra

ifdef MINGW
	LIBS += -lncursesw
	CFLAGS += -I/mingw64/include/ncurses/
else
	LIBS += -lncurses
endif

$(TARGET): Makefile $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LIBS)
