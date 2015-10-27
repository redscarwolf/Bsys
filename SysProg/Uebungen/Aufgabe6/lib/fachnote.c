/*
 * fachnote.c
 *
 * Liest Fachnamen mit Beurteilung ein und gibt dann einen Notenspiegel aus.
 *
 * Autor: Marcel
 * Erstellt am: 10.06.2015
 */
 
 /* #include-Anweisungen, symbolische Konstante, Typen ... */
#include <stdio.h> /* TODO: kann ich die auch ins fachnote.h schreiben?*/
#include <string.h>

/*fuegt struct fach_note und define N ein, Prototyp von einlesen und ausgeben*/
#include "fachnote.h"

/*Funktionsimplementierung*/
 
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
