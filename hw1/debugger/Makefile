CC = gcc
CFLAGS_COMMON = -Wall
CFLAGS_DEBUG = $(CFLAGS_COMMON) -g
CFLAGS_RELEASE = $(CFLAGS_COMMON)

SOURCE = program.c
TARGET = program

all: release

release:
	$(CC) $(CFLAGS_RELEASE) -o $(TARGET) $(SOURCE)

debug:
	$(CC) $(CFLAGS_DEBUG) -o $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET)

.PHONY: all release debug clean