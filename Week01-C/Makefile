# Makefile for compiling C programs with 'cs50.h' library on Mac
# Author : Muhammed Azhar (github.com/muhammedazhar)

VERSION := 1.2.0
AUTHOR := "Muhammed Azhar (github.com/muhammedazhar)"

# Finds the device details
CHIP := $(shell system_profiler SPHardwareDataType | awk -F': ' '/Chip/{print $$2}')
MODEL := $(shell system_profiler SPHardwareDataType | awk -F': ' '/Model Name/{print $$2}')

DEVICE := $(CHIP) $(MODEL)

# Determine the default C compiler on Mac
CC := $(shell cc -v 2>&1 | grep -o 'clang\|gcc' | head -n1)

# Predefined flags and libraries
C_ERROR = -pedantic
CFLAGS = -Wall -Wextra -Werror -std=c11
LIBRARY = -lcs50

# List all C source files in the directory
SOURCE_FILES = $(wildcard *.c)

# Derive the list of executables from the source files
EXECUTABLES = $(basename $(SOURCE_FILES))

# Complies 
all: $(EXECUTABLES)

%: %.c
	@$(CC) $(CFLAGS) -o $@ $< $(LIBRARY)

# Specific target for pedantic compilation
pedantic: CFLAGS += $(C_ERROR)
pedantic: $(EXECUTABLES)

version:
	@echo $(VERSION)

.PHONY: author
author:
	@echo $(AUTHOR)

which_compiler:
	@echo "Found '$(CC)' compiler on this $(DEVICE)."

which_device:
	@echo "Your device is $(DEVICE)"

clean:
	@rm -f $(EXECUTABLES)