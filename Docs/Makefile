# Makefile for compiling C programs with the 'cs50.h' library on Mac
# Author: Muhammed Azhar (github.com/muhammedazhar)

# ANSI color codes for output formatting
BOLD := \033[1m
GREEN := \033[32m
RESET := \033[0m
LINK_START := \033]8;;
LINK_MID := \007
LINK_END := \033]8;;\007

# Version and build information
COPYRIGHT_YEAR := 2024
CUSTOM_MAKE_VERSION := 1.3.2    # Update this version number as needed
CURRENT_BUILD := $(shell uname -m)-apple-$(shell uname -s | tr '[:upper:]' '[:lower:]')$(shell uname -r)
MAKE_BUILD_TARGET := $(shell make --version | grep "built for" | sed 's/.*built for \(.*\)/\1/')
GNU_MAKE_VERSION := $(shell $(MAKE) --version | head -n1 | sed 's/^[^0-9]*\([0-9\.]*\).*/\1/')
VERSION := $(GNU_MAKE_VERSION) | CS50 Makefile $(CUSTOM_MAKE_VERSION)

# Author information
AUTHOR := Muhammed Azhar
AUTHOR_URL := https://github.com/muhammedazhar
PROJECT_URL := $(AUTHOR_URL)/CS50x

# Finds the device details
CHIP := $(shell system_profiler SPHardwareDataType | awk -F': ' '/Chip/{print $$2}')
MODEL := $(shell system_profiler SPHardwareDataType | awk -F': ' '/Model Name/{print $$2}')
DEVICE := $(CHIP) $(MODEL)

# Determine the default C compiler on Mac
MCC := $(shell cc -v 2>&1 | grep -o 'clang\|gcc' | head -n1)
CC := $(MCC)

# Setting flags and libraries
C_ERROR = -pedantic
CFLAGS = -Wall -Wextra -Werror -std=c11
LIBRARY = -lcs50

# List all C source files in the directory
SOURCE_FILES = $(wildcard *.c)
EXECUTABLES = $(patsubst %.c,%,$(SOURCE_FILES))

# Displays the version information of the Makefile
.PHONY: version --version -v
--version -v:
	@echo "GNU Make $(VERSION)"
	@echo "Copyright (C) $(COPYRIGHT_YEAR) $(AUTHOR)"
	@echo "This is free software; see the source for copying conditions."
	@echo "There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A"
	@echo "PARTICULAR PURPOSE."
	@echo ""
	@echo "Current system is $(CURRENT_BUILD)"
	@echo "This program built for $(MAKE_BUILD_TARGET)"
	@echo ""
	@echo "Written by $(BOLD)$(GREEN)$(AUTHOR)$(RESET)"
	@echo "Project URL: $(LINK_START)$(PROJECT_URL)$(LINK_MID)$(PROJECT_URL)$(LINK_END)"

# Displays author information
.PHONY: --author
--author:
	@echo "Author: $(BOLD)$(GREEN)$(AUTHOR)$(RESET)"
	@echo "GitHub: $(LINK_START)$(AUTHOR_URL)$(LINK_MID)$(AUTHOR_URL)$(LINK_END)"

# Displays information about the current compiler and device
.PHONY: which_compiler
which_compiler:
	@echo "CS50 Make Compiler Information"
	@echo "Compiler: $(CC)"
	@echo "Target: $(BUILD_TARGET)"
	@echo "Host Device: $(DEVICE)"

# Displays information about the device
.PHONY: which_device
which_device:
	@echo "CS50 Make Device Information"
	@echo "Device: $(DEVICE)"
	@echo "Architecture: $(shell uname -m)"
	@echo "Operating System: $(shell sw_vers -productName) $(shell sw_vers -productVersion)"

# Compilation targets
.PHONY: all
all: $(EXECUTABLES)

# Compiles user-specified target files
%: %.c
	@$(CC) $(CFLAGS) -o $@ $< $(LIBRARY)

# Specific target for pedantic compilation
.PHONY: pedantic
pedantic: CFLAGS += $(C_ERROR)
pedantic: $(EXECUTABLES)

# Removes all compiled programs except the source files
.PHONY: clean
clean:
	@rm -f $(EXECUTABLES)
	@rm -rf *.dSYM
