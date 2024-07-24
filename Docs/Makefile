# Makefile for compiling C programs with the 'cs50.h' library on Mac
# Author: Muhammed Azhar (github.com/muhammedazhar)

# Version of the Makefile
VERSION := 1.2.2

# Author information
AUTHOR := "Muhammed Azhar (https://github.com/muhammedazhar)"

# Finds the device details
CHIP := $(shell system_profiler SPHardwareDataType | awk -F': ' '/Chip/{print $$2}')
MODEL := $(shell system_profiler SPHardwareDataType | awk -F': ' '/Model Name/{print $$2}')

# Concatenates chip and model to form the device name
DEVICE := $(CHIP) $(MODEL)

# Determine the default C compiler on Mac
MCC := $(shell cc -v 2>&1 | grep -o 'clang\|gcc' | head -n1)

# If your compiler is NOT found, you can replace '$(MCC)' to 'gcc' or 'clang' here
CC := $(MCC)

# Setting flags and libraries
C_ERROR = -pedantic
CFLAGS = -Wall -Wextra -Werror -std=c11
LIBRARY = -lcs50

# List all C source files in the directory
SOURCE_FILES = $(wildcard *.c)

# Derive the list of executables from the source files
EXECUTABLES = $(patsubst %.c,%,$(SOURCE_FILES))

# Compiles all executable C programs in one go
.PHONY: all
all: $(EXECUTABLES)

# Compiles user-specified target files
%: %.c
	@$(CC) $(CFLAGS) -o $@ $< $(LIBRARY)

# Specific target for pedantic compilation
pedantic: CFLAGS += $(C_ERROR)
pedantic: $(EXECUTABLES)

# Displays the version of the Makefile
.PHONY: version
version:
	@echo $(VERSION)

# Displays author information
.PHONY: author
author:
	@echo $(AUTHOR)

# Displays information about the current compiler and device
.PHONY: which_compiler
which_compiler:
	@echo "Found '$(CC)' compiler on this $(DEVICE)!"

# Displays information about the device
.PHONY: which_device
which_device:
	@echo "Your device is $(DEVICE)"

# Removes all compiled programs except the source files
.PHONY: clean
clean:
	@rm -f $(EXECUTABLES)
	@rm -rf *.dSYM