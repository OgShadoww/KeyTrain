TARGET = train

SRC = main.c

LIBS = -lncurses

CFLAGS = -Wall -Wextra

$(TARGET) : $(SRC)
	gcc $(CFLAGS) $(SRC) -o $(TARGET) $(LIBS)

clean:
	rm -f $(TARGET)
