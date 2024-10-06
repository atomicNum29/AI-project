CC = gcc
CFLAGS = -g -MMD -MP

CURRENT_DIR := $(shell pwd)
SRC_DIR = $(CURRENT_DIR)
OBJ_DIR = $(CURRENT_DIR)/../.execFiles/obj
BIN_DIR = $(CURRENT_DIR)/../.execFiles/bin

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
TARGET = $(BIN_DIR)/main

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

-include $(OBJ_FILES:.o=.d)

clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)
	rm -f $(BIN_DIR)/*.o $(TARGET)

