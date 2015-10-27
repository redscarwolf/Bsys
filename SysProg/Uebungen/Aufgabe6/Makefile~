#
# /Makefile
#
# ruft erst das Makefile im Unterverzeichnis lib und
# dann das Makefile im Unterverzeichnis bin rekursiv auf.
# 
# Autor: Marcel Kieser
# Erstellt am 19.06.2015
#

# rekursiv erstellen
# zuerst lib dann bin erstellen, damit ueberhaupt libaufgabe6.a/so vorhanden ist.
PACKAGES = lib bin

.PHONY: all clean

all clean:
	for p in $(PACKAGES); do \
		(cd $$p && $(MAKE) $@); \
	done