#
# /bin/Makefile
#
# erstellt ein ausführbares Programm notenspiegel,
# das mit der Bibliothek (libaufgabe6.) aus dem Unterverzeichnis lib gebunden wird.
#
#
# Autor: Marcel Kieser
# Erstellt am 19.06.2015
#

# Kommando Variablen
CC = gcc
CFLAGS = -g -W -Wall -ansi -pedantic
CPPFLAGS = -I../lib
# TODO verzeichnis von Bib mit -L./lib  name mit -laufgabe6
LDFLAGS = -L../lib -l
RM = rm -f

#Hilfsvariablen
TARGET = notenspiegel
LIBRARY = aufgabe6
LIBTYPE = a
#ganzen pfad angeben!!!
HEADERS = ../lib/fachnote.h ../lib/liste.h

# Standardziele:
.PHONY: all clean

all: $(TARGET)

clean:
	$(RM) $(TARGET) $(TARGET).o depend

#explizite Regel zum binden der main Datei mit der Bib-Datei
# gcc notenspiegel.o -L../lib -laufgabe6 -o notenspiegel
$(TARGET): $(TARGET).o ../lib/lib$(LIBRARY).$(LIBTYPE)
	$(CC) $(TARGET).o $(LDFLAGS)$(LIBRARY) -o $(TARGET)


#erstelle notenspiegel.o
#
# erstellt Datei "depend" zum abspeichern des Textes der Abhaengigkeitsregeln
depend: $(TARGET).c $(HEADERS)
	$(CC) $(CPPFLAGS) -MM $(TARGET).c > $@

# Abhaengigkeitsregeln für die beiden Objektdateien
include depend

#Musterregel um .c Dateien zu .o Dateien zu uebersetzen
%.o: %.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS)  $<


