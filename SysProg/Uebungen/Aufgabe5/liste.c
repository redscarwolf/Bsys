/*
 * liste.c
 *
 * Liest Fachnamen mit Beurteilung ein und gibt dann einen Notenspiegel aus.
 *
 * Autor: Marcel
 * Erstellt am: 10.06.2015
 */
 
 /* #include-Anweisungen, symbolische Konstante, Typen ... */
#include <string.h>

/*fuegt struct fach_note und define N ein, Prototyp von einlesen und ausgeben*/
#include "fachnote.h"

/*fuegt hinzu: Prototyp von einfuegen schleife und entfernen*/
#include "liste.h"

/* Funktionsimplementierungen */
 
fach_note* einfuegen( fach_note* head, fach_note* elementNeu, fach_note** elementEntf)
{

    fach_note *h = elementNeu;
    *elementEntf = NULL;

    /*Am Kopf einfuegen| danach zeigt elementNeu auf head | bei leerer Liste wird einfach NULL geschrieben  */
    elementNeu->next = head;

    /*wenn Liste NICHT Leer, dann zeigt bisherige Liste auf neues Element per prev*/
    if(head != NULL)
    {
        head->prev = elementNeu;
    }
    head = elementNeu; /*head wird auf 1es Element gerichtet*/

    /*gibt es das Element schon? | Schleife*/
    while (h->next != NULL)
    {
        h = h->next;
        if(!strcmp(elementNeu->fach, h->fach) && elementNeu->art == h->art )
        {
            *elementEntf = h; /*doppeltes Element gefunden*/
            break;
        }
    }

    /*Wenn es ein doppeltes Element gibt, dann loeschen*/
    if (*elementEntf != NULL)
    {
        (*elementEntf)->prev->next = NULL; /*vorgaenger-NextVariable auf jeden Fall mal auf NULL setzen*/
        if ((*elementEntf)->next) /*wird nur gemacht, wenn es ein nachfolge Element gibt*/
        {
            (*elementEntf)->next->prev = (*elementEntf)->prev; /*nachfolger einen Wert zuweisen*/
            (*elementEntf)->prev->next = (*elementEntf)->next; /*vorgaenger das naechste Element zuweisen*/
        }

        /*entferne next und prev von entfernten Element*/
        (*elementEntf)->next = NULL;
        (*elementEntf)->prev = NULL;
    }

    return head;
}

void schleife(const fach_note* head, void (*fkt) (const fach_note*))
{

    /*bei einer leeren Liste*/
    if (head == NULL)
    {
        /*printf("Leere Liste.\n");*/
        return;
    }

    /*Ausgabe des ersten Elements*/
    fkt(head);
    /*itteriere ueber rest der Liste*/
    while (head->next)
    {
        head = head->next;
        fkt(head);
    }
}

fach_note* entfernen( fach_note* head, fach_note** elementEntf)
{
    /*TODO: Annahme das es keine leere Liste gibt*/

    *elementEntf = head;
    /*haenge erstes Element aus*/
    head = head->next;

    /*wenn nicht alle Elemente jetzt entfernt sind dann loesche prev von folge Element*/
    if ((*elementEntf)->next != NULL)
    {
        (*elementEntf)->next->prev = NULL;
    }

    /*entferne alle Verbindungen von elementEntf zu Liste*/
    (*elementEntf)->next = NULL;

    return head;
}