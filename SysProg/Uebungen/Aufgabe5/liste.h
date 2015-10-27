/*
 * liste.h
 *
 * Liest Fachnamen mit Beurteilung ein und gibt dann einen Notenspiegel aus.
 *
 * Autor: Marcel
 * Erstellt am: 10.06.2015
 */
 
#ifndef LISTE_H
#define LISTE_H

/*ist fuer Prototypen unten benoetigt*/
#include "fachnote.h"

/*Funktions-Prototypen*/
fach_note* einfuegen(fach_note*, fach_note*, fach_note**);/*add mit entfernen von doppelten*/
void schleife(const fach_note*, void (*) (const fach_note*));
fach_note* entfernen(fach_note*, fach_note**);/*alle Elemente der Liste loeschen und speicher frei geben */
 
#endif