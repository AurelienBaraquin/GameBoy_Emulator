CFLAGS = -W -Wall -Wextra -I./include
LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRC = $(shell find . -name '*.c')
OBJ = $(SRC:.c=.o)
TARGET = emulator

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) $(LDFLAGS) $(INCLUDE)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(TARGET)

re: fclean all
