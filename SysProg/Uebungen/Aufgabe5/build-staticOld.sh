#!/bin/sh
# erstelle .o Dateien
gcc -c -I. -g -W -Wall -ansi -pedantic fachnote.c
gcc -c -I. -g -W -Wall -ansi -pedantic liste.c
gcc -c -I. -g -W -Wall -ansi -pedantic notenspiegel.c

# erstelle .a Datei, statische Lib-Datei 
ar rs libaufgabe5.a fachnote.o liste.o

#fuege .a zu main dazu und erstelle ein ausfuehrbares Program
gcc notenspiegel.o -L. -laufgabe5 -o notenspiegel 