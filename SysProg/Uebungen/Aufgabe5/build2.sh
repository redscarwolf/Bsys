#!/bin/sh

#erstellt .o Dateien in einer for-each Schleife, cfile ist der "Array"
cfile="notenspiegel.c fachnote.c liste.c"

for s in $cfile ; do
    compile_command="gcc -c -I. -g -W -Wall -ansi -pedantic $s"
    echo $compile_command #Text-Ausgabe an Konsole
    eval $compile_command # eigentliche Berechnung
    if [ $? -ne 0 ] ; then
        echo build failed
        exit 1
    fi
done

# zusammen fuegen zu einer ausfuerbaren Datei
ofile="notenspiegel notenspiegel.o fachnote.o liste.o"
link_command="gcc -o $ofile"
echo $link_command
eval $link_command
if [ $? -ne 0 ] ; then
    echo build failed
    exit 1
fi
echo build successful

