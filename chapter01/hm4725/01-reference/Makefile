CXX := clang++
CXXFLAGS := -std=c++17
DBGFLAGS := -g
TARGET := run.exe
TARGET_DEBUG := debug.exe
DEBUG_SYMBOL := $(TARGET_DEBUG).dSYM/
SRC := main.cc
CLEAN_LIST := $(TARGET) $(TARGET_DEBUG) $(TARGET_DEBUG) $(DEBUG_SYMBOL)


$(TARGET): $(SRC)
	$(CXX) -o $@ $(SRC) $(CXXFLAGS)

$(TARGET_DEBUG): $(SRC)
	$(CXX) -o $@ $(SRC) $(CXXFLAGS) $(DBGFLAGS)

.PHONY: all
all: $(TARGET)

.PHONY: debug
debug: $(TARGET_DEBUG)

.PHONY: clean
clean:
	rm -rf $(CLEAN_LIST)