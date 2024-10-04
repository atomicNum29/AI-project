CC = gcc
CFLAGS = -g

SRC_DIR = /Users/bagsiu/Downloads/INU/2024-2/AI-project/ANNwithC
OBJ_DIR = /Users/bagsiu/Downloads/INU/2024-2/AI-project/.execFiles/obj
BIN_DIR = /Users/bagsiu/Downloads/INU/2024-2/AI-project/.execFiles/bin

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
TARGET = $(BIN_DIR)/main

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f %(OBJ_DIR)/*.o $(TARGET)

