CC=gcc

SRC_DIR := sources
OBJ_DIR := obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

MiniSiteGenerator: $(OBJ_FILES)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I headers -c -o $@ $<

.PHONY: clean

clean:
	rm -f MiniSiteGenerator $(OBJ_FILES)
