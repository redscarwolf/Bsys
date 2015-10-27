#
# Makefile
#
# Autor: M.Kieser
# Erstellt am: 29.07.2015
#
#

CC = gcc
CFLAGS = -g -W -Wall -ansi -pedantic

TARGET = filecopy.c filesize.c
.PHONY: all clean

all: $(TARGET:.c=)

clean:
	$(RM) $(TARGET:.c=) $(TARGET:.c=.o)

