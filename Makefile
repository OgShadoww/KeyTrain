TARGET = train

SRC = main.c

FLAGS = -lncurses

TARGET : SRC
	gcc $(SRC) -o $(TARGET) $(FLAGS)

clean:
	rm -f $(TARGET)
