/*
 * filesize.c
 *
 * mit POSIX-Standart
 * Programm das als Kommandozeilenargumente beliebig viele Dateinamen erwartet
 * und für jede der Dateien die Größe in Byte(Anzahl der Zeichen(chars))
 * auf die Standardausgabe schreibt.
 *
 * Author M. Kieser
 * Erstellt am: 25.6.2015
 */

#include <locale.h> /* setlocale */
#include <sys/stat.h>  /* struct stat, S_IFMT, S_IFDIR */
#include <errno.h>     /* errno */

#include <stdio.h>  /* fopen, fgetc, fclose, ferror, perror */
#include <string.h> /* strerror */

int main(int argc, char *argv[])
{
    struct stat s;    /* Dateistatus */

    int i;

    /* uebersetzt errno Befehle in Deutsch */
    setlocale(LC_ALL, "");

    /* Parameter uebergeben? */
    if (argc < 2)
    {
        fprintf(stderr, "Aufruf: %s Uebergebe mindestens "
            "eine Datei\n", argv[0]);
        return 1;
    }

    errno = 0; /* kein Fehler | erstmal fehlerstatus auf 0 setzen*/
    
    for (i = 1; i < argc; ++i)
    {
        if (stat(argv[i], &s) == -1)
        {
            fprintf(stderr, "%s existiert nicht (errno %d: %s)\n",
                    argv[i], errno, strerror(errno));
             continue;
        }

        /* liest von Statusinfos die Variable st_size ist vom typ off_t welches ein signed Integer ist*/
        printf("Groesse von Datei %s: %d Byte\n", argv[i], (int) s.st_size);

    }

    return 0;
}

