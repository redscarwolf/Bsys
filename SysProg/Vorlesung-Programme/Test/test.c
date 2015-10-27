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

int main(void)
{
    /*
    fach_note x;
    x.u.note = 4;
    printf("%d %p", x.u.note,(void*) &x.u.note);
    */
    
    fach_note *y =(fach_note*) malloc(sizeof (fach_note)); 
    
    y->u.note = 3;
    printf("%d %p\n", y->u.note,(void*) &y->u.status);
    printf("%d %p\n", y->u.note,(void*) &y);
    printf("%d %p\n", y->u.note,(void*) &y->u);
    
    return 0;
}

/* Funktionsimplementierungen */

