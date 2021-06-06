# Created by Dima Sushchenko
# Date: 01.06.2021
# Last Update: 02.06.2021
# Makefile to build a project from .cpp files.
#

# Constants
TRUE = true
FALSE = false

# Chosen compiler
CC = gcc

# Chosen modes
DEBUG_MODE = Debug
RELEASE_MODE = Release

BUILD_MODE = $(DEBUG_MODE)
AUTO_RUN = $(FALSE)

# Flags for two build modes
Release_FLAGS = -O3 -s -DNDEBUG
Debug_FLAGS = -O0 -g -Wall

# EXECUTABLE - main filename
# SOURCES - returns list of all .cpp files
EXECUTABLE = main
SOURCES = $(shell find ./include -name '*.cpp')

# Run build
all: build run

# Build project
build:
	@mkdir -p $(BUILD_MODE)
	$(CC) $($(BUILD_MODE)_FLAGS) $(EXECUTABLE).cpp $(SOURCES) -o $(BUILD_MODE)/$(EXECUTABLE)
	@echo "makefile: \033[;32mBuild successful!\033[0m"

# Run program after build
run:
ifeq ($(AUTO_RUN),$(TRUE))
	@$(BUILD_MODE)/$(EXECUTABLE)
endif

# Debugging program
gdb:
	@gdb $(DEBUG_MODE)/$(EXECUTABLE)

# Remove folders with executable files
clean: rm_debug rm_release

rm_debug:
	@rm -rf $(DEBUG_MODE)

rm_release:
	@rm -rf $(RELEASE_MODE)

.PHONY: all build run test gdb clean rm_debug rm_release