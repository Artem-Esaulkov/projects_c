FLAGS = -Wall -Werror -Wextra

BUILD_DIR = ../../build

MAIN = stat.c
MAX = maxmin.c
DIFF = differ.c
MED = mediana.c
SORT = sort.c

TARGET = static

FILES = $(MAIN) $(MAX) $(DIFF) $(SORT) $(MED)

all: program

program: $(FILES)
	@mkdir -p $(BUILD_DIR)
	gcc $(FLAGS) $(FILES) -o $(BUILD_DIR)/$(TARGET)

clean:
	@rm -rf $(BUILD_DIR)

rebuild: clean all

.PHONY: all program clean rebuild
