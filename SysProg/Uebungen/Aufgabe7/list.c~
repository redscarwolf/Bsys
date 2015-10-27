/*
 * list.c
 *
 * Listet Verzeichnisse auf.
 * Verwendet Funktionen nach POSIX-Standard.
 *
 * Author H.Drachenfels
 * Erstellt am: 5.6.2014
 */

#define _XOPEN_SOURCE /* S_IFMT, S_IFDIR */

#include <stdio.h>  /* fprintf, printf */
#include <string.h> /* strerror */

#include <sys/stat.h>  /* struct stat, S_IFMT, S_IFDIR */
#include <dirent.h>    /* DIR, struct dirent, opendir, readdir */
#include <errno.h>     /* errno */

int main(int argc, char *argv[])
{
    struct stat s;    /* Dateistatus */
    DIR *d;           /* geoeffnetes Verzeichnis */
    struct dirent *e; /* gelesener Verziechniseintrag */
    int i;

    if (argc < 2)
    {
        fprintf(stderr, "Aufruf: %s Uebergebe mindestens "
            "einen Dateipfad eines Verzeichnisses\n", argv[0]);
        return 1;
    }

    for (i = 1; i < argc; ++i)
    {
        /* ist die Datei vorhanden? | und speichern der Statusinfos in s */
        if (stat(argv[i], &s) == -1)
        {
            fprintf(stderr, "%s existiert nicht (errno %d: %s)\n",
                    argv[i], errno, strerror(errno));
            continue;
        }

        /* liest von Statusinfos die Variable st_mode fuegt sie bitweise mit S_IFMT zusammen und vergleicht ob es keine DirectoryDatei ist. */
        if ((s.st_mode & S_IFMT) != S_IFDIR)
        {
            fprintf(stderr, "%s ist kein Verzeichnis\n", argv[i]);
            continue;
        }

        /* "oeffnet" Datei, indem es einen Zeiger d auf DateiAdresse erstellt */
        d = opendir(argv[i]);
        if (d == NULL)
        {
            fprintf(stderr, "%s kann nicht geoeffnet werden (errno %d: %s)\n",
                    argv[i], errno, strerror(errno));
            continue;
        }

        errno = 0;

        /* liefert einen Zeiger auf den naechsten ungelesenen Verzeichniseintrag */
        /* das heisst, dass ich einen Zeiger e auf eine struct dirent bekomme, welche einen char vom namen d_name hat */
        while ((e = readdir(d)) != NULL)
        {
            /* schreibe namen der unterdatei in Konsole */
            printf("%s/%s\n", argv[i], e->d_name);
        }

        if (errno)
        {
            fprintf(stderr, "Lesefehler in %s (errno %d: %s)\n",
                    argv[i], errno, strerror(errno));
        }

        closedir(d);
    }

    return 0;
}

