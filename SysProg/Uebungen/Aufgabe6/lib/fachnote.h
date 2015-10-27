/*
 * fachnote.h
 *
 * Liest Fachnamen mit Beurteilung ein und gibt dann einen Notenspiegel aus.
 *
 * Autor: Marcel
 * Erstellt am: 10.06.2015
 */
 
#ifndef FACHNOTE_H
#define FACHNOTE_H
 
/* Symbolische Variable fuer String fach*/
#define N 20 
 
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

#endif