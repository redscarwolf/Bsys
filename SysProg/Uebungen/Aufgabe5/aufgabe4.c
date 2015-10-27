/*
 * aufgabe4.c
 *
 * Liest Fachnamen mit Beurteilung ein und gibt dann einen Notenspiegel aus.
 *
 * Autor: Marcel
 * Erstellt am: 8.05.2015
 */

/* #include-Anweisungen, symbolische Konstante, Typen ... */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20 /* Symbolische Variable fuer String fach*/

/*struct Anweisungen*/
enum ben_uben {benotet, unbenotet};
struct fach_note
{
    enum ben_uben art;
    struct fach_note* next;
    struct fach_note* prev;
    union
    {
        int note;/*Bei art = benotet*/
        char status;/*Bei art = unbenotet */
    } u;
    char fach[N];/*String fuer Fach-Name mit einer groesse von 20 Zeichen*/
};
typedef struct fach_note fach_note;/*Jetzt kann ich "fach_note" schreiben*/

/*Funktions-Prototypen*/
int einlesen(fach_note*);
void ausgeben(const fach_note*); /*get| schreibt eine fach_note auf die konsole*/
fach_note* einfuegen(fach_note*, fach_note*, fach_note**);/*add mit entfernen von doppelten*/
void schleife(const fach_note*, void (*) (const fach_note*));
fach_note* entfernen(fach_note*, fach_note**);/*alle Elemente der Liste loeschen und speicher frei geben */

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

/* Funktionsimplementierungen */

int einlesen(fach_note* fn)
{
    /*deklarationen*/
    char *c;/*fuer zwischenspeichern der durch stchr gefundenen Char-Adresse */
    
    /*Fachname einlesen und  bei Strg-D Eingabe beenden*/
    /*scanf braucht eine Adresse "fach" ist die anfangsfnadresse von fach[20]*/
    if (scanf("%s\n", fn->fach) == EOF) 
    {
        return 0; /*lesen ist nicht gelungen*/
    }
    
    /*Fachname "_" ersetzen durch leerzeichen*/
    while (strchr(fn->fach, '_'))
    {
        c = strchr(fn->fach, '_'); /* char* strchr(const char*, int)*/
        *c = ' ';
    }

    /*Beurteilung einlesen*/
    /*TODO:Eingabe: 30dd oder ff behandeln? Muss statt char einen String einlesen*/
    /* zuerst int einlesen wenn keine zahl, char einlesen*/
    if(scanf("%d", &fn->u.note) > 0) /*scanf braucht die Adresse von u.note*/
    {
        fn->art = benotet;
        return 1;
    }
    else
    {
        scanf("%c", &fn->u.status); /*scanf braucht die Adresse von u.status*/
        fn->art = unbenotet;
        return 1;
    }
    
    return 0;/*lesen ist nicht gelungen*/
}

void ausgeben(const fach_note* fn)
{
    /*hilfsvariablen*/
    int nachkomma, vorkomma;

    /*ausgabe*/
    if(fn->art)
    {

        switch (fn->u.status)
        {
        case 'N':
            printf("%-*s\tnicht bestanden\n", N, fn->fach);
            break;
        case 'B':
            printf("%-*s\tbestanden\n", N, fn->fach);
            break;
        default:
            printf("%-*s\tFehler: %c\n", N, fn->fach, fn->u.status);

        }
    }
    else
    {
        switch (fn->u.note)
        {
        case 10:
        case 13:
        case 17:
        case 20:
        case 23:
        case 27:
        case 30:
        case 33:
        case 37:
        case 40:
        case 50:
            nachkomma = fn->u.note % 10;
            vorkomma = (fn->u.note - nachkomma) / 10;
            printf("%-*s\t%d,%d\n", N, fn->fach, vorkomma, nachkomma);
            break;
        default:
            printf("%-*s\tFehler: %d\n", N, fn->fach, fn->u.note);

        }
    }
}

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
        printf("Leere Liste.\n");
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