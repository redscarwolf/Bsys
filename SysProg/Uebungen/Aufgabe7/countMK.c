/*
 * countMK.c
 *
 * ohne POSIX
 * Programm das als Kommandozeilenargumente beliebig viele Dateinamen erwartet
 * und für jede der Dateien die Größe in Byte(Anzahl der Zeichen(chars))
 * auf die Standardausgabe schreibt.
 *
 * Author M. Kieser
 * Erstellt am: 25.6.2015
 */

#include <stdio.h>  /* fopen, fgetc, fclose, ferror, perror */

int main(int argc, char *argv[])
{
    FILE *fp;
    int i;
    int n;

    for (i = 1; i < argc; ++i)
    {
        fp = fopen(argv[i], "r");
        if (fp == NULL)
        {
            perror(argv[i]); /*Fehler Ausgabe*/
            continue; /*setzt for schleife fort*/
        }

        n = 0;

        while (fgetc(fp) != EOF)
        {
            ++n;
        }

        if (ferror(fp))
        {
            perror(argv[i]); /*Fehler Ausgabe*/
            fclose(fp); /*geoeffnete Datei auch im Fehler Fall schliessen*/
            continue; /*setzt for schleife fort*/
        }

        printf("%s: %d Zeichen\n", argv[i], n);

        fclose(fp);
    }

    return 0;
}

