CC 	:= gcc
CFLAGS := -Wall -Wextra -std=c99

BIN := bin
SRC := src
INCLUDE := include
LIB := lib
LIBRARIES :=
EXECUTABLE := termi

all: $(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
	-rm $(SRC)/*.o
