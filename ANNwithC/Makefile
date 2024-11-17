# 컴파일러 지정
CC = gcc
# 플래그 지정, MMD, MP는 헤더파일 의존성 추가 관련 옵션
CFLAGS = -Wall -g -MMD -MP

# 현재 경로 획득
CURRENT_DIR := $(shell pwd)
# 소스파일 디렉토리
SRC_DIR = $(CURRENT_DIR)
# obj파일 디렉토리
OBJ_DIR = $(CURRENT_DIR)/obj
# 실행파일 디렉토리
BIN_DIR = $(CURRENT_DIR)/bin

# 소스파일 디렉토리의 모든 .c 파일
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
# 모든 소스파일과 대응하는 obj파일
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
# 메인 프로그램 파일
TARGET = $(BIN_DIR)/main

# 타겟의 의존성은 모든 obj파일에 있음
$(TARGET): $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)  # 실행파일 디렉토리 생성
	$(CC) $(CFLAGS) -o $@ $^

# 모든 .c 파일로 obj파일을 생성함
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)  # obj 디렉토리 생성
	$(CC) $(CFLAGS) -c $< -o $@

# 헤더파일 의존성 규칙을 포함
-include $(OBJ_FILES:.o=.d)

# clean 명령
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)
	rm -f $(BIN_DIR)/*.o $(TARGET)

