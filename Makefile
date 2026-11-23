CC = gcc
CFLAGS = -D_DEFAULT_SOURCE -Wall -Wextra -pedantic

INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

MKDIR_CMD = mkdir -p
RM_CMD = rm -rf

OBJS = \
			$(OBJ_DIR)/terminal_utils.o \
			$(OBJ_DIR)/main.o


all: clean diretorio $(BIN_DIR)/main

$(BIN_DIR)/main: diretorio $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

diretorio:
	$(MKDIR_CMD) $(BIN_DIR) $(OBJ_DIR)

clean: 
	$(RM_CMD) $(BIN_DIR) $(OBJ_DIR)

.PHONY: all clean