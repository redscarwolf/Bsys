/*
 * notenspiegel.c
 *
 * Liest Fachnamen mit Beurteilung ein und gibt dann einen Notenspiegel aus.
 *
 * Autor: Marcel
 * Erstellt am: 10.06.2015
 */

/* #include-Anweisungen, symbolische Konstante, Typen ... */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*fuegt struct fach_note und define N ein, Prototyp von einlesen und ausgeben*/
#include "fachnote.h"

/*fuegt hinzu: Prototyp von einfuegen schleife und entfernen*/
#include "liste.h"

int main(void)
{
    fach_note *notenspiegel = NULL; /*Kopf der Liste*/
    fach_note *p; /*aktuelles Element*/
    fach_note *q; /*rueckgabewert fuer geloeschte Elemente die doppelt sind*/

    /*------------------------------------------- Notenspiegel einlesen */
    fprintf(stderr, "Faecher mit Noten eingeben (Ende mit Strg-D):\n");

    for (;;) /* eine bewusste Entlosschleife*/
    {
        p = (fach_note *) malloc(sizeof (fach_note));
        if (p == NULL)
        {
            fprintf(stderr, "Zu viele Faecher!(Speicher voll)\n");
            break;
        }

        /*Daten ueber scanf einlesen in "p" vom typ fach_note*/
        if (! einlesen(p))
        {
            fprintf(stderr, "Eingabeende!\n");
            free(p);
            break;
        }

        /*Daten in doppeltverkettete Liste einfuegen*/

        notenspiegel = einfuegen(notenspiegel, p, &q);
        if (q != NULL)
        {
            fprintf(stderr, "Alte Eingabe ueberschrieben!\n");
            free(q);
        }
    }

    /*------------------------------------------- Notenspiegel ausgeben */
    printf("Notenspiegel:\n");

    schleife(notenspiegel, ausgeben);/*2erParam: ist ADRESSE der Fkt "ausgeben"*/

    /*------------------------------------------- Notenspiegel loeschen */
    while (notenspiegel != NULL)
    {
        notenspiegel = entfernen(notenspiegel, &p);
        free(p);
    }

    return 0;
}
