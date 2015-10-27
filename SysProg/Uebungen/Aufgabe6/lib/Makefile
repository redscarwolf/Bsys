#
# /lib/Makefile
#
# erstellt eine Bibliothek mit
# den Uebersetzungseinheiten fachnote und liste,
# wobei der Bibliothekstyp mittels einer Variablen waehlbar is
# 
#
# Autor: Marcel Kieser
# Erstellt am 19.06.2015
#

# Kommando Variablen
# mit Variablen fuer in make schon vordefinierte C-Uebersetzungsregeln
CC = gcc
CFLAGS = -g -W -Wall -ansi -pedantic
CPPFLAGS = -I.
RM = rm -f

#Hilfsvariablen
TARGET = libaufgabe6
LIBTYPE = a
COMBINED = $(TARGET).$(LIBTYPE)

OBJECTS = fachnote.o liste.o
SOURCES = $(OBJECTS:.o=.c)
HEADERS = $(OBJECTS:.o=.h)

# Standardziele: Pseudoziele all und clean
.PHONY: all clean

# alle Endergebnisse, hier nur die libDatei
all: $(COMBINED)

# entfernt alle erstellten Dateien ohne nachzufragen(-f)
clean:
	$(RM) $(TARGET).a $(TARGET).so $(OBJECTS) depend

# erstellt Datei "depend" zum abspeichern des Textes der Abhaengigkeitsregeln
depend : $(SOURCES) $(HEADERS)
	$(CC) $(CPPFLAGS) -MM $(SOURCES) > $@

# eine explizite Regel zum Erstellen der statischen Bibliothek
$(TARGET).a: $(OBJECTS)
	ar rs $(TARGET).a $(OBJECTS)

# eine explizite Regel zum Erstellen der dynamischen Bibliothek
$(TARGET).so: $(OBJECTS)
	$(CC) -shared -o $@ $^

# Abhaengigkeitsregeln für die beiden Objektdateien
include depend

# eine Musterregel für das Uebersetzen der C-Quellen in .o Dateien
# "-fPIC" ist nur fuer dynamische Bib benoetigt
%.o: %.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $< -fPIC

