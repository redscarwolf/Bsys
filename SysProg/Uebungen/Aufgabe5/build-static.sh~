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

#erstelle .a Datei, statische Lib-Datei
afile="fachnote.o liste.o"
lib_command="ar rs libaufgabe5.a $afile"
echo $lib_command
eval $lib_command
if [ $? -ne 0 ] ; then
    echo build failed
    exit 1
fi

#fuege .a zu main dazu und erstelle ein ausfuehrbares Program
ofile="notenspiegel notenspiegel.o -L. -laufgabe5"
link_command="gcc -o $ofile"
echo $link_command
eval $link_command
if [ $? -ne 0 ] ; then
    echo build failed
    exit 1
fi
echo build successful