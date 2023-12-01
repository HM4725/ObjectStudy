CXX := clang++
CXXFLAGS := -std=c++17
TARGET := run.exe

SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
INCLUDE_DIR := include

EXE := $(BIN_DIR)/$(TARGET)
SRC := $(wildcard $(SRC_DIR)/*.cc)
OBJ := $(SRC:$(SRC_DIR)/%.cc=$(OBJ_DIR)/%.o)

$(EXE): $(OBJ) | $(BIN_DIR)
	$(CXX) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@


.PHONY: all
all: $(EXE)

.PHONY: clean
clean:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR)