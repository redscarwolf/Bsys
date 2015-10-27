#!/bin/sh
# o. Dateien erstellen
gcc -c -I. -g -W -Wall -ansi -pedantic fachnote.c
gcc -c -I. -g -W -Wall -ansi -pedantic liste.c
gcc -c -I. -g -W -Wall -ansi -pedantic notenspiegel.c

# zu einer Datei zusammenfuegen
gcc notenspiegel.o liste.o fachnote.o -o notenspiegel
