/*
 * aufgabe4.c
 *
 * Liest Fachnamen mit Beurteilung ein und gibt dann einen Notenspiegel aus.
 *
 * Autor: Sebastian Gruhler
 * Erstellt am: 13.10.2015
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FELDSIZE 21

enum noted {benotet, unbenotet};

struct fach_note
{
    struct fach_note *next;
    struct fach_note *prev;
    char fachname[FELDSIZE];
    enum noted pruefungsart;
    union
    {
        int note;
        char best;
    } beurteilung;
};

typedef struct fach_note fach_note;

void ausgeben(const fach_note*);
int einlesen(fach_note*);
fach_note* einfuegen(fach_note*, fach_note*, fach_note**);
fach_note* entfernen(fach_note*, fach_note**);
void schleife(fach_note *, void (*)(fach_note const *));


int main(void)
{
    fach_note *notenspiegel = NULL; /* Kopf der Liste */
    fach_note *p = NULL; /* Einzufuegendes oder zu entfernednes struct */
    fach_note *q = NULL; /* Ausgabeparamter fuer das entfernte Element */

    /*------------------------------------------- Notenspiegel einlesen */
    fprintf(stderr, "Faecher mit Noten eingeben (Ende mit Strg-D):\n");

    for (;;)
    {
        p = (fach_note *) malloc(sizeof (fach_note));
        if (p == NULL)
        {
            fprintf(stderr, "Zu viele Faecher!\n");
            break;
        }

        if (! einlesen(p))
        {
            fprintf(stderr, "Eingabeende!\n");
            free(p);
            break;
        }

        notenspiegel = einfuegen(notenspiegel, p, &q);
        if (q != NULL)
        {
            fprintf(stderr, "Alte Eingabe ueberschrieben!\n");
            free(q);
        }
    }

    /*------------------------------------------- Notenspiegel ausgeben */
    printf("Notenspiegel:\n");

    schleife(notenspiegel, ausgeben);

    /*------------------------------------------- Notenspiegel loeschen */
    while (notenspiegel != NULL)
    {
        notenspiegel = entfernen(notenspiegel, &p);
        free(p);
    }

    return 0;
}

void ausgeben(const fach_note* element)
{
    char note[FELDSIZE];
    char buffer[5];
    if(element->pruefungsart == 0)
    {
        if(((element->beurteilung.note >= 10) && (element->beurteilung.note <= 40)) || (element->beurteilung.note == 50))
        {
            sprintf(buffer, "%d", element->beurteilung.note);
            note[0] = buffer[0];
            note[1] = ',';
            note[2] = buffer[1];
            note[3] = '\0';

            printf("%-20s\t%s\n", element->fachname, note);
        }
        else
        {
            printf("%-20s\tFehler: %d\n", element->fachname, element->beurteilung.note);
            return;
        }
    }
    else
    {
        if(element->beurteilung.best == 'B' || element->beurteilung.best == 'N')
        {
        
            if(element->beurteilung.best == 'B')
            {
                printf("%-20s\tbestanden\n", element->fachname);
            }
            else
            {
                printf("%-20s\tnicht bestanden\n", element->fachname);
            }
        }
        else
        {
            printf("%-20s\tFehler: %c\n", element->fachname, element->beurteilung.note);
            return;
        }
    }
}

int einlesen(fach_note* fn)
{
    int note;
    int is_benotet;

    fn->next = NULL;
    fn->prev = NULL;

    is_benotet = scanf("%20s %i", fn->fachname, &note);

    if(is_benotet == 1)
    {
        scanf("%c", &(fn->beurteilung.best));
        fn->pruefungsart = unbenotet;
    }
    else if(is_benotet == 2)
    {
        fn->pruefungsart = benotet;
        fn->beurteilung.note = note;
    }
    else
    {
        if(is_benotet != -1) /* Is not EOF */
        {
            printf("Falsche Eingabe\n");
        }
        return 0;
    }

    while(strchr(fn->fachname, '_') != NULL)
    {
        *(strchr(fn->fachname, '_')) = ' ';
    }

    return 1;
}

fach_note* einfuegen(fach_note* head, fach_note* element, fach_note** removed)
{
    fach_note *e;
    *removed = NULL;

    if (head == NULL)
    {
        return element;
    }

    /* An Listenanfang einfuegen */
    head->prev = element;
    element->next = head;
    e = element;

    /* Pruefen ob bereits vorhanden (Namen) */
    while(e->next != NULL)
    {
        e = e->next;
        if (strcmp(element->fachname, e->fachname) == 0)
        {
            *removed = e;
            e->prev->next = e->next;
            e->prev = NULL;
            if (e->next != NULL)
            {
                e->next->prev = e->prev;
            }
            else
            {
                e->next = NULL;
            }
            break;
        }
    }

    return element;
}

fach_note* entfernen(fach_note* head, fach_note** removed)
{
    *removed = head;

    head = head->next;

    if(head != NULL)
    {
        head->prev = NULL;
    }

    return head;
}

void schleife(fach_note *head, void (*func)(fach_note const *))
{
    fach_note* element = head;
    while(element != NULL)
    {
        func(element);
        element = element->next;
    }
}

