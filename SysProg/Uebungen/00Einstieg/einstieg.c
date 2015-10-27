 /*
 * einstieg.c
 *
 * Das erste C-Programm gibt einen Text aus.
 *
 * Autor(en): ...
 * Erstellt am: ...
 */

#include <stdio.h>
// fuer printf und scanf wichtig
#include <stdlib.h>
// fuer malloc wichtig

int main(void)
{
    int anzahl;
    //char vorname[8];
    char *vorname = (char*) malloc(8); // auf Heap statt Stack

    printf("Anzahl bisher geschriebener C-Programme eingeben: ");
    scanf("%d", &anzahl);

    printf("Vorname eingeben: ");
    scanf("%s", vorname);

    printf("%ss %d. C-Programm funktioniert!\n", vorname, anzahl + 1);

    free(vorname); // speicher wieder frei machen
    return 0;
}
