
#Copyright 2026 JATIN AGGARWAL
#
#Permission is hereby granted, free of charge, to any person obtaining a copy of this software
#and associated documentation files (the “Software”), to deal in the Software without restriction,
#including without limitation the rights to use, copy, modify, merge, publish, distribute,
#sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
#subject to the following conditions:
#
#The above copyright notice and this permission notice shall be included in all copies
#or substantial portions of the Software.
#
#THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
#INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
#IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
#WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
#OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


CC := g++
CPPFLAGS := -std=c++17 -mavx2 -mavx512f -Wall -MP -MD

TARGET := driver

SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)

DEPS := intrin_generic.h

ifneq (,$(findstring indows,$(OS)))
    # --- WINDOWS SETTINGS ---
    CLEAN_CMD := del /F /Q
    # Windows exes have .exe extension
    TARGET_BIN := $(TARGET).exe
    # Hide error if file not found
    ERR_IGNORE := 2>NUL
else
    # --- LINUX SETTINGS ---
    CLEAN_CMD := rm -f
    # Linux binaries usually have no extension
    TARGET_BIN := $(TARGET)
    # No special error hiding needed for rm -f
    ERR_IGNORE :=
endif

all := $(TARGET)

$(TARGET) : $(OBJS)
	@echo "LINKING $(TARGET) ... "
	$(CC) $(CPPFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp $(DEPS)
	@echo "COMPILING $< ..."
	$(CC) $(CPPFLAGS) -c $< -o $@

.PHONY: clean
clean:
	@echo "CLEANING ... "
	$(CLEAN_CMD) $(OBJS) $(TARGET_BIN) $(ERR_IGNORE) $(wildcard *.d)

.PHONY: run
run: $(TARGET)
	./$(TARGET)
