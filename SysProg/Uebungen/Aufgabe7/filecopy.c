/*
 * copy.c
 *
 * Kopiert eine Datei.
 * Verwendet elementare Ein-/Ausgabe nach POSIX-Standard.
 *
 * Author H.Drachenfels
 * Erstellt am: 6.6.2013
 */

#include <locale.h>
#include <stdio.h>  /* fprintf */
#include <string.h> /* strerror */
#include <stdlib.h> /* malloc */

#include <fcntl.h>    /* open, O_RDONLY, O_WRONLY, O_CREAT, O_EXCL */
#include <sys/stat.h> /* mode_t, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH */
#include <unistd.h>   /* read, write */
#include <errno.h>    /* errno */

int main(int argc, char *argv[])
{
    const mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH; /* rw-r--r-- */
    int in, out; /* Dateideskriptoren */
    ssize_t a;
    
    struct stat s;    /* Dateistatus */
    unsigned char* buf;  /* Zeiger auf Buffer */
    char* locale;

    errno = 0; /* kein Fehler | erstmal fehlerstatus auf 0 setzen*/
    locale = setlocale(LC_MESSAGES, "de_DE.UTF-8");
    if (locale == NULL)
    {
        fprintf(stderr,
                "Die Sprache wird nicht unterstuetzt. (errno %d: %s)\n", errno, strerror(errno));
    }

    if (argc != 3)
    {
        fprintf(stderr, "Aufruf: %s Quelle Ziel\n", argv[0]);
        return 1;
    }

    errno = 0; /* kein Fehler | erstmal fehlerstatus auf 0 setzen*/

    in = open(argv[1], O_RDONLY);
    if (in == -1)
    {
        fprintf(stderr,
                "Quelle %s kann nicht geoeffnet werden (errno %d: %s)\n",
                argv[1], errno, strerror(errno));
        return 1;
    }

    out = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, mode);
    if (out == -1)
    {
        fprintf(stderr,
                "Ziel %s kann nicht erzeugt werden (errno %d: %s)\n",
                argv[2], errno, strerror(errno));
        return 1;
    }

    /* Groessenbestimmung des in-Files */
    if (fstat(in,&s) == -1)
    {
        fprintf(stderr, "Fehler bei Groessenbestimmung von Eingangsdatei %s "
                    "(errno %d: %s)\n",
                    argv[1], errno, strerror(errno));
        return 1;
    }
    buf = (unsigned char*) malloc(s.st_size);
    if (buf == NULL) {
        fprintf(stderr,
                "Speicherzugrifsfehler (errno %d: %s)\n", errno, strerror(errno));
        return 1;
    }

    /* einlesen mit EINEM Befehl */
    if ((a = read(in, buf, s.st_size)) < 0)
    {
        fprintf(stderr,
                "Lesefehler (errno %d: %s)\n", errno, strerror(errno));
        return 1;
    }
    /* zu wenig daten uebergeben*/
    if (a - s.st_size < 0)
    {
         fprintf(stderr,"Nicht alle daten kopiert\n");
        return 1;   
    }
    /* ausgeben mit EINEM Befehl */
    if (write(out, buf, s.st_size) == -1){
        fprintf(stderr,
                    "Schreibfehler (errno %d: %s)\n", errno, strerror(errno));
        return 1;
    }

    close(out);
    close(in);

    return 0;
}

